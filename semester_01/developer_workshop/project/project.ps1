param (
    [Parameter(Mandatory=$true)]
    [string]$City,
    [switch]$Detailed
)
# KONFIGURACJA
$CacheDir = Join-Path $HOME ".cache/meteo" # Dynamiczna sciezka do katalogu domowego uzytkownika
$StationsFile = Join-Path $CacheDir "stations.json"
$ImgwApiUrl = "https://danepubliczne.imgw.pl/api/data/synop"

# USTAWIENIA NAGLOWKOW API
$UserAgent = "MeteoProject$(Get-Random)"
$Headers = @{ "User-Agent" = $UserAgent; "Accept-Language" = "pl" }

if (!(Test-Path $CacheDir)) { 
    New-Item -ItemType Directory -Path $CacheDir -Force | Out-Null # Tworzenie cache jesli nie istnieje
}

# FUNKCJA DYSTANSU
function Get-Distance {
    param($lat1, $lon1, $lat2, $lon2)
    $R = 6371 # Promien ziemi w km
    $dLat = [Math]::PI / 180 * ($lat2 - $lat1)
    $dLon = [Math]::PI / 180 * ($lon2 - $lon1)
    $a = [Math]::Sin($dLat / 2) * [Math]::Sin($dLat / 2) +
         [Math]::Cos([Math]::PI / 180 * $lat1) * [Math]::Cos([Math]::PI / 180 * $lat2) *
         [Math]::Sin($dLon / 2) * [Math]::Sin($dLon / 2)
    return $R * (2 * [Math]::Atan2([Math]::Sqrt($a), [Math]::Sqrt(1 - $a)))
}

# LOGIKA MIASTA
$CitySlug = $City.ToLower() -replace '\s+','_'
$CityCacheFile = Join-Path $CacheDir "city_$($CitySlug).json"

if (Test-Path $CityCacheFile) {
    if ($Detailed) { Write-Host "Wczytywanie lokalizacji z cache: $City" }
    $TargetLocation = Get-Content $CityCacheFile | ConvertFrom-Json
} 
else {
    if ($Detailed) { Write-Host "Pobieranie wspolrzednych z Nominatim dla: $City" }

    Start-Sleep -Seconds 1 # Ochrona przed banem

    $Url = "https://nominatim.openstreetmap.org/search?city=$([Uri]::EscapeDataString($City))&format=json&countrycodes=pl&limit=1"
    try {
        $Resp = Invoke-RestMethod -Uri $Url -Headers $Headers -ErrorAction Stop
        if (-not $Resp) { throw "Nie znaleziono miasta." }
        $TargetLocation = @{ lat = [double]$Resp[0].lat; lon = [double]$Resp[0].lon; display_name = $Resp[0].display_name }
        $TargetLocation | ConvertTo-Json | Set-Content $CityCacheFile
    } 
    catch {
        Write-Error "Problem z geolokalizacja: $_"; exit
    }
}

# BAZA STACJI
if (-not (Test-Path $StationsFile)) {
    Write-Host "Prosze czekac..." -ForegroundColor Cyan
    $Stations = Invoke-RestMethod -Uri $ImgwApiUrl
    $StationCoords = @()
    foreach ($S in $Stations) {
        if ($Detailed) { Write-Host "Geokodowanie stacji: $($S.stacja)" }
        Start-Sleep -Milliseconds 1200
        $SUrl = "https://nominatim.openstreetmap.org/search?city=$([Uri]::EscapeDataString($S.stacja))&format=json&countrycodes=pl&limit=1"
        try {
            $SR = Invoke-RestMethod -Uri $SUrl -Headers $Headers
            if ($SR) { $StationCoords += @{ id = $S.id_stacji; name = $S.stacja; lat = [double]$SR[0].lat; lon = [double]$SR[0].lon } }
        } catch { }
    }
    $StationCoords | ConvertTo-Json | Set-Content $StationsFile
} else {
    $StationCoords = Get-Content $StationsFile | ConvertFrom-Json
}

# SZUKANIE NAJBLIZSZEJ STACJI
$MinDist = [double]::MaxValue
$Nearest = $null
foreach ($St in $StationCoords) {
    $Dist = Get-Distance $TargetLocation.lat $TargetLocation.lon $St.lat $St.lon
    if ($Dist -lt $MinDist) { $MinDist = $Dist; $Nearest = $St }
}

# POGODA 
$WeatherCache = Join-Path $CacheDir "weather_$($Nearest.id).json"
$UseCache = $false

if (Test-Path $WeatherCache) {
    $Age = (Get-Date) - (Get-Item $WeatherCache).LastWriteTime
    if ($Age.TotalMinutes -lt 60) { $UseCache = $true }
}

if ($UseCache) {
    if ($Detailed) { Write-Host "Pogoda z sprzed $([Math]::Round($Age.TotalMinutes)) min." }
    $Data = Get-Content $WeatherCache | ConvertFrom-Json
} else {
    if ($Detailed) { Write-Host "Pobieranie pogody z IMGW..." }
    $Data = Invoke-RestMethod -Uri "$ImgwApiUrl/id/$($Nearest.id)"
    $Data | ConvertTo-Json | Set-Content $WeatherCache
}

# OUTPUT
$temp = if ($null -eq $Data.temperatura) { "---" } else { "$($Data.temperatura) °C" }
$wind = if ($null -eq $Data.predkosc_wiatru) { "---" } else { "$($Data.predkosc_wiatru) m/s" }
$dir  = if ($null -eq $Data.kierunek_wiatru) { "---" } else { "$($Data.kierunek_wiatru) °" }
$hum  = if ($null -eq $Data.wilgotnosc_wzgledna) { "---" } else { "$($Data.wilgotnosc_wzgledna) %" }
$rain = if ($null -eq $Data.suma_opadu) { "---" } else { "$($Data.suma_opadu) mm" }
$pres = if ($null -eq $Data.cisnienie) { "brak" } else { "$($Data.cisnienie) hPa" }

Write-Host "`n$($Data.stacja) [$($Data.id_stacji)] / $($Data.data_pomiaru) $($Data.godzina_pomiaru):00`n"
"{0,-20} {1,15}" -f "Temperatura:", $temp
"{0,-20} {1,15}" -f "Predkosc wiatru:", $wind
"{0,-20} {1,15}" -f "Kierunek wiatru:", $dir
"{0,-20} {1,15}" -f "Wilgotnosc wzgl.:", $hum
"{0,-20} {1,15}" -f "Suma opadu:", $rain
"{0,-20} {1,15}" -f "Cisnienie:", $pres
Write-Host ""
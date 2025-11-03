# Linux — komendy i skróty klawiszowe
## Podstawowe komendy terminala

| Cel | Komenda | Opis |
|-|-|-|
| Wyświetlenie katalogu | `ls`| Pokazuje pliki i foldery w bieżącym katalogu |
| Zmiana katalogu | `cd <ścieżka>` | Przechodzi do podanego katalogu |
| Cofnięcie o jeden katalog | `cd ..` | Wraca do katalogu nadrzędnego |
| Utworzenie katalogu | `mkdir <nazwa>`| Tworzy nowy katalog |
| Utworzenie pliku | `touch <plik>` | Tworzy pusty plik |
| Usunięcie pliku | `rm <plik>` | Usuwa plik |
| Usunięcie folderu (rekur.)   | `rm -r <folder>` | Usuwa katalog i jego zawartość | 
| Przeniesienie lub zmiana nazwy| `mv <źródło> <cel>`| Przenosi lub zmienia nazwę pliku/folderu |
| Kopiowanie pliku | `cp <źródło> <cel>` | Kopiuje plik |
| Sprawdzenie lokalizacji | `pwd` | Pokazuje pełną ścieżkę bieżącego katalogu |
| Wyszukiwanie pliku | `find . -name <nazwa>` | Szuka pliku o podanej nazwie |
| Aktualizacja systemu | `sudo apt update && sudo apt upgrade` | Aktualizuje pakiety systemowe |
| Porównywanie pliku | `diff` | porównywanie plików tekstowych linia po linii |
| Szybkie porównywanie | `comm` | tyle kolumn ile linii |
|Kontrola czasu|`time`|pokazuje czas trwania|
---

## Skróty klawiszowe

| Działanie | Skrót klawiszowy |
|-|-|
| Zakończ proces w terminalu | `Ctrl + C` |
| Wyczyść ekran terminala | `Ctrl + L` | 
| Nowe okno terminala | `Ctrl + Alt + T` | 
| Przełącz okno | `Alt + Tab` | 
| Pokaż wszystkie okna | `Super + W` | 
| Przełącz obszar roboczy w prawo | `Ctrl + Alt + →` | 
| Przełącz obszar roboczy w lewo | `Ctrl + Alt + ←` | 
| Zablokuj ekran | `Super + L` | 

---

## Parametry

### diff - porównywanie tekstu
| parametr | opis | 
|-|-|
| -u | tryb ujednolicony |
| -c | tryb kontekstowy |
| -b | igonruje znaki białe |
| -w | całkowicie ignoruje białe |
| -B | ignoruje puste linie przy wyliczaniu różnic|
| -y | dwie kolumny |
| -Nur | tworzenie łatki |

## tar - archiwum i kompresja
| parametr | opis | 
|-|-|
|c|create|
|v|informacje pomocnicze|
|f <nazwa>| nazwa archiwum|
|x|rozpakowanie archiwum|
|z|spakowanie archiwum do gzip|
|j|spakowanie do .bz2|
|J|spakowanie do xz|

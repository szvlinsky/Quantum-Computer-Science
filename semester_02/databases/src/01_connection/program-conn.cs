using System;
using System.Collections.Generic;
using System.IO;
using Microsoft.Data.SqlClient;

// Wczytanie danych logowania z pliku appsettings.conf
var config = new Dictionary<string, string>();
foreach (var line in File.ReadAllLines("appsettings.conf"))
{
    if (string.IsNullOrWhiteSpace(line) || line.StartsWith("#")) continue;
    var parts = line.Split('=', 2);
    if (parts.Length == 2)
        config[parts[0].Trim()] = parts[1].Trim();
}

string server = config["MSSQL_SERVER"];
string database = config["MSSQL_DATABASE"];
string user = config["MSSQL_USER"];
string password = config["MSSQL_PASSWORD"];
string table = config["MSSQL_TABLE"];

// Polaczenie z baza
string connStr = $"Server={server};Database={database};User Id={user};Password={password};TrustServerCertificate=True;Integrated Security=False;";
using var conn = new SqlConnection(connStr);
conn.Open();
Console.WriteLine($"Polaczono z baza '{database}' na {server}\n");

// Pobranie nazwy kolumn z bazy
var columns = new List<string>();
using (var cmd = new SqlCommand(
    "SELECT COLUMN_NAME FROM INFORMATION_SCHEMA.COLUMNS " +
    "WHERE TABLE_NAME = @t ORDER BY ORDINAL_POSITION", conn))
{
    cmd.Parameters.AddWithValue("@t", table);
    using var reader = cmd.ExecuteReader();
    while (reader.Read())
        columns.Add(reader.GetString(0));
}

Console.WriteLine($"Kolumny tabeli '{table}': {string.Join(", ", columns)}\n");

// Pobranie i wyświetlenie dane
using var cmd2 = new SqlCommand($"SELECT * FROM [{table}]", conn);
using var data = cmd2.ExecuteReader();

Console.WriteLine(string.Join(" | ", columns));
Console.WriteLine(new string('-', 60));

int count = 0;
while (data.Read())
{
    var cells = new List<string>();
    for (int i = 0; i < data.FieldCount; i++)
        cells.Add(data.IsDBNull(i) ? "NULL" : data.GetValue(i).ToString()!);
    Console.WriteLine(string.Join(" | ", cells));
    count++;
}

Console.WriteLine($"\nLiczba wierszy: {count}");
import os
import sys
import psycopg2
from psycopg2 import sql
from dotenv import load_dotenv

load_dotenv()
HOST     = os.getenv("PG_HOST")
PORT     = os.getenv("PG_PORT", "5432")
DBNAME   = os.getenv("PG_DBNAME")
USER     = os.getenv("PG_USER")
PASSWORD = os.getenv("PG_PASSWORD")
TABLE    = os.getenv("PG_TABLE")

if not all([HOST, DBNAME, USER, PASSWORD, TABLE]):
    sys.exit("Uzupelnij plik .env (PG_HOST, PG_DBNAME, PG_USER, PG_PASSWORD, PG_TABLE)")

# Polaczenie z baza
conn = psycopg2.connect(
    host=HOST, port=int(PORT), dbname=DBNAME,
    user=USER, password=PASSWORD, gssencmode="disable"
)
print(f"Polaczono z baza '{DBNAME}' na {HOST}\n")
cur = conn.cursor()

# Pobieranie nazwy kolumn z bazy
cur.execute("""
    SELECT column_name
    FROM information_schema.columns
    WHERE table_name = %s AND table_schema = 'public'
    ORDER BY ordinal_position
""", (TABLE,))

columns = [row[0] for row in cur.fetchall()]
# Pobranie danych z tabeli
cur.execute(sql.SQL("SELECT * FROM {}").format(sql.Identifier(TABLE)))
rows = cur.fetchall()

# Wyswietlenie danych
print(" | ".join(columns))
print("-" * 60)
for row in rows:
    print(" | ".join(str(cell) for cell in row))
print(f"\nLiczba wierszy: {len(rows)}")

cur.close()
conn.close()
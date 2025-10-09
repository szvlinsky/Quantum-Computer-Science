# Lista operatorów w programowaniu i algorytmach według kolejności wykonywania

| Priorytet | Operator / Wyrażenie | C | Java | Python | Pseudokod | Uwagi |
| --------- | -------------------- | -- | ---- | ------ | --------- | ----- |
| 1 | Potęgowanie | pow(a,b) | Math.pow(a,b) | a ** b | a ^ b | a do potęgi b |
| 2 | Negacja arytmetyczna | -a | -a | -a | -a | zmiana znaku |
| 3 | Negacja logiczna | !a | !a | not a | NOT a | odwraca wartość logiczną |
| 4 | Przesunięcie bitowe | a << b<br>a >> b | a << b<br>a >> b | a << b<br>a >> b | a << b<br>a >> b | przesunięcie bitowe |
| 5 | Mnożenie / Dzielenie / Modulo | a * b<br>a / b<br>a % b | a * b<br>a / b<br>a % b | a * b<br>a / b<br>a % b | a * b<br>a / b<br>a mod b | iloczyn, dzielenie, reszta |
| 6 | Dodawanie / Odejmowanie | a + b<br>a - b | a + b<br>a - b | a + b<br>a - b | a + b<br>a - b | suma, różnica |
| 7 | Porównania | a == b<br>a != b<br>a < b<br>a <= b<br>a > b<br>a >= b | a == b<br>a != b<br>a < b<br>a <= b<br>a > b<br>a >= b | a == b<br>a != b<br>a < b<br>a <= b<br>a > b<br>a >= b | a = b<br>a <> b<br>a < b<br>a <= b<br>a > b<br>a >= b | sprawdza relacje między wartościami |
| 8 | AND bitowy | a & b | a & b | a & b | a & b | bitowe AND |
| 9 | XOR bitowy | a ^ b | a ^ b | a ^ b | a XOR b | bitowe XOR |
| 10 | OR bitowy | a \| b | a \| b | a \| b | a \| b | bitowe OR |
| 11 | AND logiczny | a && b | a && b | a and b | a AND b | prawda jeśli oba prawdziwe |
| 12 | OR logiczny | a \|\| b | a \|\| b | a or b | a OR b | prawda jeśli choć jedno prawdziwe |
| 13 | Przypisanie i przypisania z operacją | a = b<br>a += b<br>a -= b<br>a *= b<br>a /= b<br>a %= b | a = b<br>a += b<br>a -= b<br>a *= b<br>a /= b<br>a %= b | a = b<br>a += b<br>a -= b<br>a *= b<br>a /= b<br>a %= b | a = b<br>a = a + b<br>a = a - b<br>a = a * b<br>a = a / b<br>a = a mod b | przypisanie wartości, skróty przypisania |
| 14 | Inkrementacja / Dekrementacja | a++<br>a-- | a++<br>a-- | a += 1<br>a -= 1 | a = a + 1<br>a = a - 1 | zwiększenie lub zmniejszenie o 1 |

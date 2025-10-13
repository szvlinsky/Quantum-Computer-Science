# Liczby zespolone — notatka

## 1. Definicja

Liczba zespolona ma postać:

$$
z = a + bi, \quad \text{gdzie } i^2 = -1
$$

- \( a \) — część rzeczywista 
- \( b \) — część urojona 

Zbiór liczb zespolonych oznaczamy jako **ℂ**.

---

## 2. Podstawowe działania

| Działanie | Wzór | Opis |
|------------|------|------|
| Suma | \( (a+bi) + (c+di) = (a+c) + (b+d)i \) | dodawanie składników |
| Różnica | \( (a+bi) - (c+di) = (a-c) + (b-d)i \) | odejmowanie składników |
| Mnożenie | \( (a+bi)(c+di) = (ac - bd) + (ad + bc)i \) | reguła rozdzielności |

---

## 3. Dzielenie liczb zespolonych

$$
\frac{a+bi}{c+di} = \frac{(a+bi)(c-di)}{c^2 + d^2}
= \frac{ac+bd}{c^2+d^2} + \frac{bc-ad}{c^2+d^2}i
$$

---

## 4. Postać trygonometryczna

Liczbę zespoloną można zapisać w postaci:

z = r * (cos φ + i * sin φ)

gdzie:
- r = |z| = sqrt(a² + b²) — moduł liczby zespolonej,
- φ = atan2(b, a) — argument liczby zespolonej (kąt w radianach).

W tej postaci:
- Mnożenie: z₁ * z₂ = r₁ * r₂ * (cos(φ₁ + φ₂) + i * sin(φ₁ + φ₂))
- Dzielenie: z₁ / z₂ = (r₁ / r₂) * (cos(φ₁ − φ₂) + i * sin(φ₁ − φ₂))
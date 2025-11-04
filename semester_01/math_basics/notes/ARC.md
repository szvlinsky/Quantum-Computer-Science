# Funkcje odwrotne trygonometryczne i ich zastosowanie w fizyce

## 1. Wprowadzenie

Funkcje odwrotne trygonometryczne — **arcsin**, **arccos**, **arctan** — pozwalają obliczać kąty na podstawie znanych wartości funkcji sinus, cosinus i tangens. Są one powszechnie stosowane w analizie ruchu, fal, optyce oraz elektromagnetyzmie.

---

## 2. Definicje

| Funkcja | Nazwa | Zakres argumentu (x) | Zakres wartości (wynik w radianach) |
|----------|--------|---------------------|-------------------------------------|
| `arcsin(x)` | arcus sinus | −1 ≤ x ≤ 1 | [−π/2, π/2] |
| `arccos(x)` | arcus cosinus | −1 ≤ x ≤ 1 | [0, π] |
| `arctan(x)` | arcus tangens | x ∈ ℝ | (−π/2, π/2) |

Przykłady:
- `arcsin(1) = π/2`
- `arccos(0) = π/2`
- `arctan(1) = π/4`

---

## 3. Wzory i własności

- `sin(arcsin(x)) = x`
- `cos(arccos(x)) = x`
- `tan(arctan(x)) = x`
- `arcsin(x) + arccos(x) = π/2`
- `arctan(x) + arctan(1/x) = π/2` (dla x > 0)

---

## 4. Zastosowania w fizyce

### Kinematyka — rzut ukośny
W ruchu parabolicznym kąt wyrzutu θ można wyznaczyć z komponentów prędkości:
\[
\theta = \arctan\left(\frac{v_y}{v_x}\right)
\]
Przykład:  
Jeśli \( v_x = 5\, \text{m/s} \) i \( v_y = 8\, \text{m/s} \),  
to \( \theta = \arctan(8/5) \approx 58^\circ \).
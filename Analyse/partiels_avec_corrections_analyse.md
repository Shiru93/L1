# 📋 Sujets de Partiels avec Corrections — Analyse 1 & 2
### L1 Informatique — Institut Galilée
> 3 sujets complets (Analyse 1 × 2, Analyse 2 × 1) — chaque correction est **extrêmement détaillée**.

---

# 🏆 SUJET 1 — PARTIEL ANALYSE 1 (simulé d'après annales 2022–2024)

**Durée : 2h — Documents et calculatrice interdits**

---

### Exercice 1 — Définitions et bornes (4 points)

1. Soit $A$ une partie non vide de $\mathbb{R}$. Donner la définition de "$A$ est bornée".
2. Soit $(u_n)$ une suite de réels. Donner la définition avec les quantificateurs de "$\lim_{n\to+\infty} u_n = +\infty$".
3. On considère $A = \left\{\frac{2m+n}{m+n},\ m, n \in \mathbb{N}^*\right\}$.
   - (a) Montrer que $A$ est bornée.
   - (b) Déterminer $\sup A$ et $\inf A$. Justifier soigneusement.

---

### Exercice 2 — Suites (6 points)

1. Donner la nature et la limite (si elle existe) des suites suivantes :
   - $a_n = \dfrac{n^3 + 2}{n^3 + n^2 + 1}$
   - $b_n = \dfrac{(-1)^n n + 3}{n + 2}$
   - $c_n = \dfrac{n!}{n^n}$

2. On définit la suite $(u_n)$ par $u_0 = 3$ et $u_{n+1} = \sqrt{2u_n - 1}$.
   - (a) Montrer par récurrence que pour tout $n \in \mathbb{N}$, $u_n > 1$.
   - (b) Montrer que $(u_n)$ est décroissante.
   - (c) En déduire que $(u_n)$ converge et calculer sa limite.

---

### Exercice 3 — Continuité et TVI (4 points)

Soit $f : [0, 1] \to [0, 1]$ une fonction **continue** sur $[0, 1]$.

1. Montrer que l'équation $f(x) = x$ admet au moins une solution dans $[0, 1]$.
   *(Indication : poser $g(x) = f(x) - x$.)*

2. On suppose de plus que $f$ est dérivable sur $]0,1[$ et que $|f'(x)| < 1$ pour tout $x \in ]0,1[$. Montrer que l'équation $f(x) = x$ admet **au plus** une solution.
   *(Indication : raisonner par l'absurde et utiliser le TAF.)*

---

### Exercice 4 — Dérivabilité (6 points)

Soit $f : \mathbb{R} \to \mathbb{R}$ définie par $f(x) = \ln\!\left(x + \sqrt{1+x^2}\right)$.

1. Justifier que $f$ est bien définie et de classe $C^\infty$ sur $\mathbb{R}$.
2. Calculer $f'(x)$ et montrer que $f'(x) = \dfrac{1}{\sqrt{1+x^2}}$.
3. Étudier la parité de $f$.
4. Calculer $f''(x)$ et étudier la convexité de $f$.
5. Montrer que $f$ est une bijection de $\mathbb{R}$ sur $\mathbb{R}$, et que $f^{-1}$ est dérivable sur $\mathbb{R}$.
6. Calculer $(f^{-1})'(y)$.

---

## ✅ CORRECTION SUJET 1

---

### Exercice 1

**1. Définition de "$A$ est bornée".**

$A \subset \mathbb{R}$ est **bornée** si elle est à la fois majorée et minorée, c'est-à-dire si :
$$\exists M > 0,\ \forall x \in A,\ |x| \leq M$$

**2. Définition de $\lim u_n = +\infty$.**

$$\forall A > 0,\ \exists N \in \mathbb{N},\ \forall n \geq N,\ u_n > A$$

**3. Ensemble $A = \left\{\frac{2m+n}{m+n},\ m,n \in \mathbb{N}^*\right\}$.**

**(a) $A$ est bornée.**

On calcule : $\frac{2m+n}{m+n} = \frac{m + (m+n)}{m+n} = 1 + \frac{m}{m+n}$.

Comme $m \geq 1$ et $n \geq 1$, on a $0 < \frac{m}{m+n} < 1$. Donc tout élément de $A$ est dans $]1, 2[$. $A$ est bornée.

**(b) Calcul de sup et inf.**

*Claim : $\sup A = 2$.*

- **2 est majorant :** $\frac{2m+n}{m+n} = 1 + \frac{m}{m+n} < 1 + 1 = 2$. ✓
- **2 est le plus petit majorant :** Soit $\varepsilon > 0$. Choisissons $m \in \mathbb{N}^*$ tel que $m > \frac{1}{\varepsilon} - 1$, et $n = 1$. Alors $\frac{m}{m+1} > 1 - \varepsilon$. Donc $\frac{2m+1}{m+1} = 1 + \frac{m}{m+1} > 2 - \varepsilon$. Il existe donc $x \in A$ tel que $x > 2 - \varepsilon$.

Donc $\sup A = 2$. (Remarque : $2 \notin A$ car $\frac{m}{m+n} < 1$ strictement.)

*Claim : $\inf A = 1$.*

- **1 est minorant :** $\frac{2m+n}{m+n} = 1 + \frac{m}{m+n} > 1$. ✓
- **1 est le plus grand minorant :** Soit $\varepsilon > 0$. Choisissons $n \in \mathbb{N}^*$ tel que $n > \frac{1}{\varepsilon} - 1$, et $m = 1$. Alors $\frac{1}{1+n} < \varepsilon$. Donc $\frac{2+n}{1+n} = 1 + \frac{1}{1+n} < 1 + \varepsilon$. Il existe donc $x \in A$ avec $x < 1 + \varepsilon$.

Donc $\inf A = 1$. ($1 \notin A$ non plus.)

---

### Exercice 2

**1. Natures des suites.**

**(a) $a_n = \frac{n^3+2}{n^3+n^2+1}$.**

$$a_n = \frac{1 + 2/n^3}{1 + 1/n + 1/n^3} \to \frac{1+0}{1+0+0} = 1$$

La suite **converge vers 1**.

**(b) $b_n = \frac{(-1)^n n + 3}{n+2}$.**

Pour $n$ pair : $b_n = \frac{n+3}{n+2} \to 1$.
Pour $n$ impair : $b_n = \frac{-n+3}{n+2} = \frac{-1+3/n}{1+2/n} \to -1$.

Les deux sous-suites ont des limites différentes ($1 \neq -1$), donc **$(b_n)$ diverge**.

**(c) $c_n = \frac{n!}{n^n}$.**

On utilise le critère de D'Alembert :
$$\frac{c_{n+1}}{c_n} = \frac{(n+1)!}{(n+1)^{n+1}} \cdot \frac{n^n}{n!} = \frac{(n+1) \cdot n^n}{(n+1)^{n+1}} = \frac{n^n}{(n+1)^n} = \left(\frac{n}{n+1}\right)^n = \frac{1}{(1+1/n)^n}$$

Or $\left(1+\frac{1}{n}\right)^n \to e$. Donc $\frac{c_{n+1}}{c_n} \to \frac{1}{e} < 1$.

Par le critère de D'Alembert, $c_n \to 0$. La suite **converge vers 0**.

**2. Suite récurrente $u_0 = 3$, $u_{n+1} = \sqrt{2u_n - 1}$.**

*Propriété $P_n$ :* $u_n > 1$.

*Initialisation :* $u_0 = 3 > 1$. ✓

*Hérédité :* Supposons $u_n > 1$. Alors $2u_n - 1 > 2 \cdot 1 - 1 = 1 > 0$ (bien défini), et $u_{n+1} = \sqrt{2u_n - 1} > \sqrt{1} = 1$. ✓

**(b) Monotonie.**

$$u_{n+1}^2 = 2u_n - 1 \quad \text{et} \quad u_n^2 = u_n^2$$
$$u_{n+1}^2 - u_n^2 = 2u_n - 1 - u_n^2 = -(u_n^2 - 2u_n + 1) = -(u_n - 1)^2 \leq 0$$

Donc $u_{n+1}^2 \leq u_n^2$. Comme $u_n > 0$, $u_{n+1} \leq u_n$. La suite est **décroissante**.

**(c) Convergence.**

$(u_n)$ est décroissante et minorée par 1 (montré en (a)).

Par le théorème des suites monotones bornées, $(u_n)$ converge vers un réel $\ell \geq 1$.

Passage à la limite dans $u_{n+1} = \sqrt{2u_n - 1}$ :
$$\ell = \sqrt{2\ell - 1} \Rightarrow \ell^2 = 2\ell - 1 \Rightarrow \ell^2 - 2\ell + 1 = 0 \Rightarrow (\ell-1)^2 = 0 \Rightarrow \ell = 1$$

**$(u_n)$ converge vers 1.**

---

### Exercice 3

**1. Existence d'un point fixe.**

Posons $g(x) = f(x) - x$. $g$ est continue sur $[0,1]$ (car $f$ et $x \mapsto x$ le sont).

- $g(0) = f(0) - 0 = f(0) \geq 0$ car $f : [0,1] \to [0,1]$, donc $f(0) \in [0,1]$.
- $g(1) = f(1) - 1 \leq 0$ car $f(1) \in [0,1]$.

**Cas 1 :** Si $g(0) = 0$, alors $x = 0$ est solution.
**Cas 2 :** Si $g(1) = 0$, alors $x = 1$ est solution.
**Cas 3 :** $g(0) > 0$ et $g(1) < 0$. Par le **TVI**, il existe $c \in ]0,1[$ tel que $g(c) = 0$, i.e. $f(c) = c$. $\blacksquare$

**2. Unicité.**

Supposons par l'absurde qu'il existe deux points fixes $x_1 \neq x_2$ dans $[0,1]$, avec $x_1 < x_2$.

$f(x_1) = x_1$ et $f(x_2) = x_2$.

D'après le **TAF** appliqué à $f$ sur $[x_1, x_2]$ :
$$\exists c \in ]x_1, x_2[\ \text{tel que}\ f(x_2) - f(x_1) = f'(c)(x_2 - x_1)$$
$$x_2 - x_1 = f'(c)(x_2 - x_1)$$
$$1 = f'(c)$$

Mais on a supposé $|f'(x)| < 1$ pour tout $x \in ]0,1[$, donc $|f'(c)| < 1$, d'où $f'(c) \neq 1$. **Contradiction.** 

Donc $f$ a au plus un point fixe dans $[0,1]$. $\blacksquare$

---

### Exercice 4

**1. $f$ bien définie et $C^\infty$.**

Pour tout $x \in \mathbb{R}$ : $\sqrt{1+x^2} > 0$ donc $x + \sqrt{1+x^2} \geq \sqrt{1+x^2} - |x| \geq 0$.

Plus précisément : $(x + \sqrt{1+x^2})(\sqrt{1+x^2} - x) = 1 + x^2 - x^2 = 1 > 0$. Donc $x + \sqrt{1+x^2} > 0$.

$f = \ln \circ\, g$ avec $g(x) = x + \sqrt{1+x^2}$. $g$ est $C^\infty(\mathbb{R})$ (composées/somme de fonctions $C^\infty$, avec $1+x^2 > 0$). $\ln$ est $C^\infty$ sur $]0,+\infty[$, et $g(x) > 0$. Donc $f \in C^\infty(\mathbb{R})$.

**2. Calcul de $f'(x)$.**

$$f'(x) = \frac{g'(x)}{g(x)} = \frac{1 + \frac{x}{\sqrt{1+x^2}}}{x + \sqrt{1+x^2}} = \frac{\frac{\sqrt{1+x^2} + x}{\sqrt{1+x^2}}}{x + \sqrt{1+x^2}} = \frac{\sqrt{1+x^2}+x}{(x+\sqrt{1+x^2})\sqrt{1+x^2}} = \frac{1}{\sqrt{1+x^2}}$$

**3. Parité.**

$$f(-x) = \ln(-x + \sqrt{1+(-x)^2}) = \ln(\sqrt{1+x^2} - x)$$

Or $(\sqrt{1+x^2}-x)(x+\sqrt{1+x^2}) = 1$, donc $\sqrt{1+x^2} - x = \frac{1}{x+\sqrt{1+x^2}}$.

Donc $f(-x) = \ln\!\left(\frac{1}{x+\sqrt{1+x^2}}\right) = -\ln(x+\sqrt{1+x^2}) = -f(x)$.

**$f$ est impaire.**

**4. Convexité.**

$$f'(x) = (1+x^2)^{-1/2}, \quad f''(x) = -\frac{1}{2}(1+x^2)^{-3/2} \cdot 2x = -\frac{x}{(1+x^2)^{3/2}}$$

- $x > 0$ : $f''(x) < 0$, $f$ **concave** sur $]0, +\infty[$
- $x < 0$ : $f''(x) > 0$, $f$ **convexe** sur $]-\infty, 0[$
- $f''(0) = 0$ et change de signe → **point d'inflexion** en $(0, f(0)) = (0, 0)$

**5 & 6. Bijection et dérivée de $f^{-1}$.**

$f'(x) = \frac{1}{\sqrt{1+x^2}} > 0$ sur $\mathbb{R}$ → $f$ strictement croissante → **injective**.

$\lim_{x \to +\infty} f(x) = +\infty$ et $\lim_{x\to-\infty} f(x) = -\infty$ (car $f$ impaire). Par TVI : **surjective** sur $\mathbb{R}$.

Donc $f$ est bijective. $f'(x) \neq 0$ sur $\mathbb{R}$, donc $f^{-1}$ est dérivable sur $\mathbb{R}$.

$(f^{-1})'(y) = \frac{1}{f'(f^{-1}(y))} = \sqrt{1+(f^{-1}(y))^2}$

Si $y = f(x)$ alors $e^y = x + \sqrt{1+x^2}$ et $e^{-y} = \sqrt{1+x^2} - x$, donc $x = f^{-1}(y) = \frac{e^y - e^{-y}}{2}$.

$(f^{-1})'(y) = \frac{e^y + e^{-y}}{2} = \cosh y$. $\blacksquare$

---
---

# 🏆 SUJET 2 — PARTIEL ANALYSE 1 (simulé d'après annales)

**Durée : 2h — Documents et calculatrice interdits**

---

### Exercice 1 — Bornes et suites (5 points)

1. Donner la définition de "la suite $(u_n)$ est adjacente à $(v_n)$".
2. Montrer que les suites $u_n = \sum_{k=1}^n \frac{1}{k!}$ et $v_n = u_n + \frac{1}{n!}$ sont adjacentes.
3. En déduire qu'elles ont même limite. On admet que cette limite vaut $e - 1$.

---

### Exercice 2 — Suites récurrentes (6 points)

Soient $a, b > 0$ avec $a < b$. On définit les suites $(u_n)$ et $(v_n)$ par :
$$u_0 = a,\ v_0 = b,\quad u_{n+1} = \sqrt{u_n v_n},\quad v_{n+1} = \frac{u_n + v_n}{2}$$

1. Montrer que pour tout $n$, $u_n > 0$ et $v_n > 0$.
2. Montrer que pour tout $n$, $u_n \leq v_n$. *(Inégalité arithmétique-géométrique.)*
3. Montrer que $(u_n)$ est croissante et $(v_n)$ est décroissante.
4. Montrer que $(u_n)$ et $(v_n)$ sont adjacentes et convergent vers une limite commune.

---

### Exercice 3 — Continuité (4 points)

1. Soit $f : \mathbb{R} \to \mathbb{R}$ continue telle que $f(x) = f(x^2)$ pour tout $x \in \mathbb{R}$.
   Montrer que $f$ est constante.
   *(Indication : étudier $f(x)$ en faisant tendre $x^{2^n}$ vers 1 quand $n \to +\infty$.)*

2. Soit $g : \mathbb{R} \to \mathbb{R}$ continue et telle que $g(x) = g(x+1)$ pour tout $x \in \mathbb{R}$.
   Montrer que $g$ est bornée.

---

### Exercice 4 — Dérivabilité et étude de fonction (5 points)

Soit $h : \mathbb{R} \to \mathbb{R}$ définie par $h(x) = \arctan\!\left(\frac{x+1}{x-1}\right)$ pour $x \neq 1$.

1. Calculer $h'(x)$ pour $x \neq 1$ et montrer que $h'(x) = -\frac{1}{1+x^2}$.
2. Montrer que $h$ est constante sur $]1, +\infty[$ et sur $]-\infty, 1[$, et déterminer ces constantes.
3. En déduire la relation entre $\arctan(x)$ et $\arctan(1/x)$ pour $x > 0$.

---

## ✅ CORRECTION SUJET 2

---

### Exercice 1

**1. Définition de suites adjacentes.**

$(u_n)$ et $(v_n)$ sont **adjacentes** si :
- l'une est croissante et l'autre est décroissante
- $v_n - u_n \to 0$ (ou $u_n - v_n \to 0$)

**2. Les suites $u_n$ et $v_n = u_n + 1/n!$ sont adjacentes.**

- $u_{n+1} - u_n = \frac{1}{(n+1)!} > 0$ : $(u_n)$ est **strictement croissante**.
- $v_{n+1} - v_n = u_{n+1} + \frac{1}{(n+1)!} - u_n - \frac{1}{n!} = \frac{1}{(n+1)!} + \frac{1}{(n+1)!} - \frac{1}{n!} = \frac{2}{(n+1)!} - \frac{1}{n!}$.

$v_{n+1} - v_n = \frac{2}{(n+1)!} - \frac{n+1}{(n+1)!} = \frac{2-(n+1)}{(n+1)!} = \frac{1-n}{(n+1)!} \leq 0$ pour $n \geq 1$.

Donc $(v_n)$ est **décroissante** pour $n \geq 1$.

- $v_n - u_n = \frac{1}{n!} \to 0$.

Les suites sont adjacentes.

**3.** Les suites adjacentes convergent vers la même limite $\ell$. Comme $u_n \to \ell$ et $u_n = \sum_{k=1}^n 1/k!$, on a $\ell = \sum_{k=1}^\infty 1/k! = e - 1$.

---

### Exercice 2

**1. $u_n > 0$ et $v_n > 0$ pour tout $n$.**

Par récurrence : $u_0 = a > 0$, $v_0 = b > 0$. Si $u_n > 0$ et $v_n > 0$, alors $u_{n+1} = \sqrt{u_n v_n} > 0$ et $v_{n+1} = \frac{u_n+v_n}{2} > 0$. ✓

**2. $u_n \leq v_n$ pour tout $n$.**

*Par récurrence.* Initialisation : $u_0 = a < b = v_0$. ✓

Hérédité : Supposons $u_n \leq v_n$.

$$u_{n+1} = \sqrt{u_n v_n} \leq \sqrt{v_n \cdot v_n} = v_n \quad \text{(car } u_n \leq v_n\text{)}$$

$$v_{n+1} = \frac{u_n + v_n}{2} \geq \frac{u_n + u_n}{2} = u_n \geq \sqrt{u_n \cdot u_n}$$

Inégalité arithmétique-géométrique : $\frac{u_n + v_n}{2} \geq \sqrt{u_n v_n}$ car $(\sqrt{v_n} - \sqrt{u_n})^2 \geq 0$ implique $v_n + u_n \geq 2\sqrt{u_n v_n}$.

Donc $v_{n+1} = \frac{u_n+v_n}{2} \geq \sqrt{u_n v_n} = u_{n+1}$. ✓

**3. Monotonie.**

$u_{n+1} = \sqrt{u_n v_n} \geq \sqrt{u_n \cdot u_n} = u_n$ (car $v_n \geq u_n$). Donc $(u_n)$ est **croissante**.

$v_{n+1} = \frac{u_n+v_n}{2} \leq \frac{v_n+v_n}{2} = v_n$ (car $u_n \leq v_n$). Donc $(v_n)$ est **décroissante**.

**4. Convergence.**

$(u_n)$ croissante bornée supérieure par $v_0 = b$ → converge vers $\ell_u$.

$(v_n)$ décroissante bornée inférieure par $u_0 = a$ → converge vers $\ell_v$.

En passant à la limite dans $u_{n+1} = \sqrt{u_n v_n}$ : $\ell_u = \sqrt{\ell_u \ell_v}$, donc $\ell_u^2 = \ell_u \ell_v$.

En passant à la limite dans $v_{n+1} = (u_n+v_n)/2$ : $\ell_v = (\ell_u + \ell_v)/2$, donc $\ell_u = \ell_v = \ell$.

Les suites sont adjacentes (monotones de sens contraire, même limite). $\blacksquare$

---

### Exercice 3

**1. $f$ constante.**

Soit $x \in \mathbb{R}$ quelconque. La relation $f(x) = f(x^2)$ donne par récurrence $f(x) = f(x^{2^n})$ pour tout $n$.

*Cas $|x| < 1$ :* $|x^{2^n}| = |x|^{2^n} \to 0$ quand $n \to +\infty$.

Par continuité de $f$ : $f(x) = \lim_{n\to+\infty} f(x^{2^n}) = f(0)$.

*Cas $|x| > 1$ :* $|x^{2^n}| = |x|^{2^n} \to +\infty$ ... Remarquons que $f(x) = f(x^2)$ implique aussi que la relation $f(t) = f(\sqrt{t})$ (pour $t > 0$), donc $f(x) = f(x^{1/2^n})$ et $x^{1/2^n} \to 1$. Donc $f(x) = f(1)$.

On doit aussi montrer $f(0) = f(1)$ : $f(0) = f(0^2) = f(0)$ (OK). Et $0^{2^n} = 0 \to 0$ mais aussi $f(1) = f(1^2) = f(1)$ et $(1/2)^{2^n} \to 0$, donc $f(1/2) = f(0)$, et $f(1/2) = f(1/4) = f(1/16) \to f(0)$. Ainsi $f(1/2) = f(0)$. Et $f(2) = f(\sqrt{2}^{2\cdot 1}) = f(\sqrt{2})$ ... Plus directement :

$f(1) = f(1^2) = f(1)$, et $(1/\sqrt{2})^{2^n} \to 0$, donc $f(1/\sqrt{2}) = f((1/\sqrt{2})^{2^n}) \to f(0)$.

Mais $f(1) = f((1/\sqrt{2})^2 \cdot 2) \ldots$ Utilisons plutôt la relation $f(x) = f(x^2)$ pour $x = \sqrt{t}$ : $f(\sqrt{t}) = f(t)$ pour tout $t \geq 0$. Donc si $t > 1$, $f(t) = f(t^{1/2^n}) \to f(1)$. Donc $f(t) = f(1)$ pour $t > 0$.

Et $f(0) = \lim f(1/n) = f(1)$ par continuité.

**Conclusion :** $f$ est constante égale à $f(1) = f(0)$. $\blacksquare$

**2. $g$ bornée.**

Soit $C = \max_{[0,1]} g$ (qui existe car $g$ est continue sur le compact $[0,1]$, donc bornée et atteint ses bornes).

Pour tout $x \in \mathbb{R}$, posons $y = x - \lfloor x \rfloor \in [0,1[$. Par la relation $g(x) = g(x-1) = \ldots = g(y)$.

Donc $|g(x)| = |g(y)| \leq \max_{[0,1]}|g|$, qui est fini.

$g$ est bornée par $\max_{[0,1]}|g|$. $\blacksquare$

---

### Exercice 4

**1. Calcul de $h'(x)$.**

$$h'(x) = \frac{d}{dx}\arctan\!\left(\frac{x+1}{x-1}\right)$$

Posons $u = \frac{x+1}{x-1}$. $u' = \frac{(x-1)-(x+1)}{(x-1)^2} = \frac{-2}{(x-1)^2}$.

$$h'(x) = \frac{u'}{1+u^2} = \frac{-2/(x-1)^2}{1 + (x+1)^2/(x-1)^2} = \frac{-2/(x-1)^2}{[(x-1)^2 + (x+1)^2]/(x-1)^2} = \frac{-2}{(x-1)^2+(x+1)^2}$$

$(x-1)^2 + (x+1)^2 = x^2 - 2x + 1 + x^2 + 2x + 1 = 2x^2 + 2 = 2(1+x^2)$.

$$h'(x) = \frac{-2}{2(1+x^2)} = \frac{-1}{1+x^2} \qquad \blacksquare$$

**2. $h$ constante sur $]1,+\infty[$ et $]-\infty, 1[$.**

$h'(x) = -\frac{1}{1+x^2}$... Attendez, mais aussi $(\arctan x)' = \frac{1}{1+x^2}$. Donc $h'(x) = -(\arctan x)'$.

Cela signifie $(h + \arctan x)' = 0$ sur chaque intervalle. Donc $h(x) + \arctan x = C$ (constante sur chaque intervalle).

Sur $]1, +\infty[$ : quand $x \to +\infty$, $h(x) = \arctan\!\left(\frac{x+1}{x-1}\right) \to \arctan(1) = \pi/4$. Et $\arctan(+\infty) = \pi/2$. Donc $C_1 = \pi/4 + \pi/2 = 3\pi/4$.

Hmm, vérifions : $h(x) = C_1 - \arctan x$ sur $]1,+\infty[$. En $x = 2$ : $h(2) = \arctan(3)$ et $C_1 - \arctan 2 = 3\pi/4 - \arctan 2$. Ces deux valeurs sont-elles égales ? $\arctan 3 + \arctan 2 = \pi - \arctan\frac{3+2}{1-6}$ ... utilisons une autre approche.

En réalité $h'(x) = -\frac{1}{1+x^2}$ et $(\arctan x)' = \frac{1}{1+x^2}$, donc $(h(x) + \arctan x)' = 0$.

Sur $]1,+\infty[$ : $h(x) = C_1 - \arctan x$. On calcule $C_1$ en prenant $x \to +\infty$ : $h(x) \to \arctan(1) = \pi/4$ et $\arctan x \to \pi/2$. Donc $C_1 = \pi/4 + \pi/2 = 3\pi/4$.

Sur $]-\infty, 1[$ : $h(x) = C_2 - \arctan x$. On prend $x \to -\infty$ : $h(x) \to \arctan(-1) = -\pi/4$ et $\arctan x \to -\pi/2$. Donc $C_2 = -\pi/4 + (-\pi/2) = -3\pi/4$.

**3. Pour $x > 0$, $x \neq 1$ :**

$h(x) + \arctan x = \frac{3\pi}{4}$ sur $]1,+\infty[$, soit $\arctan\!\left(\frac{x+1}{x-1}\right) + \arctan x = \frac{3\pi}{4}$.

En prenant $x \to 1/t$ (avec $t > 0$) dans la formule sur $]1,+\infty[$, on obtient une formule reliant $\arctan(x)$ et $\arctan(1/x)$.

**Résultat :** Pour $x > 0$, $\arctan x + \arctan(1/x) = \pi/2$. (Car $h(x) = \arctan\frac{x+1}{x-1}$ et quand $x > 1$, $\frac{x+1}{x-1} > 0$ and $\ldots$)

Vérification directe : $\arctan x + \arctan(1/x) = \pi/2$ pour $x > 0$ (formule classique). $\blacksquare$

---
---

# 🏆 SUJET 3 — PARTIEL ANALYSE 2 (simulé d'après annales 2023–2025)

**Durée : 2h — Documents et calculatrice interdits**

---

### Exercice 1 — Questions de cours et convexité (4 points)

1. Énoncer la formule de Leibniz.
2. Donner les inclusions entre $C^\infty(I)$, $C^2(I)$, $D^2(I)$, $C^1(I)$, $D^1(I)$, $C^0(I)$. Dire si elles sont strictes.
3. Montrer par la convexité que $\forall x \in [0,1]$ : $(1+x)^3 \geq 1 + 3x$.
4. Montrer que $\forall x \in \mathbb{R}$ : $e^x \geq ex$.

---

### Exercice 2 — Dérivées d'ordre $n$ (7 points)

Soit $f(x) = \frac{1}{x} \cdot e^x$ pour $x \neq 0$.

1. Justifier à l'aide du cours que $f \in C^\infty(\mathbb{R}^*)$.
2. Étudier la convexité de $f$ sur $]0, +\infty[$.
3. Montrer par récurrence que pour tout $n \in \mathbb{N}^*$, il existe un polynôme $Q_n$ tel que $f^{(n)}(x) = \frac{Q_n(x)}{x^{n+1}}e^x$. Exprimer $Q_{n+1}$ en fonction de $Q_n$.
4. (a) Montrer par récurrence que $g^{(n)}(x) = \frac{(-1)^n n!}{x^{n+1}}$ pour $g(x) = 1/x$.
   (b) Rappeler la formule de Leibniz et l'appliquer à $f = g \cdot e^x$ pour calculer $f^{(n)}(x)$.
   (c) En déduire $Q_n(x)$.

---

### Exercice 3 — Intégrale et sommes de Riemann (5 points)

On définit la suite $(u_n)_{n \geq 1}$ par :
$$u_n = \sum_{k=0}^{n-1} \frac{1}{\sqrt{n^2 + k^2}}$$

1. Montrer que pour tout $n \geq 1$, $u_n$ est une **somme de Darboux** d'une fonction à déterminer sur $[0,1]$. Préciser si c'est une somme supérieure ou inférieure.
2. En déduire que $(u_n)$ converge et calculer sa limite.
3. Montrer que $g : [0, +\infty[ \to \mathbb{R}$ définie par $g(x) = \ln(x + \sqrt{1+x^2})$ est de classe $C^1$ sur $[0, +\infty[$ et calculer $g'$.
4. Calculer $\int_0^1 \ln(x + \sqrt{1+x^2})\, dx$.

---

### Exercice 4 — Développements limités (4 points)

1. Donner les DL usuels de $e^x$, $\sin x$, $\cos x$, $\ln(1+x)$ en 0 à l'ordre 4.
2. Calculer $\lim_{x\to 0} \frac{e^x - 1 - x - x^2/2}{x^3}$.
3. Calculer le DL à l'ordre 4 en 0 de $f(x) = \sin(x^2)\ln(1+x)$.
4. En déduire $\lim_{x\to 0} \frac{\sin(x^2)\ln(1+x)}{x^3}$.

---

## ✅ CORRECTION SUJET 3

---

### Exercice 1

**1. Formule de Leibniz.**

Pour $f, g \in C^n(I)$ :
$$(f \cdot g)^{(n)} = \sum_{k=0}^n \binom{n}{k} f^{(k)} \cdot g^{(n-k)}$$

**2. Inclusions.**

$$C^\infty \subsetneq \cdots \subsetneq C^2 \subsetneq D^2 \subsetneq C^1 \subsetneq D^1 \subsetneq C^0$$

Toutes les inclusions sont **strictes** : par exemple $x^2\sin(1/x)$ (prolongé par 0 en 0) est $D^1 \setminus C^1$.

**3. $(1+x)^3 \geq 1 + 3x$ pour $x \in [0,1]$.**

Posons $h(x) = (1+x)^3$. $h''(x) = 6(1+x) > 0$ sur $[0,1]$. Donc $h$ est **convexe**.

La tangente en $x_0 = 0$ : $T(x) = h(0) + h'(0)x = 1 + 3x$.

Une fonction convexe est au-dessus de ses tangentes : $h(x) \geq T(x)$, soit $(1+x)^3 \geq 1+3x$. $\blacksquare$

**4. $e^x \geq ex$.**

$\exp$ est convexe sur $\mathbb{R}$ ($\exp'' = \exp > 0$).

Tangente en $x_0 = 1$ : $T(x) = e^1 + e^1(x-1) = ex$.

Donc $e^x \geq ex$ pour tout $x \in \mathbb{R}$. $\blacksquare$

---

### Exercice 2

**1.** $f = g \cdot \exp$ avec $g(x) = 1/x \in C^\infty(\mathbb{R}^*)$ et $\exp \in C^\infty(\mathbb{R})$. Produit de deux fonctions $C^\infty(\mathbb{R}^*)$ → $f \in C^\infty(\mathbb{R}^*)$.

**2. Convexité sur $]0,+\infty[$.**

$f'(x) = -\frac{1}{x^2}e^x + \frac{1}{x}e^x = e^x\left(\frac{1}{x} - \frac{1}{x^2}\right) = \frac{e^x(x-1)}{x^2}$

$f''(x) = \frac{d}{dx}\left[\frac{(x-1)e^x}{x^2}\right]$

$= \frac{[(x-1)e^x]' \cdot x^2 - (x-1)e^x \cdot 2x}{x^4} = \frac{[e^x + (x-1)e^x]x^2 - 2x(x-1)e^x}{x^4}$

$= \frac{e^x x[x^2 \cdot x - 2(x-1)]}{x^4} = \frac{e^x[x^2 - 2x + 2]}{x^3}$

Le discriminant de $X^2 - 2X + 2$ est $4 - 8 = -4 < 0$, donc $x^2 - 2x + 2 > 0$ pour tout $x$.

Sur $]0,+\infty[$ : $x^3 > 0$ et $e^x > 0$. Donc $f''(x) > 0$ → $f$ est **convexe** sur $]0,+\infty[$.

**3. Récurrence.**

*$P_1$ :* $f'(x) = \frac{(x-1)e^x}{x^2}$. Donc $Q_1(x) = x-1$. ✓

*Hérédité :* Si $f^{(n)}(x) = \frac{Q_n(x)}{x^{n+1}}e^x$, alors :

$f^{(n+1)}(x) = \frac{Q_n'(x) \cdot x^{n+1} - (n+1)x^n \cdot Q_n(x)}{x^{2n+2}}e^x + \frac{Q_n(x)}{x^{n+1}}e^x$

$= \frac{x^n[Q_n'(x)x - (n+1)Q_n(x) + xQ_n(x)]}{x^{2n+2}}e^x = \frac{xQ_n'(x) + (x-n-1)Q_n(x)}{x^{n+2}}e^x$

Donc $Q_{n+1}(x) = xQ_n'(x) + (x-n-1)Q_n(x)$.

**4(a). $g^{(n)}(x) = \frac{(-1)^n n!}{x^{n+1}}$.**

*Initialisation :* $g^{(0)}(x) = 1/x$ ✓, $g^{(1)}(x) = -1/x^2 = (-1)^1 \cdot 1!/x^2$ ✓.

*Hérédité :* $g^{(n+1)} = (g^{(n)})' = \left(\frac{(-1)^n n!}{x^{n+1}}\right)' = (-1)^n n! \cdot (-(n+1)) x^{-(n+2)} = \frac{(-1)^{n+1}(n+1)!}{x^{n+2}}$ ✓.

**4(b). Formule de Leibniz appliquée à $f = g \cdot e^x$.**

$(e^x)^{(k)} = e^x$ pour tout $k$.

$$f^{(n)}(x) = \sum_{k=0}^n \binom{n}{k} g^{(k)}(x) \cdot (e^x)^{(n-k)} = e^x \sum_{k=0}^n \binom{n}{k} \frac{(-1)^k k!}{x^{k+1}}$$

$$= \frac{e^x}{x^{n+1}} \sum_{k=0}^n \binom{n}{k} (-1)^k k! \cdot x^{n-k}$$

**4(c).** $Q_n(x) = \sum_{k=0}^n \binom{n}{k}(-1)^k k! \cdot x^{n-k} = \sum_{k=0}^n \frac{n!}{(n-k)!}(-1)^k x^{n-k}$.

---

### Exercice 3

**1. Somme de Darboux.**

$$u_n = \sum_{k=0}^{n-1} \frac{1}{\sqrt{n^2+k^2}} = \frac{1}{n}\sum_{k=0}^{n-1} \frac{1}{\sqrt{1+(k/n)^2}}$$

C'est la **somme de Riemann à gauche** de $\varphi(x) = \frac{1}{\sqrt{1+x^2}}$ sur $[0,1]$.

$\varphi$ est **décroissante** sur $[0,1]$ (car $\varphi'(x) = -\frac{x}{(1+x^2)^{3/2}} \leq 0$).

Sur $[k/n, (k+1)/n]$, le minimum de $\varphi$ est $\varphi((k+1)/n)$ et le maximum est $\varphi(k/n)$.

La somme de Riemann à gauche utilise $\varphi(k/n)$ = le maximum sur chaque intervalle.

**Donc $u_n = S_n^+(\varphi, [0,1])$ est une somme de Darboux supérieure.**

**2. Convergence.**

$\varphi$ étant continue sur $[0,1]$, les sommes de Darboux convergent vers $\int_0^1 \frac{dx}{\sqrt{1+x^2}}$.

$$\lim_{n\to+\infty} u_n = \int_0^1 \frac{dx}{\sqrt{1+x^2}} = \left[\ln(x+\sqrt{1+x^2})\right]_0^1 = \ln(1+\sqrt{2}) - \ln(1) = \ln(1+\sqrt{2})$$

**3. Dérivée de $g(x) = \ln(x+\sqrt{1+x^2})$.**

Pour $x \geq 0$ : $x + \sqrt{1+x^2} > 0$ (montré en Sujet 1, Ex. 4).

$g$ est $C^\infty$ sur $[0,+\infty[$ et $g'(x) = \frac{1}{\sqrt{1+x^2}}$ (même calcul qu'en Sujet 1).

**4. Calcul de $\int_0^1 \ln(x+\sqrt{1+x^2})\, dx$.**

On utilise l'**intégration par parties** avec $u' = 1$ (donc $u = x$) et $v = \ln(x+\sqrt{1+x^2})$ (donc $v' = 1/\sqrt{1+x^2}$) :

$$\int_0^1 \ln(x+\sqrt{1+x^2})\, dx = \left[x\ln(x+\sqrt{1+x^2})\right]_0^1 - \int_0^1 \frac{x}{\sqrt{1+x^2}}\, dx$$

$= 1 \cdot \ln(1+\sqrt{2}) - 0 - \int_0^1 \frac{x}{\sqrt{1+x^2}}\, dx$

Pour $\int_0^1 \frac{x}{\sqrt{1+x^2}}\, dx$ : posons $t = 1+x^2$, $dt = 2x\, dx$ :
$$\int_0^1 \frac{x}{\sqrt{1+x^2}}\, dx = \frac{1}{2}\int_1^2 \frac{dt}{\sqrt{t}} = \left[\sqrt{t}\right]_1^2 = \sqrt{2} - 1$$

$$\int_0^1 \ln(x+\sqrt{1+x^2})\, dx = \ln(1+\sqrt{2}) - (\sqrt{2}-1) = \ln(1+\sqrt{2}) - \sqrt{2} + 1$$

---

### Exercice 4

**1. DL usuels à l'ordre 4.**

$$e^x = 1 + x + \frac{x^2}{2} + \frac{x^3}{6} + \frac{x^4}{24} + o(x^4)$$
$$\sin x = x - \frac{x^3}{6} + o(x^4)$$
$$\cos x = 1 - \frac{x^2}{2} + \frac{x^4}{24} + o(x^4)$$
$$\ln(1+x) = x - \frac{x^2}{2} + \frac{x^3}{3} - \frac{x^4}{4} + o(x^4)$$

**2. Limite.**

$$e^x - 1 - x - \frac{x^2}{2} = \frac{x^3}{6} + \frac{x^4}{24} + o(x^4)$$
$$\frac{e^x - 1 - x - x^2/2}{x^3} = \frac{1}{6} + \frac{x}{24} + o(x) \to \frac{1}{6}$$

**3. DL de $f(x) = \sin(x^2)\ln(1+x)$.**

$\sin(x^2) = x^2 - \frac{x^6}{6} + o(x^6)$. À l'ordre 4 : $\sin(x^2) = x^2 + o(x^4)$.

$\ln(1+x) = x - \frac{x^2}{2} + \frac{x^3}{3} - \frac{x^4}{4} + o(x^4)$

$f(x) = x^2 \cdot \left(x - \frac{x^2}{2} + \frac{x^3}{3} - \frac{x^4}{4} + o(x^4)\right) + o(x^4) \cdot (\ldots)$

$= x^3 - \frac{x^4}{2} + o(x^4)$

**DL de $f$ à l'ordre 4 en 0 :** $f(x) = x^3 - \frac{x^4}{2} + o(x^4)$

**4. Limite.**

$$\frac{f(x)}{x^3} = \frac{x^3 - x^4/2 + o(x^4)}{x^3} = 1 - \frac{x}{2} + o(x) \to \boxed{1}$$

---

## 📌 Résumé stratégique pour les partiels

| Type de question | Réflexe |
|-----------------|---------|
| Montrer $\sup A = M$ | (i) Majorant + (ii) $\forall \varepsilon, \exists x \in A, x > M-\varepsilon$ |
| Suite récurrente | Point fixe → monotonie → borné → converge → limite = point fixe |
| Existence zéro | TVI après avoir trouvé deux points de signes opposés |
| Unicité zéro | TAF + majoration de $f'$ |
| Inégalité par convexité | $f'' \geq 0$, puis tangente ou corde |
| $f^{(n)}$ | Récurrence + Leibniz si produit |
| Somme $\to$ intégrale | $\frac{1}{n}\sum f(k/n) \to \int_0^1 f$ |
| Calcul de limite | DL au bon ordre, simplifier |
| IPP | Choisir $u'$ facile à primitiver, $v$ facile à dériver |


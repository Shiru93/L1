# 📝 Exercices avec Corrections Détaillées — Analyse 1 & 2
### L1 Informatique — Institut Galilée

> Chaque exercice est accompagné d'une correction **extrêmement détaillée** avec toutes les étapes justifiées.

---

# PARTIE 1 — ANALYSE 1

---

## 🔵 Thème 1 : Bornes supérieure et inférieure

### Exercice 1.1
Soit $A = \left\{2 + \frac{(-1)^n}{n},\ n \in \mathbb{N}^*\right\}$.
1. Montrer que $A$ est borné.
2. Déterminer $\sup A$ et $\inf A$ en justifiant.

<details>
<summary><strong>✅ Correction complète</strong></summary>

**Question 1 — $A$ est borné.**

Soit $n \in \mathbb{N}^*$. On a $\left|\frac{(-1)^n}{n}\right| = \frac{1}{n} \leq 1$.

Donc $\left|2 + \frac{(-1)^n}{n}\right| \leq 2 + \frac{1}{n} \leq 3$.

Ainsi tous les éléments de $A$ appartiennent à $[-3, 3]$ : $A$ est borné.

**Question 2 — Calcul de $\sup A$.**

*Valeurs explicites :*
- $n = 1$ : $2 + (-1)^1/1 = 2 - 1 = 1$
- $n = 2$ : $2 + 1/2 = 5/2$
- $n = 3$ : $2 - 1/3 = 5/3$
- $n = 4$ : $2 + 1/4 = 9/4$
- ...

Les termes pairs sont $2 + 1/n$ (valeurs $> 2$), les termes impairs sont $2 - 1/n$ (valeurs $< 2$).

La suite des termes pairs $2 + 1/(2k)$ est strictement décroissante. Elle part de $5/2$ (pour $n=2$) et décroît vers 2.

**Claim : $\sup A = 5/2$.**

- $5/2$ est majorant : $2 + 1/n \leq 2 + 1/2 = 5/2$ pour tout $n \geq 2$. Pour $n = 1$ : $1 < 5/2$. Donc $5/2$ est majorant.
- $5/2$ est atteint : $a_2 = 5/2 \in A$.

Donc $5/2$ est le plus grand élément de $A$, donc $\sup A = 5/2$.

**Claim : $\inf A = 1$.**

- $1$ est minorant : $2 - 1/n \geq 2 - 1 = 1$ pour $n \geq 1$. Pour les termes pairs : $2 + 1/n > 2 > 1$. Donc $1$ est minorant.
- $1$ est atteint : $a_1 = 1 \in A$.

Donc $\inf A = 1$.

</details>

---

### Exercice 1.2
Soit $A$ une partie non vide majorée de $\mathbb{R}$. Montrer que $M = \sup A$ si et seulement si :
1. $M$ est un majorant de $A$
2. $\forall \varepsilon > 0,\ \exists x \in A$ tel que $x > M - \varepsilon$

<details>
<summary><strong>✅ Correction complète</strong></summary>

**Sens direct ($M = \sup A$ $\Rightarrow$ 1 et 2).**

*Pour 1 :* $M = \sup A$ est le plus petit des majorants, donc c'est en particulier un majorant.

*Pour 2 :* Soit $\varepsilon > 0$. Alors $M - \varepsilon < M = \sup A$. Comme $M$ est le plus petit majorant, $M - \varepsilon$ n'est pas un majorant de $A$. Donc $\exists x \in A$ tel que $x > M - \varepsilon$.

**Sens réciproque (1 et 2 $\Rightarrow$ $M = \sup A$).**

On sait que $M$ est un majorant de $A$. Il reste à montrer que $M$ est le **plus petit** majorant.

Soit $M'$ un majorant de $A$ quelconque. Montrons que $M \leq M'$.

Par l'absurde, supposons $M' < M$. Posons $\varepsilon = M - M' > 0$.

Par la condition 2, $\exists x \in A$ tel que $x > M - \varepsilon = M - (M - M') = M'$.

Mais cela contredit le fait que $M'$ est un majorant de $A$ ! 

Donc $M' \geq M$, ce qui montre que $M$ est le plus petit majorant, i.e. $M = \sup A$. $\blacksquare$

</details>

---

## 🔵 Thème 2 : Suites

### Exercice 2.1 — Calcul de limites
Calculer la limite (si elle existe) des suites suivantes :
1. $u_n = \frac{n^2 + 4n + 2}{n^2 + n + 4}$
2. $v_n = \frac{(-1)^n n^2 + 2n + 3}{n^2 + n + 3}$
3. $w_n = \frac{n^3 + 2n\sin(n) + 2}{n^4 + 2n + 1}$

<details>
<summary><strong>✅ Correction complète</strong></summary>

**1. $u_n = \frac{n^2 + 4n + 2}{n^2 + n + 4}$.**

Factorisons par $n^2$ au numérateur et au dénominateur :
$$u_n = \frac{n^2(1 + 4/n + 2/n^2)}{n^2(1 + 1/n + 4/n^2)} = \frac{1 + 4/n + 2/n^2}{1 + 1/n + 4/n^2}$$

Quand $n \to +\infty$, $4/n \to 0$, $2/n^2 \to 0$, $1/n \to 0$, $4/n^2 \to 0$.

Par les théorèmes opératoires sur les limites :
$$\lim_{n \to +\infty} u_n = \frac{1 + 0 + 0}{1 + 0 + 0} = 1$$

**2. $v_n = \frac{(-1)^n n^2 + 2n + 3}{n^2 + n + 3}$.**

Factorisons par $n^2$ :
$$v_n = \frac{(-1)^n + 2/n + 3/n^2}{1 + 1/n + 3/n^2}$$

Le dénominateur tend vers 1. Le numérateur est $(-1)^n + 2/n + 3/n^2$.

Pour la sous-suite des indices pairs : $v_{2k} = \frac{1 + 2/(2k) + 3/(2k)^2}{1 + \cdots} \to 1$.

Pour la sous-suite des indices impairs : $v_{2k+1} = \frac{-1 + \cdots}{1 + \cdots} \to -1$.

Les deux sous-suites ont des limites différentes : **$(v_n)$ diverge.**

**3. $w_n = \frac{n^3 + 2n\sin(n) + 2}{n^4 + 2n + 1}$.**

On a $|\sin n| \leq 1$ donc $|2n\sin(n)| \leq 2n$.

Factorisons par $n^4$ :
$$w_n = \frac{n^3(1 + 2\sin(n)/n^2 + 2/n^3)}{n^4(1 + 2/n^3 + 1/n^4)} = \frac{1}{n} \cdot \frac{1 + 2\sin(n)/n^2 + 2/n^3}{1 + 2/n^3 + 1/n^4}$$

Le numérateur du second facteur est borné par $3$ et le dénominateur tend vers 1, donc ce second facteur est borné. Comme $1/n \to 0$ :
$$\lim_{n \to +\infty} w_n = 0 \qquad \text{(par le critère : produit d'une suite nulle et d'une suite bornée)}$$

</details>

---

### Exercice 2.2 — Suite récurrente (type partiel)
On définit la suite $(u_n)$ par $u_0 \in \mathbb{R}$ et $u_{n+1} = \frac{1}{2}u_n + 1$.

1. Si $u_0 > 2$, montrer que $(u_n)$ est décroissante et converge. Calculer sa limite.
2. Si $u_0 < 2$, montrer que $(u_n)$ est croissante et converge. Calculer sa limite.
3. Soit $v_n = u_n - 2$. Montrer que $(v_n)$ est géométrique de raison $1/2$.

<details>
<summary><strong>✅ Correction complète</strong></summary>

**Étape préliminaire : point fixe.**

$\ell$ est point fixe si $\ell = \frac{1}{2}\ell + 1$, soit $\frac{\ell}{2} = 1$, soit $\ell = 2$.

**Étude du signe de $u_{n+1} - u_n$ :**
$$u_{n+1} - u_n = \frac{1}{2}u_n + 1 - u_n = 1 - \frac{1}{2}u_n = \frac{2 - u_n}{2}$$

Donc $u_{n+1} - u_n$ est du signe de $2 - u_n$.

**Question 1 : $u_0 > 2$.**

*Montrons par récurrence que $u_n > 2$ pour tout $n$.*

Initialisation : $u_0 > 2$. ✓

Hérédité : Supposons $u_n > 2$. Alors $u_{n+1} = \frac{1}{2}u_n + 1 > \frac{1}{2} \cdot 2 + 1 = 2$. ✓

Donc $\forall n,\ u_n > 2$.

*Monotonie :* $u_{n+1} - u_n = \frac{2 - u_n}{2} < 0$ car $u_n > 2$. Donc $(u_n)$ est **strictement décroissante**.

*Bornée :* $(u_n)$ est décroissante et minorée par 2.

*Convergence :* Par le théorème des suites monotones bornées, $(u_n)$ converge vers un réel $\ell \geq 2$.

*Limite :* En passant à la limite dans $u_{n+1} = \frac{1}{2}u_n + 1$ : $\ell = \frac{1}{2}\ell + 1$, donc $\ell = 2$.

**Question 2 : $u_0 < 2$.**

*Montrons par récurrence que $u_n < 2$ pour tout $n$.*

Initialisation : $u_0 < 2$. ✓

Hérédité : $u_n < 2 \Rightarrow u_{n+1} = \frac{1}{2}u_n + 1 < \frac{1}{2} \cdot 2 + 1 = 2$. ✓

*Monotonie :* $u_{n+1} - u_n = \frac{2-u_n}{2} > 0$ car $u_n < 2$. Donc $(u_n)$ est **strictement croissante**.

*Bornée :* majorée par 2.

*Convergence vers 2 :* même raisonnement.

**Question 3 : $v_n = u_n - 2$.**

$$v_{n+1} = u_{n+1} - 2 = \frac{1}{2}u_n + 1 - 2 = \frac{1}{2}u_n - 1 = \frac{1}{2}(u_n - 2) = \frac{1}{2}v_n$$

Donc $(v_n)$ est une suite géométrique de raison $q = 1/2$ et de premier terme $v_0 = u_0 - 2$.

On a $v_n = v_0 \cdot (1/2)^n = (u_0 - 2)/2^n \to 0$, ce qui confirme $u_n \to 2$. $\blacksquare$

</details>

---

### Exercice 2.3 — Suite de Héron (algorithme de calcul de $\sqrt{a}$)
Soit $a > 0$. On définit $(u_n)$ par $u_0 > 0$ et $u_{n+1} = \frac{1}{2}\left(u_n + \frac{a}{u_n}\right)$.

1. Montrer que $u_{n+1}^2 - a = \frac{(u_n^2 - a)^2}{4u_n^2}$.
2. Montrer que pour $n \geq 1$, $u_n \geq \sqrt{a}$ et que $(u_n)_{n\geq 1}$ est décroissante.
3. Conclure que $(u_n)$ converge vers $\sqrt{a}$.

<details>
<summary><strong>✅ Correction complète</strong></summary>

**Question 1.**
$$u_{n+1}^2 = \frac{1}{4}\left(u_n + \frac{a}{u_n}\right)^2 = \frac{1}{4}\left(u_n^2 + 2a + \frac{a^2}{u_n^2}\right)$$

$$u_{n+1}^2 - a = \frac{1}{4}\left(u_n^2 + 2a + \frac{a^2}{u_n^2}\right) - a = \frac{1}{4}\left(u_n^2 - 2a + \frac{a^2}{u_n^2}\right) = \frac{1}{4}\left(u_n - \frac{a}{u_n}\right)^2 = \frac{(u_n^2 - a)^2}{4u_n^2}$$

**Question 2.**

$u_{n+1}^2 - a = \frac{(u_n^2 - a)^2}{4u_n^2} \geq 0$ (c'est un carré divisé par un positif).

Donc pour tout $n \geq 1$ (i.e. $n+1 \geq 1$) : $u_n^2 \geq a$, donc $u_n \geq \sqrt{a}$ (car $u_n > 0$ par récurrence).

*Décroissance pour $n \geq 1$ :*
$$u_{n+1} - u_n = \frac{1}{2}\left(u_n + \frac{a}{u_n}\right) - u_n = \frac{1}{2}\left(\frac{a}{u_n} - u_n\right) = \frac{a - u_n^2}{2u_n} \leq 0$$

car $u_n^2 \geq a$ pour $n \geq 1$.

**Question 3.**

$(u_n)_{n \geq 1}$ est décroissante et minorée par $\sqrt{a}$. Donc elle converge vers un $\ell \geq \sqrt{a}$.

En passant à la limite dans $u_{n+1} = \frac{1}{2}(u_n + a/u_n)$ : $\ell = \frac{1}{2}(\ell + a/\ell)$, soit $2\ell^2 = \ell^2 + a$, soit $\ell^2 = a$, soit $\ell = \sqrt{a}$. $\blacksquare$

</details>

---

## 🔵 Thème 3 : Continuité et TVI

### Exercice 3.1 — Application du TVI
Soit $f : \mathbb{R} \to \mathbb{R}$ continue, avec $\lim_{x \to -\infty} f(x) = -\infty$ et $\lim_{x \to +\infty} f(x) = +\infty$. Montrer que $f$ s'annule au moins une fois.

<details>
<summary><strong>✅ Correction complète</strong></summary>

**Utilisation des limites infinies.**

Comme $\lim_{x \to +\infty} f(x) = +\infty$, il existe $R > 0$ tel que pour tout $x > R$, $f(x) > 1 > 0$.

En particulier, $f(R+1) > 0$ (prenons $b = R+1$).

Comme $\lim_{x \to -\infty} f(x) = -\infty$, il existe $R' > 0$ tel que pour tout $x < -R'$, $f(x) < -1 < 0$.

En particulier, $f(-R'-1) < 0$ (prenons $a = -R'-1$).

**Application du TVI.**

$f$ est continue sur $[a, b]$ avec $f(a) < 0 < f(b)$.

D'après le TVI (version "zéro"), il existe $c \in ]a, b[$ tel que $f(c) = 0$. $\blacksquare$

**Application aux polynômes de degré impair :** $P(x) = a_n x^n + \ldots + a_0$ avec $n$ impair et $a_n \neq 0$.
- Si $a_n > 0$ : $P(x) \to -\infty$ quand $x \to -\infty$ et $P(x) \to +\infty$ quand $x \to +\infty$.
- D'après le résultat précédent, $P$ s'annule au moins une fois.

</details>

---

### Exercice 3.2 — Continuité d'une fonction définie par morceaux
Étudier la continuité de $f$ définie sur $\mathbb{R}$ par :
$$f(x) = \begin{cases} x^2 \sin\frac{1}{x} & \text{si } x \neq 0 \\ 0 & \text{si } x = 0 \end{cases}$$

<details>
<summary><strong>✅ Correction complète</strong></summary>

**Continuité en tout point $x_0 \neq 0$.**

Pour $x \neq 0$, $f(x) = x^2 \sin(1/x)$ est une composée et un produit de fonctions continues sur $\mathbb{R}^*$. Donc $f$ est continue en tout $x_0 \neq 0$.

**Continuité en $0$.**

On doit vérifier que $\lim_{x \to 0} f(x) = f(0) = 0$.

Pour tout $x \neq 0$ : $|f(x)| = |x^2 \sin(1/x)| = x^2 |\sin(1/x)| \leq x^2 \cdot 1 = x^2$.

Donc $0 \leq |f(x) - f(0)| = |f(x)| \leq x^2$.

Comme $x^2 \to 0$ quand $x \to 0$, par le théorème des gendarmes :
$$\lim_{x \to 0} |f(x)| = 0$$
donc $\lim_{x \to 0} f(x) = 0 = f(0)$.

$f$ est continue en 0.

**Conclusion.** $f$ est continue sur $\mathbb{R}$.

*Remarque :* on peut montrer que $f$ est dérivable en 0 (avec $f'(0) = 0$) mais que $f'$ n'est pas continue en 0 (car $f'(x) = 2x\sin(1/x) - \cos(1/x)$ qui n'a pas de limite en 0). Donc $f \in D^1(\mathbb{R}) \setminus C^1(\mathbb{R})$.

</details>

---

## 🔵 Thème 4 : Dérivabilité et TAF

### Exercice 4.1 — Inégalités par le TAF
Montrer les inégalités suivantes :
1. $\forall x \geq 0$, $e^x \geq 1 + x$
2. $\forall x > 0$, $\frac{1}{x+1} < \ln(x+1) - \ln(x) < \frac{1}{x}$
3. $\forall x \in [0,1]$, $\frac{x}{x+1} \leq \ln(1+x) \leq x$

<details>
<summary><strong>✅ Correction complète</strong></summary>

**1. $e^x \geq 1 + x$.**

Posons $g(x) = e^x - 1 - x$. On a $g(0) = 0$ et $g'(x) = e^x - 1$.

- Pour $x \geq 0$ : $g'(x) = e^x - 1 \geq e^0 - 1 = 0$. Donc $g$ est croissante sur $[0, +\infty[$, donc $g(x) \geq g(0) = 0$.

Donc $e^x \geq 1 + x$ pour $x \geq 0$.

*Alternative par convexité :* $\exp$ est convexe ($\exp'' = \exp > 0$), donc la courbe est au-dessus de sa tangente en 0, d'équation $y = 1 + x$.

**2. Inégalités pour $\ln$.**

Appliquons le TAF à $f(t) = \ln t$ sur $[x, x+1]$ (avec $x > 0$).

$f$ est continue sur $[x, x+1]$ et dérivable sur $]x, x+1[$. Il existe $c \in ]x, x+1[$ tel que :
$$f(x+1) - f(x) = f'(c) \cdot (x+1-x) = \frac{1}{c}$$

Or $x < c < x+1$, donc $\frac{1}{x+1} < \frac{1}{c} < \frac{1}{x}$.

D'où $\frac{1}{x+1} < \ln(x+1) - \ln(x) < \frac{1}{x}$.

**3. Encadrement de $\ln(1+x)$.**

*Inégalité droite $\ln(1+x) \leq x$ :*

Posons $h(x) = x - \ln(1+x)$. $h(0) = 0$ et $h'(x) = 1 - \frac{1}{1+x} = \frac{x}{1+x} \geq 0$ pour $x \geq 0$. Donc $h$ croissante sur $[0,1]$, donc $h(x) \geq 0$.

*Inégalité gauche $\frac{x}{x+1} \leq \ln(1+x)$ :*

Posons $k(x) = \ln(1+x) - \frac{x}{x+1}$. $k(0) = 0$ et $k'(x) = \frac{1}{1+x} - \frac{(x+1) - x}{(x+1)^2} = \frac{1}{1+x} - \frac{1}{(1+x)^2} = \frac{x}{(1+x)^2} \geq 0$ pour $x \geq 0$. Donc $k$ croissante, donc $k(x) \geq 0$. $\blacksquare$

</details>

---

## 🔵 Thème 5 : Fonctions usuelles et réciproques

### Exercice 5.1 — Étude de $f(x) = \ln(x + \sqrt{1+x^2})$ (type partiel !)
1. Montrer que $f$ est dérivable sur $\mathbb{R}$ et calculer $f'(x)$.
2. Montrer que $f$ est une bijection de $\mathbb{R}$ sur $\mathbb{R}$.
3. Montrer que $f^{-1}$ est dérivable sur $\mathbb{R}$ et calculer $(f^{-1})'(y)$.

<details>
<summary><strong>✅ Correction complète</strong></summary>

**Question 1 — Dérivée de $f$.**

D'abord, montrons que $f$ est bien définie sur $\mathbb{R}$ : pour tout $x \in \mathbb{R}$, $\sqrt{1+x^2} > 0$, et $x + \sqrt{1+x^2} > 0$ car $\sqrt{1+x^2} > |x| \geq -x$.

$f$ est composée de fonctions $C^\infty$ sur $\mathbb{R}$, donc $f \in C^\infty(\mathbb{R})$.

$$f'(x) = \frac{1}{x + \sqrt{1+x^2}} \cdot \left(1 + \frac{x}{\sqrt{1+x^2}}\right) = \frac{1}{x + \sqrt{1+x^2}} \cdot \frac{\sqrt{1+x^2} + x}{\sqrt{1+x^2}} = \frac{1}{\sqrt{1+x^2}}$$

Donc $f'(x) = \frac{1}{\sqrt{1+x^2}} > 0$ pour tout $x \in \mathbb{R}$.

**Question 2 — Bijection.**

$f'(x) > 0$ sur $\mathbb{R}$ donc $f$ est **strictement croissante**, donc **injective**.

Limites :
- $\lim_{x \to +\infty} f(x) = \lim_{x \to +\infty} \ln(x + \sqrt{1+x^2})$. Comme $x + \sqrt{1+x^2} \geq x \to +\infty$, $f(x) \to +\infty$.
- $\lim_{x \to -\infty} f(x)$ : on a $x + \sqrt{1+x^2} = x(1 + \sqrt{1/x^2+1}) \approx x \cdot 0 = ...$ Mieux : $f(-x) = \ln(-x + \sqrt{1+x^2})$. Or $(-x+\sqrt{1+x^2})(x+\sqrt{1+x^2}) = 1+x^2-x^2 = 1$. Donc $f(-x) = -\ln(x+\sqrt{1+x^2}) = -f(x)$. La fonction $f$ est **impaire**. Donc $\lim_{x\to-\infty} f(x) = -\lim_{x\to+\infty} f(x) = -\infty$.

Par le TVI, $f(\mathbb{R}) = \mathbb{R}$, donc $f$ est **surjective** de $\mathbb{R}$ dans $\mathbb{R}$.

Conclusion : $f$ est bijective.

**Question 3 — Dérivée de $f^{-1}$.**

$f$ est bijective de classe $C^1$, avec $f'(x) = \frac{1}{\sqrt{1+x^2}} \neq 0$.

Par le théorème de dérivation des bijections réciproques :
$$(f^{-1})'(y) = \frac{1}{f'(f^{-1}(y))} = \frac{1}{\frac{1}{\sqrt{1+(f^{-1}(y))^2}}} = \sqrt{1+(f^{-1}(y))^2}$$

En posant $x = f^{-1}(y)$, on a $y = f(x) = \ln(x + \sqrt{1+x^2})$, donc $e^y = x + \sqrt{1+x^2}$.

On peut montrer que $f^{-1}(y) = \frac{e^y - e^{-y}}{2} = \sinh y$ (sinus hyperbolique).

$(f^{-1})'(y) = \sqrt{1 + \sinh^2 y} = \cosh y$. $\blacksquare$

</details>

---

---

# PARTIE 2 — ANALYSE 2

---

## 🟡 Thème 1 : Convexité et inégalités

### Exercice A.1 — Inégalités par convexité (type partiel !)
1. Montrer que $\forall x \in [0, 1]$, $\frac{\pi}{4} x \leq \arctan x \leq x$.
2. Montrer que $\forall x > -1$, $\forall \alpha > 1$, $(1+x)^\alpha \geq 1 + \alpha x$.

<details>
<summary><strong>✅ Correction complète</strong></summary>

**1. Inégalités pour arctan.**

Posons $g(x) = \arctan x$.

$g'(x) = \frac{1}{1+x^2}$ et $g''(x) = -\frac{2x}{(1+x^2)^2}$.

Sur $[0,1]$, $x \geq 0$ donc $g''(x) \leq 0$. Donc $g = \arctan$ est **concave** sur $[0,1]$.

*Inégalité gauche $\frac{\pi}{4}x \leq \arctan x$ :*

$g$ est concave sur $[0,1]$. En $x_1 = 0$ et $x_2 = 1$, la corde a pour équation :
$$y = g(0) + \frac{g(1) - g(0)}{1 - 0}(x - 0) = 0 + \frac{\pi/4 - 0}{1}x = \frac{\pi}{4}x$$

Pour une fonction concave, la courbe est **au-dessus des cordes**. Donc pour $x \in [0,1]$ :
$$g(x) \geq \frac{\pi}{4}x$$

*Inégalité droite $\arctan x \leq x$ :*

$g$ est concave sur $[0,1]$ et sa tangente en $x_0 = 0$ a pour équation $y = g(0) + g'(0)(x-0) = x$ (car $g'(0) = 1$).

Pour une fonction concave, la courbe est **en dessous de ses tangentes**. Donc pour $x \in [0,1]$ :
$$g(x) \leq x$$

Conclusion : $\frac{\pi}{4}x \leq \arctan x \leq x$ pour $x \in [0,1]$. $\blacksquare$

**2. Inégalité de Bernoulli généralisée.**

Posons $h(x) = (1+x)^\alpha$ sur $]-1, +\infty[$. On a :
- $h'(x) = \alpha(1+x)^{\alpha-1}$
- $h''(x) = \alpha(\alpha-1)(1+x)^{\alpha-2}$

Pour $\alpha > 1$ et $x > -1$ : $(1+x)^{\alpha-2} > 0$ et $\alpha(\alpha-1) > 0$ (car $\alpha > 1$). Donc $h''(x) > 0$ : $h$ est **convexe** sur $]-1, +\infty[$.

La tangente à la courbe de $h$ en $x_0 = 0$ est :
$$T(x) = h(0) + h'(0)(x-0) = 1 + \alpha \cdot 1 \cdot x = 1 + \alpha x$$

Pour une fonction convexe, la courbe est **au-dessus de ses tangentes**. Donc pour $x > -1$ :
$$h(x) \geq T(x) \quad \Leftrightarrow \quad (1+x)^\alpha \geq 1 + \alpha x \qquad \blacksquare$$

</details>

---

## 🟡 Thème 2 : Dérivées d'ordre $n$ et formule de Leibniz

### Exercice B.1 — Dérivées d'ordre $n$ (type partiel !)
Soit $f(x) = (x^2 + x + 1)e^{-x}$.

1. Justifier que $f \in C^\infty(\mathbb{R})$.
2. Calculer $g^{(n)}(x)$ pour $g(x) = e^{-x}$.
3. Calculer $f^{(n)}(x)$ par la formule de Leibniz.

<details>
<summary><strong>✅ Correction complète</strong></summary>

**Question 1.**

$P(x) = x^2 + x + 1$ est un polynôme, donc $C^\infty(\mathbb{R})$.

$g(x) = e^{-x}$ est $C^\infty(\mathbb{R})$ (composée de $\exp$ et d'une fonction affine).

$f = P \cdot g$ est un produit de deux fonctions $C^\infty(\mathbb{R})$, donc $f \in C^\infty(\mathbb{R})$.

**Question 2.** Par récurrence : $g^{(n)}(x) = (-1)^n e^{-x}$.

*Initialisation :* $g^{(0)}(x) = e^{-x}$ ✓, $g^{(1)}(x) = -e^{-x} = (-1)^1 e^{-x}$ ✓.

*Hérédité :* Supposons $g^{(n)}(x) = (-1)^n e^{-x}$. Alors $g^{(n+1)}(x) = ((-1)^n e^{-x})' = (-1)^n \cdot (-e^{-x}) = (-1)^{n+1} e^{-x}$. ✓

**Question 3 — Formule de Leibniz.**

Posons $u(x) = P(x) = x^2 + x + 1$ et $v(x) = e^{-x}$.

Les dérivées de $u$ :
- $u^{(0)} = x^2 + x + 1$
- $u^{(1)} = 2x + 1$
- $u^{(2)} = 2$
- $u^{(k)} = 0$ pour $k \geq 3$

Les dérivées de $v$ : $v^{(k)} = (-1)^k e^{-x}$.

Par Leibniz :
$$f^{(n)} = \sum_{k=0}^{n} \binom{n}{k} u^{(k)} v^{(n-k)}$$

Comme $u^{(k)} = 0$ pour $k \geq 3$, seuls les termes $k = 0, 1, 2$ (si $n \geq 2$) contribuent.

**Pour $n \geq 2$ :**
$$f^{(n)}(x) = \binom{n}{0}(x^2+x+1)(-1)^n e^{-x} + \binom{n}{1}(2x+1)(-1)^{n-1}e^{-x} + \binom{n}{2} \cdot 2 \cdot (-1)^{n-2}e^{-x}$$

$$= e^{-x}\left[(-1)^n(x^2+x+1) - n(-1)^{n-1}(2x+1) \cdot \frac{(-1)^{n-1}}{(-1)^n} \ldots\right]$$

Simplifions en factorisant $(-1)^{n-2}$ :

$$f^{(n)}(x) = (-1)^{n-2} e^{-x}\left[(x^2+x+1)\cdot(-1)^2 - n(2x+1)\cdot(-1) + n(n-1)\right]$$

$$= (-1)^n e^{-x}\left[(x^2+x+1) + n(2x+1) + n(n-1)\right]$$

Attendez, recalculons proprement :

$$f^{(n)}(x) = (x^2+x+1)(-1)^n e^{-x} + n(2x+1)(-1)^{n-1}e^{-x} + \frac{n(n-1)}{2}\cdot 2 \cdot (-1)^{n-2}e^{-x}$$

$$= (-1)^n e^{-x}\left[(x^2+x+1) - n(2x+1) + n(n-1)\right]$$

car $(-1)^{n-1} = -(-1)^n$ et $(-1)^{n-2} = (-1)^n$.

$$\boxed{f^{(n)}(x) = (-1)^n e^{-x}\left[x^2 + (1-2n)x + (1-n+n^2-n)\right] = (-1)^n e^{-x}\left[x^2 + (1-2n)x + (n^2-2n+1)\right]}$$

Simplifions : $n^2 - 2n + 1 = (n-1)^2$, $1 - 2n = -(2n-1)$.

$$f^{(n)}(x) = (-1)^n e^{-x}\left[x^2 - (2n-1)x + (n-1)^2\right]$$

*Vérification pour $n = 1$ :* $f'(x) = (2x+1)e^{-x} - (x^2+x+1)e^{-x} = (-x^2+x)e^{-x}$.

Formule : $(-1)^1 e^{-x}[x^2 - 1 \cdot x + 0] = -e^{-x}[x^2-x] = e^{-x}[x-x^2]$. ✓

</details>

---

### Exercice B.2 — Récurrence sur les dérivées
Soit $f(x) = \frac{1}{x}e^x$ pour $x \neq 0$.

1. Montrer par récurrence qu'il existe un polynôme $Q_n$ tel que $f^{(n)}(x) = \frac{Q_n(x)}{x^{n+1}}e^x$.
2. Trouver une relation de récurrence entre $Q_{n+1}$ et $Q_n$.
3. En utilisant la formule de Leibniz pour $f = g \cdot \exp$ avec $g(x) = 1/x$, donner une expression de $Q_n$.

<details>
<summary><strong>✅ Correction complète</strong></summary>

**Question 1 — Récurrence.**

*Propriété $P_n$ :* $f^{(n)}(x) = \frac{Q_n(x)}{x^{n+1}}e^x$ pour un certain polynôme $Q_n$.

*Initialisation $P_0$ :* $f^{(0)}(x) = f(x) = \frac{e^x}{x} = \frac{1}{x^1} e^x$. Donc $Q_0 = 1$. ✓

*Hérédité :* Supposons $P_n$ vraie. Alors :
$$f^{(n+1)}(x) = \left(\frac{Q_n(x)}{x^{n+1}}e^x\right)'$$

Par la règle du produit :
$$= \frac{Q_n'(x)x^{n+1} - (n+1)x^n Q_n(x)}{x^{2(n+1)}}e^x + \frac{Q_n(x)}{x^{n+1}}e^x$$

$$= \frac{Q_n'(x)x^{n+1} - (n+1)x^n Q_n(x) + x^{n+1}Q_n(x)}{x^{2n+2}}e^x$$

$$= \frac{x^n[Q_n'(x)x - (n+1)Q_n(x) + xQ_n(x)]}{x^{2n+2}}e^x = \frac{Q_n'(x)x + (x-n-1)Q_n(x)}{x^{n+2}}e^x$$

Donc $Q_{n+1}(x) = xQ_n'(x) + (x-n-1)Q_n(x)$, qui est bien un polynôme si $Q_n$ est un polynôme. ✓

**Question 2.** $Q_{n+1}(x) = xQ_n'(x) + (x - n - 1)Q_n(x)$.

**Question 3 — Via Leibniz.**

$g(x) = 1/x$, $g^{(k)}(x) = \frac{(-1)^k k!}{x^{k+1}}$ (par récurrence).

Par Leibniz :
$$f^{(n)}(x) = \sum_{k=0}^n \binom{n}{k} g^{(k)}(x) e^x = e^x \sum_{k=0}^n \binom{n}{k} \frac{(-1)^k k!}{x^{k+1}}$$

$$= \frac{e^x}{x^{n+1}} \sum_{k=0}^n \binom{n}{k} (-1)^k k! \cdot x^{n-k} = \frac{e^x}{x^{n+1}} Q_n(x)$$

avec $Q_n(x) = \sum_{k=0}^n \frac{n!}{(n-k)!}(-1)^k x^{n-k}$.

</details>

---

## 🟡 Thème 3 : Intégration et sommes de Darboux

### Exercice C.1 — Sommes de Darboux et calcul d'intégrale
En utilisant les sommes de Darboux pour $f(x) = x^3$ sur $[0,1]$, montrer que $\int_0^1 x^3\, dx = \frac{1}{4}$.

On rappelle que $\sum_{k=1}^n k^3 = \frac{n^2(n+1)^2}{4}$.

<details>
<summary><strong>✅ Correction complète</strong></summary>

**Calcul des sommes de Darboux.**

On découpe $[0,1]$ en $n$ intervalles : $a_k = k/n$ pour $k = 0, \ldots, n$.

Comme $f(x) = x^3$ est **croissante** sur $[0,1]$, sur $[a_k, a_{k+1}]$ :
- $\min = f(a_k) = (k/n)^3$
- $\max = f(a_{k+1}) = ((k+1)/n)^3$

$$S_n^-(f, [0,1]) = \frac{1}{n}\sum_{k=0}^{n-1}\left(\frac{k}{n}\right)^3 = \frac{1}{n^4}\sum_{k=0}^{n-1} k^3 = \frac{1}{n^4}\sum_{k=1}^{n-1}k^3$$

D'après la formule donnée avec $n-1$ à la place de $n$ :
$$\sum_{k=1}^{n-1}k^3 = \frac{(n-1)^2 n^2}{4}$$

Donc $S_n^- = \frac{(n-1)^2 n^2}{4n^4} = \frac{(n-1)^2}{4n^2} = \frac{1}{4}\left(1 - \frac{1}{n}\right)^2$.

$$S_n^+(f,[0,1]) = \frac{1}{n}\sum_{k=1}^{n}\left(\frac{k}{n}\right)^3 = \frac{1}{n^4}\sum_{k=1}^n k^3 = \frac{n^2(n+1)^2}{4n^4} = \frac{(n+1)^2}{4n^2} = \frac{1}{4}\left(1 + \frac{1}{n}\right)^2$$

**Passage à la limite.**

$$\lim_{n \to +\infty} S_n^- = \lim_{n\to+\infty} \frac{1}{4}\left(1-\frac{1}{n}\right)^2 = \frac{1}{4}$$

$$\lim_{n \to +\infty} S_n^+ = \lim_{n\to+\infty} \frac{1}{4}\left(1+\frac{1}{n}\right)^2 = \frac{1}{4}$$

Comme $S_n^- \leq \int_0^1 x^3\, dx \leq S_n^+$ et les deux encadrements tendent vers $\frac{1}{4}$, par le théorème des gendarmes :
$$\int_0^1 x^3\, dx = \frac{1}{4} \qquad \blacksquare$$

*Vérification par primitive :* $\int_0^1 x^3\, dx = [x^4/4]_0^1 = 1/4$. ✓

</details>

---

### Exercice C.2 — Méthodes de calcul intégral
Calculer les intégrales suivantes :
1. $I_1 = \int_0^1 x e^x\, dx$
2. $I_2 = \int_0^1 \ln(1+x)\, dx$
3. $I_3 = \int_0^{\pi/2} \sin^3 x\, dx$
4. $I_4 = \int_1^e \frac{(\ln x)^2}{x}\, dx$

<details>
<summary><strong>✅ Correction complète</strong></summary>

**1. $I_1 = \int_0^1 x e^x\, dx$ (IPP).**

Posons $u' = e^x$ (donc $u = e^x$) et $v = x$ (donc $v' = 1$).

$$I_1 = [xe^x]_0^1 - \int_0^1 e^x\, dx = (1 \cdot e^1 - 0) - [e^x]_0^1 = e - (e^1 - e^0) = e - e + 1 = 1$$

**2. $I_2 = \int_0^1 \ln(1+x)\, dx$ (IPP).**

Posons $u' = 1$ (donc $u = x$) et $v = \ln(1+x)$ (donc $v' = \frac{1}{1+x}$).

$$I_2 = [x\ln(1+x)]_0^1 - \int_0^1 \frac{x}{1+x}\, dx = \ln 2 - \int_0^1 \frac{x}{1+x}\, dx$$

Or $\frac{x}{1+x} = 1 - \frac{1}{1+x}$. Donc :
$$\int_0^1 \frac{x}{1+x}\, dx = [x - \ln(1+x)]_0^1 = (1 - \ln 2) - 0 = 1 - \ln 2$$

$$I_2 = \ln 2 - (1 - \ln 2) = 2\ln 2 - 1$$

**3. $I_3 = \int_0^{\pi/2} \sin^3 x\, dx$ (technique).**

On écrit $\sin^3 x = \sin^2 x \cdot \sin x = (1 - \cos^2 x)\sin x$.

Changement de variable : $t = \cos x$, $dt = -\sin x\, dx$.
- $x = 0 \to t = 1$, $x = \pi/2 \to t = 0$.

$$I_3 = \int_1^0 (1-t^2)(-dt) = \int_0^1 (1-t^2)\, dt = \left[t - \frac{t^3}{3}\right]_0^1 = 1 - \frac{1}{3} = \frac{2}{3}$$

**4. $I_4 = \int_1^e \frac{(\ln x)^2}{x}\, dx$ (substitution).**

Changement de variable : $t = \ln x$, $dt = dx/x$.
- $x = 1 \to t = 0$, $x = e \to t = 1$.

$$I_4 = \int_0^1 t^2\, dt = \left[\frac{t^3}{3}\right]_0^1 = \frac{1}{3}$$

</details>

---

## 🟡 Thème 4 : Formule de Taylor et reste intégral

### Exercice D.1 — Application du TFA
Soit $F(x) = \int_0^x |t|\, dt$.

1. $F$ est-elle de classe $C^1$ sur $\mathbb{R}$ ? Deux fois dérivable sur $\mathbb{R}$ ?
2. Calculer $F(x)$ pour tout $x \in \mathbb{R}$.

<details>
<summary><strong>✅ Correction complète</strong></summary>

**Question 1 — Sans calculer.**

La fonction $t \mapsto |t|$ est continue sur $\mathbb{R}$ (mais pas dérivable en 0).

D'après le théorème fondamental du calcul intégral, $F$ est **dérivable** sur $\mathbb{R}$ avec $F'(x) = |x|$.

Comme $|x|$ est continue sur $\mathbb{R}$, $F \in C^1(\mathbb{R})$.

$F'(x) = |x|$ est dérivable en tout $x \neq 0$, mais **pas dérivable en 0** (la dérivée à gauche de $|x|$ en 0 est $-1$ et la dérivée à droite est $+1$).

Donc **$F$ n'est pas deux fois dérivable sur $\mathbb{R}$**.

**Question 2 — Calcul de $F(x)$.**

*Cas $x \geq 0$ :*
$$F(x) = \int_0^x |t|\, dt = \int_0^x t\, dt = \left[\frac{t^2}{2}\right]_0^x = \frac{x^2}{2}$$

*Cas $x < 0$ :*
$$F(x) = \int_0^x |t|\, dt = -\int_x^0 |t|\, dt = -\int_x^0 (-t)\, dt = \int_x^0 t\, dt = \left[\frac{t^2}{2}\right]_x^0 = -\frac{x^2}{2}$$

En résumé :
$$F(x) = \begin{cases} \frac{x^2}{2} & \text{si } x \geq 0 \\ -\frac{x^2}{2} & \text{si } x < 0 \end{cases} = \frac{x|x|}{2}$$

*Vérification :* $F'(x) = |x|$ ✓, $F(0) = 0$ ✓. Sur $\mathbb{R}^+$ : $F''(x) = 1 > 0$. Sur $\mathbb{R}^-$ : $F''(x) = -1 < 0$. En 0 : pas dérivable deux fois. ✓

</details>

---

## 🟡 Thème 5 : Développements Limités

### Exercice E.1 — Calcul de limites par DL
Calculer les limites suivantes :
1. $\lim_{x \to 0} \frac{\sin x - x + x^3/6}{x^5}$
2. $\lim_{x \to 0} \frac{e^x - 1 - x}{\sin^2 x}$
3. $\lim_{x \to 0} \frac{1 - \cos x}{\ln(1+x^2)}$
4. $\lim_{x \to +\infty} x\left(\sqrt{x^2+1} - x\right)$

<details>
<summary><strong>✅ Correction complète</strong></summary>

**1.**
$$\sin x = x - \frac{x^3}{6} + \frac{x^5}{120} + o(x^5)$$
$$\sin x - x + \frac{x^3}{6} = \frac{x^5}{120} + o(x^5)$$
$$\frac{\sin x - x + x^3/6}{x^5} = \frac{1}{120} + o(1) \to \frac{1}{120}$$

**2.**
$$e^x - 1 - x = \frac{x^2}{2} + \frac{x^3}{6} + o(x^3)$$
$$\sin^2 x = \left(x - \frac{x^3}{6} + o(x^3)\right)^2 = x^2 - \frac{x^4}{3} + o(x^4) \approx x^2 + o(x^2)$$

$$\frac{e^x - 1 - x}{\sin^2 x} = \frac{x^2/2 + o(x^2)}{x^2 + o(x^2)} = \frac{1/2 + o(1)}{1 + o(1)} \to \frac{1}{2}$$

**3.**
$$1 - \cos x = \frac{x^2}{2} + o(x^2), \quad \ln(1+x^2) = x^2 + o(x^2)$$
$$\frac{1-\cos x}{\ln(1+x^2)} = \frac{x^2/2 + o(x^2)}{x^2 + o(x^2)} = \frac{1/2 + o(1)}{1+o(1)} \to \frac{1}{2}$$

**4.** Posons $u = 1/x^2 \to 0^+$ quand $x \to +\infty$.
$$\sqrt{x^2+1} = x\sqrt{1+1/x^2} = x\left(1 + \frac{1}{2x^2} - \frac{1}{8x^4} + o(1/x^4)\right)$$
$$\sqrt{x^2+1} - x = \frac{1}{2x} + o(1/x)$$
$$x(\sqrt{x^2+1} - x) = x \cdot \frac{1}{2x} + o(1) = \frac{1}{2} + o(1) \to \frac{1}{2}$$

</details>

---

### Exercice E.2 — DL et asymptote oblique
Étudier le comportement de $f(x) = \sqrt{x^2 + 2x + 3}$ en $+\infty$. Trouver une asymptote oblique.

<details>
<summary><strong>✅ Correction complète</strong></summary>

On factorise par $x$ (pour $x > 0$) :
$$f(x) = \sqrt{x^2 + 2x + 3} = x\sqrt{1 + \frac{2}{x} + \frac{3}{x^2}}$$

Posons $u = 2/x + 3/x^2 \to 0$ quand $x \to +\infty$.

$$\sqrt{1+u} = 1 + \frac{u}{2} - \frac{u^2}{8} + o(u^2)$$

$$u = \frac{2}{x} + \frac{3}{x^2}, \quad \frac{u}{2} = \frac{1}{x} + \frac{3}{2x^2}, \quad u^2 = \frac{4}{x^2} + o(1/x^2)$$

Donc :
$$\sqrt{1+u} = 1 + \frac{1}{x} + \frac{3}{2x^2} - \frac{1}{2x^2} + o(1/x^2) = 1 + \frac{1}{x} + \frac{1}{x^2} + o(1/x^2)$$

$$f(x) = x\left(1 + \frac{1}{x} + \frac{1}{x^2} + o(1/x^2)\right) = x + 1 + \frac{1}{x} + o(1/x)$$

**Asymptote oblique en $+\infty$ :** $y = x + 1$.

*Vérification :* $f(x) - (x+1) = \frac{1}{x} + o(1/x) \to 0$. ✓

La courbe est **au-dessus** de l'asymptote pour $x$ grand ($f(x) - (x+1) \approx 1/x > 0$).

</details>

---

### Exercice E.3 — DL d'une somme de Darboux (type partiel avancé)
On définit $u_n = \sum_{k=0}^{n-1} \frac{1}{\sqrt{n^2 + k^2}}$.

1. Montrer que $u_n$ est une somme de Riemann d'une certaine fonction sur $[0,1]$.
2. Calculer $\lim_{n \to +\infty} u_n$.

<details>
<summary><strong>✅ Correction complète</strong></summary>

**Question 1.**

$$u_n = \sum_{k=0}^{n-1} \frac{1}{\sqrt{n^2 + k^2}} = \sum_{k=0}^{n-1} \frac{1}{n\sqrt{1 + (k/n)^2}} = \frac{1}{n}\sum_{k=0}^{n-1} f\!\left(\frac{k}{n}\right)$$

avec $f(x) = \frac{1}{\sqrt{1+x^2}}$.

C'est la somme de Riemann (à gauche) de $f$ sur $[0,1]$ pour la subdivision en $n$ parties égales.

La fonction $f(x) = \frac{1}{\sqrt{1+x^2}}$ est continue sur $[0,1]$ (c'est une composée de fonctions continues, le dénominateur ne s'annule pas).

**Question 2.**

Par la définition de l'intégrale de Riemann, la somme converge vers :
$$\lim_{n \to +\infty} u_n = \int_0^1 \frac{dx}{\sqrt{1+x^2}}$$

Or on sait (cf. table des primitives) que $\frac{d}{dx}\ln(x+\sqrt{1+x^2}) = \frac{1}{\sqrt{1+x^2}}$.

Donc :
$$\int_0^1 \frac{dx}{\sqrt{1+x^2}} = \left[\ln(x+\sqrt{1+x^2})\right]_0^1 = \ln(1+\sqrt{2}) - \ln(0+1) = \ln(1+\sqrt{2})$$

$$\lim_{n \to +\infty} u_n = \ln(1+\sqrt{2})$$

</details>


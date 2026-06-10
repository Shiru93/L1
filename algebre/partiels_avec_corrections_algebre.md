# 📋 Sujets de Partiels avec Corrections — Algèbre 1 & 2
### L1 Informatique — Institut Galilée
> 3 sujets complets d'après les annales réelles 2021–2024.

---

# 🏆 SUJET 1 — PARTIEL ALGÈBRE 1 (simulé d'après annales)

**Durée : 2h — Documents et calculatrice interdits**

---

### Exercice 1 — Questions de cours (4 points)

1. Donner la définition de l'inclusion $A \subset B$ pour deux ensembles $A$ et $B$.
2. Énoncer les lois de De Morgan.
3. Donner la définition d'une application bijective $f : A \to B$.
4. Énoncer le principe de récurrence simple.

---

### Exercice 2 — Opérations sur les ensembles (5 points)

Soient $A$, $B$, $C$ des sous-ensembles d'un ensemble $E$.

1. Montrer par double inclusion que $(A \cap B) \cup C = (A \cup C) \cap (B \cup C)$.
2. Montrer que si $A \subset B$ et $B \subset C$, alors $A \subset C$.
3. Soit $f : X \to Y$ une application. Montrer que $f(A \cup B) = f(A) \cup f(B)$ pour $A, B \subset X$.
4. Donner un exemple montrant que $f(A \cap B) \subsetneq f(A) \cap f(B)$ peut être une inclusion stricte.

---

### Exercice 3 — Quantificateurs et négations (4 points)

1. Écrire avec des quantificateurs la définition de "$f : \mathbb{R} \to \mathbb{R}$ est continue en $a$".
2. Écrire la négation de la proposition : "$\forall x \in \mathbb{R},\ \exists n \in \mathbb{N},\ x < n$".
3. L'ordre des quantificateurs est-il important ? Illustrer avec un exemple.
4. Écrire la négation de "la suite $(u_n)$ converge vers $\ell$".

---

### Exercice 4 — Injections, surjections, bijections (4 points)

Soit $f : \mathbb{R} \to \mathbb{R}$ définie par $f(x) = x^3 - x$.

1. Montrer que $f$ n'est pas injective.
2. Montrer que $f$ est surjective.
3. Restreindre le domaine pour obtenir une bijection. Justifier.

---

### Exercice 5 — Récurrence et combinatoire (3 points)

1. Démontrer par récurrence que pour tout $n \geq 1$ : $\sum_{k=1}^n k^2 = \frac{n(n+1)(2n+1)}{6}$.
2. Calculer $\binom{10}{4}$ et $\binom{12}{2}$.
3. Combien y a-t-il d'injections de $\{1,2,3\}$ dans $\{1,2,3,4,5\}$ ?

---

## ✅ CORRECTION SUJET 1

---

### Exercice 1

**1.** $A \subset B$ signifie : $\forall x,\ (x \in A \Rightarrow x \in B)$.

**2.** Lois de De Morgan :
$$\overline{A \cup B} = \overline{A} \cap \overline{B} \qquad \text{et} \qquad \overline{A \cap B} = \overline{A} \cup \overline{B}$$

**3.** $f : A \to B$ est bijective si elle est injective ($f(x)=f(x') \Rightarrow x=x'$) ET surjective ($\forall y \in B, \exists x \in A, f(x)=y$).

**4.** Principe de récurrence : si $P(0)$ est vraie, et si pour tout $n \in \mathbb{N}$, $P(n) \Rightarrow P(n+1)$, alors $P(n)$ est vraie pour tout $n \in \mathbb{N}$.

---

### Exercice 2

**1.** Montrons $(A \cap B) \cup C = (A \cup C) \cap (B \cup C)$.

*$\subset$ :* Soit $x \in (A \cap B) \cup C$.
- Cas $x \in C$ : $x \in A \cup C$ et $x \in B \cup C$, donc $x \in (A\cup C) \cap (B\cup C)$.
- Cas $x \in A \cap B$ (et $x \notin C$) : $x \in A$ donc $x \in A\cup C$, et $x \in B$ donc $x \in B\cup C$. Donc $x \in (A\cup C)\cap(B\cup C)$.

*$\supset$ :* Soit $x \in (A\cup C)\cap(B\cup C)$. Alors $x \in A\cup C$ et $x \in B\cup C$.
- Si $x \in C$ : $x \in (A\cap B)\cup C$. ✓
- Si $x \notin C$ : alors $x \in A$ (car $x \in A\cup C$ et $x\notin C$) et $x \in B$ (car $x \in B\cup C$ et $x\notin C$). Donc $x \in A\cap B \subset (A\cap B)\cup C$. ✓

**2.** Transitivité : voir Exercice 1.1 du cahier d'exercices.

**3.** $f(A \cup B) = f(A) \cup f(B)$ : voir Exercice 1.2.

**4.** Contre-exemple : $f : \{1,2\} \to \{0\}$, $f(1) = f(2) = 0$. Prendre $A = \{1\}$, $B = \{2\}$. $f(A \cap B) = f(\emptyset) = \emptyset$ mais $f(A) \cap f(B) = \{0\} \cap \{0\} = \{0\} \neq \emptyset$.

---

### Exercice 3

**1.** $f$ est continue en $a$ :
$$\forall \varepsilon > 0,\ \exists \eta > 0,\ \forall x \in \mathbb{R},\ |x-a| < \eta \Rightarrow |f(x)-f(a)| < \varepsilon$$

**2.** Négation de "$\forall x \in \mathbb{R},\ \exists n \in \mathbb{N},\ x < n$" :
$$\exists x \in \mathbb{R},\ \forall n \in \mathbb{N},\ x \geq n$$
(Il existe un réel plus grand que tout entier naturel — cette proposition est fausse, car $\mathbb{N}$ est non borné dans $\mathbb{R}$.)

**3.** L'ordre est crucial. Exemple :
- $P_1 : \forall m \in \mathbb{N},\ \exists k \in \mathbb{N},\ m < k$ — VRAIE (pour tout entier, l'entier suivant est plus grand)
- $P_2 : \exists k \in \mathbb{N},\ \forall m \in \mathbb{N},\ m < k$ — FAUSSE (il n'existe pas d'entier qui majore tous les entiers)

**4.** Négation de "$(u_n)$ converge vers $\ell$" :
$$\exists \varepsilon > 0,\ \forall N \in \mathbb{N},\ \exists n \geq N,\ |u_n - \ell| \geq \varepsilon$$

---

### Exercice 4

**1. Non-injectivité.** $f(0) = 0$, $f(1) = 0$, $f(-1) = 0$. Donc $f(1) = f(-1) = 0$ avec $1 \neq -1$. $f$ n'est pas injective.

**2. Surjectivité.** $f$ est un polynôme de degré impair (3) à coefficients réels, donc $\lim_{x\to+\infty} f(x) = +\infty$ et $\lim_{x\to-\infty} f(x) = -\infty$.

Pour tout $y \in \mathbb{R}$, posons $g(x) = f(x) - y = x^3 - x - y$. $g$ est continue, $g(-\infty) = -\infty$, $g(+\infty) = +\infty$. Par le TVI, il existe $c$ tel que $g(c) = 0$, i.e., $f(c) = y$. Donc $f$ est surjective. $\blacksquare$

**3. Restriction.** $f'(x) = 3x^2 - 1 > 0 \Leftrightarrow |x| > 1/\sqrt{3}$. Donc $f$ est strictement croissante sur $[1/\sqrt{3}, +\infty[$ et $f([1/\sqrt{3}, +\infty[) = [f(1/\sqrt{3}), +\infty[$.

$f(1/\sqrt{3}) = 1/(3\sqrt{3}) - 1/\sqrt{3} = -2/(3\sqrt{3})$.

Donc $f : [1/\sqrt{3}, +\infty[ \to [-2/(3\sqrt{3}), +\infty[$ est bijective. $\blacksquare$

---

### Exercice 5

**1. Récurrence.**

$P(n) : \sum_{k=1}^n k^2 = \frac{n(n+1)(2n+1)}{6}$.

*Init :* $P(1) : 1 = \frac{1 \cdot 2 \cdot 3}{6} = 1$. ✓

*Hérédité :*
$$\sum_{k=1}^{n+1}k^2 = \sum_{k=1}^n k^2 + (n+1)^2 = \frac{n(n+1)(2n+1)}{6} + (n+1)^2 = (n+1)\left[\frac{n(2n+1)}{6} + (n+1)\right]$$
$$= (n+1) \cdot \frac{n(2n+1) + 6(n+1)}{6} = (n+1) \cdot \frac{2n^2+7n+6}{6} = (n+1) \cdot \frac{(n+2)(2n+3)}{6}$$
C'est bien $\frac{(n+1)(n+2)(2(n+1)+1)}{6} = P(n+1)$. $\blacksquare$

**2.** $\binom{10}{4} = \frac{10!}{4! \cdot 6!} = \frac{10 \times 9 \times 8 \times 7}{4!} = \frac{5040}{24} = 210$.

$\binom{12}{2} = \frac{12 \times 11}{2} = 66$.

**3.** Injections de $\{1,2,3\}$ dans $\{1,2,3,4,5\}$ : pour $1$ on a 5 choix, pour $2$ il reste 4 choix, pour $3$ il reste 3 choix. Total : $5 \times 4 \times 3 = 60$.

---
---

# 🏆 SUJET 2 — PARTIEL ALGÈBRE 2, PARTIEL 1 (simulé d'après annales 2021–2023)

**Durée : 2h — Documents interdits**

---

### Exercice 1 — Espaces vectoriels (6 points)

Soit $E$ un $\mathbb{K}$-espace vectoriel.

1. Donner la définition de la somme $F + G$ de deux sous-espaces vectoriels $F$ et $G$ de $E$, et montrer que $F + G$ est un sous-espace vectoriel de $E$.
2. Donner la définition de "F et G sont en somme directe".
3. Parmi les familles suivantes de vecteurs de $\mathbb{C}^3$, déterminer les familles libres et les familles liées :
   - $\mathcal{F}_1 = \{(1, 2, 1-3i), (0, 0, 0)\}$
   - $\mathcal{F}_2 = \{(1, 2, 3)\}$
   - $\mathcal{F}_3 = \{(1,0,0), (0,1,0), (0,0,1)\}$
   - $\mathcal{F}_4 = \{(1,1,1), (1-i, 1+i, 1-i)\}$

---

### Exercice 2 — Nombres complexes (5 points)

Soit $x$ un nombre réel.

1. Justifier la formule $\cos(2x) = \text{Re}((e^{ix})^2)$.
2. En déduire la formule trigonométrique $\cos(2x) = 2\cos^2(x) - 1$.
3. De même, calculer $\cos(3x)$ en fonction de $\cos(x)$.
4. Résoudre dans $\mathbb{C}$ : $z^2 - (1-i)z - i = 0$.

---

### Exercice 3 — Systèmes linéaires (4 points)

Résoudre le système suivant en discutant selon la valeur du paramètre $a \in \mathbb{R}$ :
$$\begin{cases} x + y + z = 1 \\ x + ay + z = a \\ ax + y + z = a^2 \end{cases}$$

---

### Exercice 4 — Questions de cours (5 points)

1. Énoncer le théorème du rang.
2. Soit $f : \mathbb{R}^3 \to \mathbb{R}^3$ une application linéaire. Quelles sont les dimensions possibles de $\text{Ker}(f)$ ? Donner un exemple dans chaque cas.
3. Soient $F$ et $G$ deux sous-espaces vectoriels supplémentaires d'un espace vectoriel de dimension finie $E$. Donner une formule reliant $\dim E$, $\dim F$ et $\dim G$.

---

## ✅ CORRECTION SUJET 2

---

### Exercice 1

**1. Somme $F+G$.**

**Définition.** $F + G = \{u + v \mid u \in F,\ v \in G\}$.

*Montrons que c'est un sev :*
- $0 \in F+G$ : $0 = 0_F + 0_G \in F+G$ (car $0_F \in F$ et $0_G \in G$). ✓
- Stabilité addition : si $w = u+v$ et $w' = u'+v'$ (avec $u,u' \in F$, $v,v' \in G$), alors $w+w' = (u+u') + (v+v')$ avec $u+u' \in F$ et $v+v' \in G$. ✓
- Stabilité scalaire : $\lambda w = \lambda u + \lambda v$ avec $\lambda u \in F$ et $\lambda v \in G$. ✓

Donc $F + G$ est un sev. $\blacksquare$

**2. Somme directe.** $F$ et $G$ sont en **somme directe** (notée $F \oplus G$) si $F \cap G = \{0\}$.

Équivalent : tout vecteur de $F + G$ s'écrit de façon **unique** comme $u + v$ avec $u \in F$, $v \in G$.

**3.**
- $\mathcal{F}_1$ : contient le vecteur nul $(0,0,0)$ → toute famille contenant le vecteur nul est **liée** ($1 \cdot (0,0,0) = 0$).
- $\mathcal{F}_2$ : un seul vecteur non nul → **libre**.
- $\mathcal{F}_3$ : base canonique de $\mathbb{C}^3$ → **libre** (et génératrice).
- $\mathcal{F}_4$ : deux vecteurs. Sont-ils proportionnels ? $(1-i, 1+i, 1-i) = \lambda(1,1,1)$ impliquerait $\lambda = 1-i$ (1re coord.), $\lambda = 1+i$ (2e coord.) → $1-i = 1+i$, faux. Donc **libre**.

---

### Exercice 2

**1.** $(e^{ix})^2 = e^{i \cdot 2x} = \cos(2x) + i\sin(2x)$ par la formule d'Euler. Donc $\cos(2x) = \text{Re}((e^{ix})^2)$. $\blacksquare$

**2.** $(e^{ix})^2 = (\cos x + i\sin x)^2 = \cos^2 x + 2i\cos x\sin x - \sin^2 x = (\cos^2 x - \sin^2 x) + i(2\cos x\sin x)$.

Partie réelle : $\cos(2x) = \cos^2 x - \sin^2 x = \cos^2 x - (1-\cos^2 x) = 2\cos^2 x - 1$. $\blacksquare$

**3.** $(e^{ix})^3 = e^{3ix} = \cos(3x) + i\sin(3x)$.

$(\cos x + i\sin x)^3 = \cos^3 x + 3\cos^2 x (i\sin x) + 3\cos x(i\sin x)^2 + (i\sin x)^3$

$= \cos^3 x - 3\cos x\sin^2 x + i(3\cos^2 x\sin x - \sin^3 x)$

Partie réelle : $\cos(3x) = \cos^3 x - 3\cos x\sin^2 x = \cos^3 x - 3\cos x(1-\cos^2 x) = 4\cos^3 x - 3\cos x$.

**4.** Discriminant : $\Delta = (1-i)^2 + 4i = 1 - 2i - 1 + 4i = 2i$.

Racines carrées de $2i$ : $2i = 2e^{i\pi/2}$, donc $\sqrt{2i} = \sqrt{2} e^{i\pi/4} = 1+i$ et $-(1+i)$.

Solutions : $z = \frac{(1-i) \pm (1+i)}{2}$.

- $z_1 = \frac{(1-i)+(1+i)}{2} = \frac{2}{2} = 1$
- $z_2 = \frac{(1-i)-(1+i)}{2} = \frac{-2i}{2} = -i$

*Vérification :* $1 - (1-i)(1) - i = 1 - 1 + i - i = 0$ ✓. $(-i)^2 - (1-i)(-i) - i = -1 + (i + i^2) - i = -1 + i - 1 - i = -2 \neq 0$...

Recalculons : $(-i)^2 - (1-i)(-i) - i = -1 - (-i + i^2) - i = -1 + i + 1 - i = 0$. ✓

---

### Exercice 3

Matrice augmentée :
$$\begin{pmatrix} 1 & 1 & 1 & | & 1 \\ 1 & a & 1 & | & a \\ a & 1 & 1 & | & a^2 \end{pmatrix}$$

$L_2 \leftarrow L_2 - L_1$, $L_3 \leftarrow L_3 - aL_1$ :
$$\begin{pmatrix} 1 & 1 & 1 & | & 1 \\ 0 & a-1 & 0 & | & a-1 \\ 0 & 1-a & 1-a & | & a^2-a \end{pmatrix}$$

$L_3 \leftarrow L_3 + L_2$ :
$$\begin{pmatrix} 1 & 1 & 1 & | & 1 \\ 0 & a-1 & 0 & | & a-1 \\ 0 & 0 & 1-a & | & a^2-1 \end{pmatrix}$$

$a^2 - 1 = (a-1)(a+1)$.

**Cas $a = 1$ :** Matrice $\begin{pmatrix}1&1&1&|&1\\0&0&0&|&0\\0&0&0&|&0\end{pmatrix}$. Infinité de solutions : $x + y + z = 1$ avec $y, z$ libres. $\dim = 2$.

**Cas $a \neq 1$ :** $L_2 \div (a-1)$ et $L_3 \div (1-a)$ :
$$\begin{pmatrix} 1 & 1 & 1 & | & 1 \\ 0 & 1 & 0 & | & 1 \\ 0 & 0 & 1 & | & -(a+1) \end{pmatrix}$$

- $z = -(a+1)$
- $y = 1$
- $x = 1 - y - z = 1 - 1 + (a+1) = a+1$

Solution unique : $(x,y,z) = (a+1, 1, -(a+1))$.

**Résumé :**
- $a = 1$ : infinité de solutions ($y, z$ libres avec $x = 1-y-z$)
- $a \neq 1$ : solution unique $(a+1, 1, -(a+1))$

---

### Exercice 4

**1. Théorème du rang.** Soit $f : E \to F$ linéaire avec $E$ de dimension finie. Alors :
$$\dim(\text{Ker}(f)) + \dim(\text{Im}(f)) = \dim E$$

**2. Dimensions possibles de $\text{Ker}(f)$ pour $f : \mathbb{R}^3 \to \mathbb{R}^3$ :**

Par le théorème du rang, $\dim\text{Ker}(f) + \dim\text{Im}(f) = 3$. Donc $\dim\text{Ker}(f) \in \{0, 1, 2, 3\}$.

- $\dim = 0$ : $f$ injective. Ex : $f(x,y,z) = (x,y,z)$ (identité).
- $\dim = 1$ : Ex : $f(x,y,z) = (x,y,0)$ ($\text{Ker} = \text{Vect}(e_3)$).
- $\dim = 2$ : Ex : $f(x,y,z) = (x,0,0)$ ($\text{Ker} = \{y\text{-axis}\} \times \{z\text{-axis}\}$).
- $\dim = 3$ : $f = 0$ (application nulle). $\text{Ker}(f) = \mathbb{R}^3$.

**3. Supplémentaires.** Si $E = F \oplus G$ (supplémentaires), alors :
$$\dim E = \dim F + \dim G$$

---
---

# 🏆 SUJET 3 — PARTIEL ALGÈBRE 2, PARTIEL 2 (simulé d'après annales 2022–2024)

**Durée : 2h — Documents interdits**

---

### Exercice 1 — Questions de cours (4 points)

1. Donner la définition d'une famille de vecteurs libre.
2. Énoncer le théorème du rang.
3. Soit $f : E \to F$ injective avec $\dim E$ et $\dim F$ finis. Montrer que $\dim E \leq \dim F$.
4. Soient $F$ et $G$ deux sous-espaces vectoriels supplémentaires de $E$. Donner une formule pour $\dim E$.

---

### Exercice 2 — Matrices (5 points)

On considère la famille de vecteurs de $\mathbb{R}^3$ dépendant d'un paramètre $a$ :
$$\{(a, 1, 1), (1, a, 1), (1, 1, a)\}$$

1. Déterminer les valeurs de $a$ pour lesquelles cette famille est libre.
2. Pour les valeurs de $a$ où la famille est liée, décrire les relations de dépendance.

---

### Exercice 3 — Application linéaire (6 points)

Soit $f : \mathbb{R}^2 \to \mathbb{R}^2$ définie par $f(e_1) = e_1 + 2e_2$ et $f(e_2) = 2e_1 + e_2$ où $(e_1, e_2)$ est la base canonique.

1. Montrer que $f$ est linéaire.
2. Écrire la matrice $A$ de $f$ dans la base canonique.
3. Calculer $\text{Ker}(f)$ et $\text{Im}(f)$.
4. $f$ est-elle bijective ? Calculer $A^{-1}$ si possible.
5. Trouver une base $(u, v)$ de $\mathbb{R}^2$ telle que $f(u) = 3u$ et $f(v) = -v$.

---

### Exercice 4 — Nombres complexes (5 points)

1. Résoudre dans $\mathbb{C}$ : $z^6 = -64$.
2. Mettre les solutions sous forme algébrique $a + bi$.
3. Calculer $(1+i)^{16}$.
4. Trouver toutes les solutions de $z^4 + 4 = 0$. *(On pourra utiliser $z^4 + 4 = (z^2 + 2i)(z^2 - 2i)$.)*

---

## ✅ CORRECTION SUJET 3

---

### Exercice 1

**1.** La famille $(v_1, \ldots, v_k)$ est **libre** (ou linéairement indépendante) si :
$$\lambda_1 v_1 + \cdots + \lambda_k v_k = 0 \Rightarrow \lambda_1 = \cdots = \lambda_k = 0$$

**2. Théorème du rang.** (Voir Sujet 2, Ex. 4.)

**3.** $f$ injective $\Rightarrow \text{Ker}(f) = \{0\} \Rightarrow \dim\text{Ker}(f) = 0$.

Par le théorème du rang : $\dim\text{Im}(f) = \dim E - 0 = \dim E$.

Or $\text{Im}(f) \subset F$, donc $\dim\text{Im}(f) \leq \dim F$.

Donc $\dim E = \dim\text{Im}(f) \leq \dim F$. $\blacksquare$

**4.** $E = F \oplus G \Rightarrow \dim E = \dim F + \dim G$.

---

### Exercice 2

**Matrice** : $A = \begin{pmatrix}a&1&1\\1&a&1\\1&1&a\end{pmatrix}$.

**Déterminant :**
$$\det(A) = a(a^2-1) - 1(a-1) + 1(1-a)$$
$$= a^3 - a - a + 1 + 1 - a = a^3 - 3a + 2 = (a-1)^2(a+2)$$

**La famille est libre** $\Leftrightarrow$ $\det(A) \neq 0$ $\Leftrightarrow$ $a \neq 1$ et $a \neq -2$.

**Cas $a = 1$ :** Les trois vecteurs sont $(1,1,1)$, $(1,1,1)$, $(1,1,1)$ : identiques, donc $1 \cdot v_1 - 1 \cdot v_2 = 0$. Relation : $v_1 = v_2 = v_3$.

**Cas $a = -2$ :** On cherche $(\lambda_1, \lambda_2, \lambda_3)$ tel que $\lambda_1(-2,1,1) + \lambda_2(1,-2,1) + \lambda_3(1,1,-2) = 0$.

Système : $-2\lambda_1 + \lambda_2 + \lambda_3 = 0$, $\lambda_1 - 2\lambda_2 + \lambda_3 = 0$, $\lambda_1 + \lambda_2 - 2\lambda_3 = 0$.

Somme des équations : $0 = 0$ (redondant). Résolution : $\lambda_1 = \lambda_2 = \lambda_3 = t$ convient pour tout $t$. Relation : $v_1 + v_2 + v_3 = 0$ (car $(-2+1+1, 1-2+1, 1+1-2) = (0,0,0)$).

---

### Exercice 3

**1.** $f$ est entièrement définie par ses valeurs sur la base. Par définition d'une application linéaire, les valeurs $f(e_1)$ et $f(e_2)$ déterminent $f$ uniquement, et $f$ est linéaire car $f(x e_1 + y e_2) = x f(e_1) + y f(e_2)$.

**2.** $A = \begin{pmatrix}1&2\\2&1\end{pmatrix}$ (colonnes = images des vecteurs de base).

**3.** $\text{Ker}(f) = \{(x,y) \mid f(x,y) = (0,0)\}$, i.e., $x + 2y = 0$ et $2x + y = 0$.

De $x + 2y = 0$ et $2x + y = 0$ : soustraire → $-x + y = 0 \Rightarrow y = x$. Donc $x + 2x = 0 \Rightarrow x = 0$, $y = 0$.

$\text{Ker}(f) = \{0\}$, $\dim\text{Ker}(f) = 0$.

Par le théorème du rang : $\dim\text{Im}(f) = 2$. Donc $\text{Im}(f) = \mathbb{R}^2$.

**4.** $f$ bijective (injective + $\dim$ égales). $\det(A) = 1-4 = -3 \neq 0$. ✓

$$A^{-1} = \frac{1}{-3}\begin{pmatrix}1&-2\\-2&1\end{pmatrix} = \begin{pmatrix}-1/3 & 2/3 \\ 2/3 & -1/3\end{pmatrix}$$

**5.** On cherche les vecteurs propres : $f(u) = \lambda u$, i.e., $Au = \lambda u$.

Valeurs propres : $\det(A - \lambda I) = (1-\lambda)^2 - 4 = \lambda^2 - 2\lambda - 3 = (\lambda-3)(\lambda+1) = 0$.

- $\lambda = 3$ : $(A - 3I)u = 0 \Rightarrow \begin{pmatrix}-2&2\\2&-2\end{pmatrix}u = 0 \Rightarrow -2x+2y=0 \Rightarrow y=x$. Donc $u = (1,1)$.
- $\lambda = -1$ : $(A+I)u = 0 \Rightarrow \begin{pmatrix}2&2\\2&2\end{pmatrix}u = 0 \Rightarrow x+y=0$. Donc $v = (1,-1)$.

Vérification : $f(1,1) = (1+2, 2+1) = (3,3) = 3(1,1)$. ✓ $f(1,-1) = (1-2, 2-1) = (-1, 1) = -(1,-1)$. ✓

Base : $(u, v) = ((1,1), (1,-1))$. $\blacksquare$

---

### Exercice 4

**1. Résolution de $z^6 = -64$.**

$-64 = 64 e^{i\pi}$. Les solutions : $z_k = 64^{1/6} e^{i(\pi + 2k\pi)/6} = 2 e^{i\pi(2k+1)/6}$ pour $k = 0, 1, 2, 3, 4, 5$.

**2. Forme algébrique :**

| $k$ | Argument | $\cos$ | $\sin$ | Forme $a+bi$ |
|-----|----------|--------|--------|--------------|
| 0 | $\pi/6$ | $\sqrt{3}/2$ | $1/2$ | $\sqrt{3}+i$ |
| 1 | $\pi/2$ | $0$ | $1$ | $2i$ |
| 2 | $5\pi/6$ | $-\sqrt{3}/2$ | $1/2$ | $-\sqrt{3}+i$ |
| 3 | $7\pi/6$ | $-\sqrt{3}/2$ | $-1/2$ | $-\sqrt{3}-i$ |
| 4 | $3\pi/2$ | $0$ | $-1$ | $-2i$ |
| 5 | $11\pi/6$ | $\sqrt{3}/2$ | $-1/2$ | $\sqrt{3}-i$ |

**3. $(1+i)^{16}$.**

$1+i = \sqrt{2} e^{i\pi/4}$.

$(1+i)^{16} = (\sqrt{2})^{16} e^{i \cdot 16\pi/4} = 2^8 e^{4i\pi} = 256 \cdot 1 = 256$.

**4. $z^4 + 4 = 0$.**

En utilisant la factorisation $z^4 + 4 = (z^2+2i)(z^2-2i)$ :

*$z^2 = -2i = 2e^{-i\pi/2}$ :* $z = \sqrt{2}e^{-i\pi/4} = 1-i$ et $z = \sqrt{2}e^{i3\pi/4} = -1+i$.

*$z^2 = 2i = 2e^{i\pi/2}$ :* $z = \sqrt{2}e^{i\pi/4} = 1+i$ et $z = \sqrt{2}e^{i5\pi/4} = -1-i$.

Les 4 solutions sont : $1+i,\ 1-i,\ -1+i,\ -1-i$.

*Vérification :* $(1+i)^4 = ((1+i)^2)^2 = (2i)^2 = -4$. Donc $(1+i)^4 + 4 = 0$. ✓

---

## 📌 Tableau récapitulatif — Réflexes pour les partiels

### Algèbre 1

| Type de question | Réflexe |
|-----------------|---------|
| $A = B$ | Double inclusion |
| Contradiction pour $\neg P$ | Absurde |
| Récurrence | Init + Hérédité proprement rédigées |
| $f$ surjective | Montrer $\forall y, \exists x, f(x)=y$ (souvent par TVI pour fonctions continues) |
| $f$ injective | Montrer $f(x)=f(x') \Rightarrow x=x'$ |

### Algèbre 2 — Nombres complexes

| Type de question | Réflexe |
|-----------------|---------|
| Mettre $z$ sous forme polaire | $r = \|z\|$, $\theta = \text{Arg}(z)$ |
| Résoudre $z^n = a$ | Forme polaire $a = re^{i\theta}$, solutions $r^{1/n}e^{i(\theta+2k\pi)/n}$ |
| Résoudre $az^2+bz+c=0$ | Discriminant $\Delta$, racine carrée complexe si $\Delta \in \mathbb{C}$ |
| Formules trig | Moivre : $(\cos\theta+i\sin\theta)^n$ |

### Algèbre 2 — Algèbre linéaire

| Type de question | Réflexe |
|-----------------|---------|
| Montrer $F$ sev | $0 \in F$, stable $+$, stable $\cdot$ |
| Famille libre ? | Résoudre $\sum\lambda_i v_i=0$, montrer $\lambda_i=0$ |
| $\dim(\text{Ker}f)$ | Résoudre $f(x)=0$, compter les param. libres |
| $\dim(\text{Im}f)$ | Théorème du rang : $\dim E - \dim\text{Ker}f$ |
| $f$ bijective si même dim | Injective $\Leftrightarrow$ surjective $\Leftrightarrow$ bijective |
| Inverser une matrice | Gauss-Jordan sur $[A|I]$ |


# 📝 Exercices avec Corrections Détaillées — Algèbre 1 & 2
### L1 Informatique — Institut Galilée

> Corrections pas-à-pas, calquées sur les TD réels et les types d'exercices des partiels.

---

# PARTIE 1 — ALGÈBRE 1

---

## 🔵 Thème 1 : Ensembles et opérations

### Exercice 1.1 — Opérations sur les ensembles
Soit $E$ un ensemble et $A, B, C \subset E$. Montrer :

1. $(A \cup B) \cap C = (A \cap C) \cup (B \cap C)$
2. $\overline{A \cup B} = \overline{A} \cap \overline{B}$ (De Morgan)
3. Si $A \subset B$ et $B \subset C$, alors $A \subset C$

<details>
<summary><strong>✅ Correction complète</strong></summary>

**1. Distributivité.**

Il faut montrer que les deux ensembles ont les mêmes éléments, donc la double inclusion.

*$\subset$ :* Soit $x \in (A \cup B) \cap C$.
Alors $x \in A \cup B$ (donc $x \in A$ ou $x \in B$) **et** $x \in C$.
- Si $x \in A$ : alors $x \in A$ et $x \in C$, donc $x \in A \cap C \subset (A \cap C) \cup (B \cap C)$.
- Si $x \in B$ : alors $x \in B$ et $x \in C$, donc $x \in B \cap C \subset (A \cap C) \cup (B \cap C)$.

*$\supset$ :* Soit $x \in (A \cap C) \cup (B \cap C)$.
- Si $x \in A \cap C$ : alors $x \in A \subset A \cup B$ et $x \in C$, donc $x \in (A \cup B) \cap C$.
- Si $x \in B \cap C$ : de même.

Les deux inclusions sont prouvées. $\blacksquare$

**2. De Morgan.**

*$\subset$ :* Soit $x \in \overline{A \cup B}$. Alors $x \notin A \cup B$, donc $x \notin A$ **et** $x \notin B$, donc $x \in \overline{A}$ et $x \in \overline{B}$, donc $x \in \overline{A} \cap \overline{B}$.

*$\supset$ :* Soit $x \in \overline{A} \cap \overline{B}$. Alors $x \notin A$ et $x \notin B$, donc $x \notin A \cup B$, donc $x \in \overline{A \cup B}$.

Conclusion : $\overline{A \cup B} = \overline{A} \cap \overline{B}$. $\blacksquare$

**3. Transitivité.**

Soit $x \in A$. Comme $A \subset B$, on a $x \in B$. Comme $B \subset C$, on a $x \in C$. Donc $A \subset C$. $\blacksquare$

</details>

---

### Exercice 1.2 — Images directes et réciproques
Soit $f : X \to Y$ et $A, B \subset X$, $S, T \subset Y$. Montrer :

1. $f(A \cup B) = f(A) \cup f(B)$
2. $f(A \cap B) \subset f(A) \cap f(B)$ (inclusion stricte possible)
3. $f^{-1}(S \cap T) = f^{-1}(S) \cap f^{-1}(T)$

<details>
<summary><strong>✅ Correction complète</strong></summary>

**1.** Soit $y \in f(A \cup B)$. Alors $\exists x \in A \cup B$ tel que $y = f(x)$.
- Si $x \in A$ : $y = f(x) \in f(A)$.
- Si $x \in B$ : $y = f(x) \in f(B)$.
Donc $y \in f(A) \cup f(B)$.

Réciproquement : si $y \in f(A)$, alors $\exists x \in A \subset A \cup B$ avec $y = f(x)$, donc $y \in f(A \cup B)$. De même pour $f(B)$.

**2.** Soit $y \in f(A \cap B)$. Alors $\exists x \in A \cap B$ avec $y = f(x)$. Comme $x \in A$, $y \in f(A)$. Comme $x \in B$, $y \in f(B)$. Donc $y \in f(A) \cap f(B)$.

*Contre-exemple pour l'égalité :* Soit $f : \{1,2\} \to \{1\}$ définie par $f(1)=f(2)=1$. Prenons $A = \{1\}$ et $B = \{2\}$. Alors $A \cap B = \emptyset$ donc $f(A \cap B) = \emptyset$, mais $f(A) \cap f(B) = \{1\} \cap \{1\} = \{1\} \neq \emptyset$.

**3.** Soit $x \in f^{-1}(S \cap T)$. Alors $f(x) \in S \cap T$, donc $f(x) \in S$ et $f(x) \in T$, donc $x \in f^{-1}(S)$ et $x \in f^{-1}(T)$, donc $x \in f^{-1}(S) \cap f^{-1}(T)$.

La réciproque est immédiate. $\blacksquare$

</details>

---

## 🔵 Thème 2 : Logique et quantificateurs

### Exercice 2.1 — Négations
Écrire la négation de chacune des propositions suivantes :

1. $\forall x \in \mathbb{R},\ x^2 \geq 0$
2. $\exists n \in \mathbb{N},\ n^2 = 2$
3. $\forall \varepsilon > 0,\ \exists N \in \mathbb{N},\ \forall n \geq N,\ |u_n - \ell| < \varepsilon$
4. $\forall x \in [0,1],\ f(x) \leq M$

<details>
<summary><strong>✅ Correction complète</strong></summary>

**1.** Négation : $\exists x \in \mathbb{R},\ x^2 < 0$. (Fausse.)

**2.** Négation : $\forall n \in \mathbb{N},\ n^2 \neq 2$. (Vraie.)

**3.** Négation de la définition de limite : $\exists \varepsilon > 0,\ \forall N \in \mathbb{N},\ \exists n \geq N,\ |u_n - \ell| \geq \varepsilon$.

*Méthode :* nier de gauche à droite en remplaçant $\forall$ par $\exists$ et $\exists$ par $\forall$, et en niant la proposition atomique finale.

**4.** Négation : $\exists x \in [0,1],\ f(x) > M$.

</details>

---

## 🔵 Thème 3 : Injections, surjections, bijections

### Exercice 3.1 (type partiel Algèbre 1)
Soit $f : \mathbb{R} \to \mathbb{R}$ définie par $f(x) = \frac{2x}{1+x^2}$.

1. $f$ est-elle surjective ?
2. $f$ est-elle injective ?
3. Restreindre le domaine et/ou le codomaine pour obtenir une bijection.

<details>
<summary><strong>✅ Correction complète</strong></summary>

**1. Surjectivité.**

Il faudrait que $\forall y \in \mathbb{R}$, l'équation $f(x) = y$ ait une solution.

$f(x) = y \Leftrightarrow \frac{2x}{1+x^2} = y \Leftrightarrow yx^2 - 2x + y = 0$.

- Si $y = 0$ : $-2x = 0 \Rightarrow x = 0$. Solution existe.
- Si $y \neq 0$ : équation du second degré. Discriminant $\Delta = 4 - 4y^2 = 4(1-y^2)$.
  - $\Delta \geq 0 \Leftrightarrow |y| \leq 1$.

Donc pour $|y| > 1$, il n'y a pas de solution. **$f$ n'est pas surjective** de $\mathbb{R}$ dans $\mathbb{R}$.

L'image de $f$ est $f(\mathbb{R}) = [-1, 1]$.

**2. Injectivité.**

$f(1) = \frac{2}{2} = 1$ et $f(-1) = \frac{-2}{2} = -1$. On a $f(1) \neq f(-1)$.

Mais $f(2) = \frac{4}{5}$ et regardons si une autre valeur donne $4/5$ : $\frac{4}{5}x^2 - 2x + \frac{4}{5} = 0 \Rightarrow 4x^2 - 10x + 4 = 0 \Rightarrow x = 2$ ou $x = 1/2$.

Donc $f(2) = f(1/2) = 4/5$ avec $2 \neq 1/2$. **$f$ n'est pas injective.**

**3. Bijection.**

$f$ est dérivable : $f'(x) = \frac{2(1+x^2) - 2x \cdot 2x}{(1+x^2)^2} = \frac{2(1-x^2)}{(1+x^2)^2}$.

$f'(x) > 0 \Leftrightarrow x^2 < 1 \Leftrightarrow x \in ]-1, 1[$.

Donc $f$ est strictement croissante sur $[-1, 1]$ et $f([-1,1]) = [-1, 1]$ (car $f(-1) = -1$, $f(0) = 0$, $f(1) = 1$).

$f : [-1, 1] \to [-1, 1]$ est une **bijection**. $\blacksquare$

</details>

---

## 🔵 Thème 4 : Récurrence

### Exercice 4.1 — Récurrences classiques
Démontrer par récurrence :

1. $\sum_{k=0}^n k = \frac{n(n+1)}{2}$
2. $\forall n \geq 1,\ 2^n > n$
3. **Binôme de Newton :** $(a+b)^n = \sum_{k=0}^n \binom{n}{k} a^k b^{n-k}$

<details>
<summary><strong>✅ Correction complète</strong></summary>

**1.** Notons $P(n) : \sum_{k=0}^n k = \frac{n(n+1)}{2}$.

*Initialisation :* $P(0) : \sum_{k=0}^0 k = 0 = \frac{0 \cdot 1}{2}$. ✓

*Hérédité :* Supposons $P(n)$ vraie. Alors :
$$\sum_{k=0}^{n+1} k = \sum_{k=0}^n k + (n+1) = \frac{n(n+1)}{2} + (n+1) = (n+1)\left(\frac{n}{2}+1\right) = \frac{(n+1)(n+2)}{2}$$
C'est bien $P(n+1)$. $\blacksquare$

**2.** Notons $P(n) : 2^n > n$ pour $n \geq 1$.

*Initialisation :* $P(1) : 2^1 = 2 > 1$. ✓

*Hérédité :* Supposons $2^n > n$. Alors :
$$2^{n+1} = 2 \cdot 2^n > 2n = n + n \geq n + 1$$
(car $n \geq 1 \Rightarrow n \geq 1$). Donc $P(n+1)$. $\blacksquare$

**3.** Notons $P(n) : (a+b)^n = \sum_{k=0}^n \binom{n}{k} a^k b^{n-k}$.

*Initialisation :* $P(0) : (a+b)^0 = 1 = \binom{0}{0}a^0 b^0$. ✓

*Hérédité :* Supposons $P(n)$. Alors :
$$\begin{align}
(a+b)^{n+1} &= (a+b)(a+b)^n = (a+b)\sum_{k=0}^n \binom{n}{k}a^k b^{n-k} \\
&= \sum_{k=0}^n \binom{n}{k}a^{k+1}b^{n-k} + \sum_{k=0}^n \binom{n}{k}a^k b^{n+1-k}
\end{align}$$

En réindexant la première somme ($j = k+1$) :
$$= \sum_{j=1}^{n+1}\binom{n}{j-1}a^j b^{n+1-j} + \sum_{j=0}^n\binom{n}{j}a^j b^{n+1-j}$$

$$= a^{n+1} + \sum_{j=1}^n\left[\binom{n}{j-1}+\binom{n}{j}\right]a^j b^{n+1-j} + b^{n+1}$$

Par la formule de Pascal $\binom{n}{j-1}+\binom{n}{j} = \binom{n+1}{j}$ :
$$= \binom{n+1}{0}b^{n+1} + \sum_{j=1}^n\binom{n+1}{j}a^j b^{n+1-j} + \binom{n+1}{n+1}a^{n+1} = \sum_{k=0}^{n+1}\binom{n+1}{k}a^k b^{n+1-k}$$

C'est bien $P(n+1)$. $\blacksquare$

</details>

---

## 🔵 Thème 5 : Combinatoire

### Exercice 5.1
1. Combien y a-t-il d'anagrammes du mot "MATHS" ?
2. Combien de sous-comités de 3 personnes peut-on former parmi 10 personnes ?
3. Combien y a-t-il de fonctions de $\{1,2,3\}$ dans $\{a,b,c,d\}$ ? De bijections ?

<details>
<summary><strong>✅ Correction complète</strong></summary>

**1.** "MATHS" a 5 lettres toutes distinctes. Le nombre d'arrangements est $5! = 120$.

**2.** Un sous-comité non ordonné de 3 parmi 10 : $\binom{10}{3} = \frac{10!}{3! \cdot 7!} = \frac{10 \times 9 \times 8}{3 \times 2 \times 1} = 120$.

**3.** Fonctions quelconques : pour chaque élément de $\{1,2,3\}$, on a 4 choix d'image. Total : $4^3 = 64$.

Bijections : impossible car $|\{1,2,3\}| = 3 < 4 = |\{a,b,c,d\}|$. Une injection est possible mais pas de bijection. Le nombre d'injections est $4 \times 3 \times 2 = 24$ (choix décroissants).

</details>

---

---

# PARTIE 2 — ALGÈBRE 2

---

## 🟡 Thème 1 : Nombres complexes

### Exercice A.1 — Calculs fondamentaux
Calculer et mettre sous forme algébrique $a + bi$ :

1. $(2+3i)(4-7i)$
2. $\frac{1-2i}{2+3i}$
3. $(1+i)^{10}$
4. Les racines carrées de $3 - 4i$

<details>
<summary><strong>✅ Correction complète</strong></summary>

**1.** $(2+3i)(4-7i) = 8 - 14i + 12i - 21i^2 = 8 - 2i + 21 = 29 - 2i$.

**2.** Multiplier par le conjugué du dénominateur :
$$\frac{1-2i}{2+3i} = \frac{(1-2i)(2-3i)}{(2+3i)(2-3i)} = \frac{2 - 3i - 4i + 6i^2}{4 + 9} = \frac{2 - 7i - 6}{13} = \frac{-4 - 7i}{13} = -\frac{4}{13} - \frac{7}{13}i$$

**3.** Forme polaire de $1+i$ : $|1+i| = \sqrt{2}$, $\text{Arg}(1+i) = \pi/4$.
Donc $1 + i = \sqrt{2}\, e^{i\pi/4}$.
$$(1+i)^{10} = (\sqrt{2})^{10} e^{i \cdot 10\pi/4} = 2^5 e^{i \cdot 5\pi/2} = 32 e^{i(\pi/2 + 2\pi)} = 32 e^{i\pi/2} = 32i$$

**4.** Cherchons $z = a+bi$ tel que $z^2 = 3 - 4i$.
Système :
$$a^2 - b^2 = 3 \qquad (1)$$
$$2ab = -4 \Rightarrow ab = -2 \qquad (2)$$
$$a^2 + b^2 = |3-4i| = \sqrt{9+16} = 5 \qquad (3)$$

De $(1) + (3)$ : $2a^2 = 8 \Rightarrow a^2 = 4 \Rightarrow a = \pm 2$.
De $(2)$ : si $a = 2$ alors $b = -1$ ; si $a = -2$ alors $b = 1$.

Les deux racines carrées sont $\boxed{2 - i}$ et $\boxed{-2 + i}$.

*Vérification :* $(2-i)^2 = 4 - 4i + i^2 = 4 - 4i - 1 = 3 - 4i$. ✓

</details>

---

### Exercice A.2 — Racines de l'unité et racines $n$-ièmes (type partiel)
1. Trouver toutes les racines cubiques de $-8$.
2. Résoudre $z^4 + 1 = 0$.
3. Montrer que $\sum_{k=0}^{n-1} e^{2ik\pi/n} = 0$ pour $n \geq 2$.

<details>
<summary><strong>✅ Correction complète</strong></summary>

**1.** On cherche les solutions de $z^3 = -8$.

$-8 = 8 e^{i\pi}$. Les solutions sont $z_k = 8^{1/3} e^{i(\pi + 2k\pi)/3} = 2 e^{i\pi(1+2k)/3}$ pour $k = 0, 1, 2$.

- $k=0$ : $z_0 = 2e^{i\pi/3} = 2(\cos(\pi/3) + i\sin(\pi/3)) = 2(1/2 + i\sqrt{3}/2) = 1 + i\sqrt{3}$
- $k=1$ : $z_1 = 2e^{i\pi} = -2$
- $k=2$ : $z_2 = 2e^{i5\pi/3} = 2(\cos(5\pi/3) + i\sin(5\pi/3)) = 2(1/2 - i\sqrt{3}/2) = 1 - i\sqrt{3}$

*Vérification :* $z_0 z_1 z_2 = (1+i\sqrt{3})(-2)(1-i\sqrt{3}) = -2(1+3) = -8$. ✓

**2.** $z^4 = -1 = e^{i\pi}$. Les solutions : $z_k = e^{i\pi(1+2k)/4}$ pour $k = 0, 1, 2, 3$.

- $k=0$ : $e^{i\pi/4} = \frac{\sqrt{2}}{2}(1+i)$
- $k=1$ : $e^{i3\pi/4} = \frac{\sqrt{2}}{2}(-1+i)$
- $k=2$ : $e^{i5\pi/4} = \frac{\sqrt{2}}{2}(-1-i)$
- $k=3$ : $e^{i7\pi/4} = \frac{\sqrt{2}}{2}(1-i)$

**3.** Posons $S = \sum_{k=0}^{n-1} \omega^k$ avec $\omega = e^{2i\pi/n}$.

C'est une somme géométrique de raison $\omega$ : $S = \frac{\omega^n - 1}{\omega - 1}$.

Or $\omega^n = e^{2i\pi} = 1$, donc $\omega^n - 1 = 0$.

Et $\omega \neq 1$ (car $n \geq 2$ et $2\pi/n \not\equiv 0 \pmod{2\pi}$), donc $\omega - 1 \neq 0$.

Donc $S = 0/(\omega - 1) = 0$. $\blacksquare$

</details>

---

### Exercice A.3 — Formules trigonométriques par les complexes
Exprimer $\cos(3\theta)$ et $\sin(3\theta)$ en fonction de $\cos\theta$ et $\sin\theta$.

<details>
<summary><strong>✅ Correction complète</strong></summary>

Par la formule de Moivre :
$$(\cos\theta + i\sin\theta)^3 = \cos(3\theta) + i\sin(3\theta)$$

En développant le membre gauche :
$$(\cos\theta + i\sin\theta)^3 = \cos^3\theta + 3\cos^2\theta \cdot i\sin\theta + 3\cos\theta \cdot (i\sin\theta)^2 + (i\sin\theta)^3$$
$$= \cos^3\theta + 3i\cos^2\theta\sin\theta - 3\cos\theta\sin^2\theta - i\sin^3\theta$$
$$= (\cos^3\theta - 3\cos\theta\sin^2\theta) + i(3\cos^2\theta\sin\theta - \sin^3\theta)$$

En identifiant parties réelle et imaginaire :
$$\cos(3\theta) = \cos^3\theta - 3\cos\theta\sin^2\theta = \cos^3\theta - 3\cos\theta(1-\cos^2\theta) = 4\cos^3\theta - 3\cos\theta$$
$$\sin(3\theta) = 3\cos^2\theta\sin\theta - \sin^3\theta = 3(1-\sin^2\theta)\sin\theta - \sin^3\theta = 3\sin\theta - 4\sin^3\theta \qquad \blacksquare$$

</details>

---

## 🟡 Thème 2 : Systèmes linéaires et pivot de Gauss

### Exercice B.1 — Résolution par Gauss
Résoudre le système :
$$\begin{cases} x + 2y - z = 3 \\ 2x - y + z = -1 \\ 3x + y + 2z = 4 \end{cases}$$

<details>
<summary><strong>✅ Correction complète</strong></summary>

**Matrice augmentée :**
$$\begin{pmatrix} 1 & 2 & -1 & | & 3 \\ 2 & -1 & 1 & | & -1 \\ 3 & 1 & 2 & | & 4 \end{pmatrix}$$

**Étape 1 :** $L_2 \leftarrow L_2 - 2L_1$ et $L_3 \leftarrow L_3 - 3L_1$ :
$$\begin{pmatrix} 1 & 2 & -1 & | & 3 \\ 0 & -5 & 3 & | & -7 \\ 0 & -5 & 5 & | & -5 \end{pmatrix}$$

**Étape 2 :** $L_3 \leftarrow L_3 - L_2$ :
$$\begin{pmatrix} 1 & 2 & -1 & | & 3 \\ 0 & -5 & 3 & | & -7 \\ 0 & 0 & 2 & | & 2 \end{pmatrix}$$

**Remontée :**
- $L_3$ : $2z = 2 \Rightarrow z = 1$
- $L_2$ : $-5y + 3 = -7 \Rightarrow -5y = -10 \Rightarrow y = 2$
- $L_1$ : $x + 4 - 1 = 3 \Rightarrow x = 0$

**Solution :** $(x, y, z) = (0, 2, 1)$.

*Vérification dans $L_3$ :* $3(0) + 2 + 2(1) = 4$. ✓

</details>

---

### Exercice B.2 — Système avec paramètre
Discuter selon $a \in \mathbb{R}$ le nombre de solutions du système :
$$\begin{cases} ax + y + z = 1 \\ x + ay + z = 1 \\ x + y + az = 1 \end{cases}$$

<details>
<summary><strong>✅ Correction complète</strong></summary>

**Déterminant de la matrice :**
$$A = \begin{pmatrix} a & 1 & 1 \\ 1 & a & 1 \\ 1 & 1 & a \end{pmatrix}$$

En développant : $\det(A) = a(a^2-1) - 1(a-1) + 1(1-a) = a^3 - a - a + 1 + 1 - a = a^3 - 3a + 2$.

Factorisons : on cherche les racines. $a=1$ : $1-3+2=0$. Donc $(a-1)$ divise.

$a^3 - 3a + 2 = (a-1)(a^2+a-2) = (a-1)(a-1)(a+2) = (a-1)^2(a+2)$.

**Cas $a \neq 1$ et $a \neq -2$** : $\det(A) \neq 0$. Solution unique (par Cramer) :

Par symétrie du système, on essaie $x = y = z = t$. Alors $at + t + t = 1 \Rightarrow t(a+2) = 1 \Rightarrow t = \frac{1}{a+2}$.

Solution unique : $\left(\frac{1}{a+2}, \frac{1}{a+2}, \frac{1}{a+2}\right)$.

**Cas $a = 1$** : Le système devient $x + y + z = 1$ (trois équations identiques). Infinité de solutions : $x + y + z = 1$ (plan affine). $\dim = 2$ paramètres libres.

**Cas $a = -2$** : Les équations donnent $-2x + y + z = 1$, $x - 2y + z = 1$, $x + y - 2z = 1$. Leur somme : $0 = 3$. **Contradiction !** Aucune solution.

**Conclusion :**
- $a \neq 1$ et $a \neq -2$ : une unique solution
- $a = 1$ : infinité de solutions (droite... non, plan : dimension 2)
- $a = -2$ : aucune solution

</details>

---

## 🟡 Thème 3 : Sous-espaces vectoriels

### Exercice C.1 — Reconnaissance de sev (type partiel !)
Dans $\mathbb{R}^3$, les sous-ensembles suivants sont-ils des sous-espaces vectoriels ?

1. $F_1 = \{(x,y,z) \in \mathbb{R}^3 \mid x + y - z = 0\}$
2. $F_2 = \{(x,y) \in \mathbb{R}^2 \mid x \geq 0 \text{ et } y \geq 0\}$
3. $F_3 = \{(x,y,z) \in \mathbb{R}^3 \mid xy = 0\}$
4. $F_4 = \{(x,y,z) \in \mathbb{R}^3 \mid x = 2z\}$

<details>
<summary><strong>✅ Correction complète</strong></summary>

**1. $F_1$ est un sev.**

- $0 \in F_1$ : $0 + 0 - 0 = 0$. ✓
- Stabilité addition : si $(x,y,z), (x',y',z') \in F_1$ (i.e., $x+y-z=0$ et $x'+y'-z'=0$), alors $(x+x') + (y+y') - (z+z') = (x+y-z) + (x'+y'-z') = 0$. ✓
- Stabilité scalaire : $\lambda(x+y-z) = 0$. ✓

**2. $F_2$ n'est pas un sev.**

$(1, 0) \in F_2$ (car $1 \geq 0, 0 \geq 0$). Mais $(-1)(1,0) = (-1, 0) \notin F_2$ (car $-1 < 0$). Pas stable par multiplication scalaire.

**3. $F_3$ n'est pas un sev.**

$(1, 0, 0) \in F_3$ (car $1 \times 0 = 0$) et $(0, 1, 0) \in F_3$ (car $0 \times 1 = 0$).

Mais $(1,0,0) + (0,1,0) = (1,1,0)$, et $1 \times 1 = 1 \neq 0$. Pas stable par addition.

**4. $F_4$ est un sev.**

$F_4 = \{(x,y,z) \mid x - 2z = 0\}$ est le noyau de l'application linéaire $(x,y,z) \mapsto x - 2z$. Tout noyau d'une application linéaire est un sev. $\blacksquare$

*Vérification directe :* $0 - 2 \times 0 = 0$ ✓. $\lambda(x - 2z) = 0$ ✓. $(x-2z) + (x'-2z') = 0$ ✓.

</details>

---

### Exercice C.2 — Familles libres/liées
Dans $\mathbb{R}^4$, la famille $\mathcal{F} = \{u_1, u_2, u_3\}$ avec $u_1 = (3,0,1,2)$, $u_2 = (1,5,0,-1)$, $u_3 = (7,5,2,1)$ est-elle libre ?

<details>
<summary><strong>✅ Correction complète</strong></summary>

On résout $\lambda_1 u_1 + \lambda_2 u_2 + \lambda_3 u_3 = 0$ :
$$\begin{cases} 3\lambda_1 + \lambda_2 + 7\lambda_3 = 0 \\ 5\lambda_2 + 5\lambda_3 = 0 \\ \lambda_1 + 2\lambda_3 = 0 \\ 2\lambda_1 - \lambda_2 + \lambda_3 = 0 \end{cases}$$

De la 2e équation : $\lambda_2 = -\lambda_3$.

De la 3e : $\lambda_1 = -2\lambda_3$.

Substituons dans la 1re : $3(-2\lambda_3) + (-\lambda_3) + 7\lambda_3 = -6\lambda_3 - \lambda_3 + 7\lambda_3 = 0$. ✓

Substituons dans la 4e : $2(-2\lambda_3) - (-\lambda_3) + \lambda_3 = -4\lambda_3 + \lambda_3 + \lambda_3 = -2\lambda_3$. Pour que ce soit $= 0$, il faut $\lambda_3 = 0$.

Donc $\lambda_3 = \lambda_2 = \lambda_1 = 0$. **La famille est libre.** $\blacksquare$

*Remarque :* $u_3 = 2u_1 + u_2$ (vérifier) — non, vérifions : $2(3,0,1,2) + (1,5,0,-1) = (7,5,2,3) \neq u_3 = (7,5,2,1)$. Donc $u_3$ n'est pas combinaison linéaire de $u_1, u_2$. La famille est bien libre.

</details>

---

## 🟡 Thème 4 : Dimension et théorème du rang

### Exercice D.1 — Applications linéaires (type partiel !)
Soit $f : \mathbb{R}^2 \to \mathbb{R}^3$ définie par $f(x,y) = (x+y, x-y, 2x)$.

1. Montrer que $f$ est linéaire.
2. Calculer $\text{Ker}(f)$ et $\dim(\text{Ker}(f))$.
3. Calculer $\text{Im}(f)$ et $\dim(\text{Im}(f))$.
4. Vérifier le théorème du rang.

<details>
<summary><strong>✅ Correction complète</strong></summary>

**1. Linéarité.**

$f(\lambda(x,y) + \mu(x',y')) = f(\lambda x + \mu x', \lambda y + \mu y')$
$= (\lambda x + \mu x' + \lambda y + \mu y', \lambda x + \mu x' - \lambda y - \mu y', 2\lambda x + 2\mu x')$
$= \lambda(x+y, x-y, 2x) + \mu(x'+y', x'-y', 2x')$
$= \lambda f(x,y) + \mu f(x',y')$. ✓

**2. Noyau.**

$f(x,y) = (0,0,0) \Leftrightarrow \begin{cases} x+y=0 \\ x-y=0 \\ 2x=0 \end{cases}$

De la 3e : $x = 0$. De la 1re : $y = -x = 0$. Donc $\text{Ker}(f) = \{(0,0)\}$.

$\dim(\text{Ker}(f)) = 0$ : $f$ est **injective**.

**3. Image.**

$\text{Im}(f) = \text{Vect}(f(1,0), f(0,1)) = \text{Vect}((1,1,2), (1,-1,0))$.

Ces deux vecteurs sont-ils libres ? Supposons $\lambda(1,1,2) + \mu(1,-1,0) = (0,0,0)$ :
$$\lambda + \mu = 0,\quad \lambda - \mu = 0 \Rightarrow \lambda = \mu = 0.$$

Donc $\text{Im}(f) = \text{Vect}((1,1,2),(1,-1,0))$, $\dim(\text{Im}(f)) = 2$.

**4. Théorème du rang.**

$\dim(\text{Ker}(f)) + \dim(\text{Im}(f)) = 0 + 2 = 2 = \dim(\mathbb{R}^2)$. ✓

</details>

---

### Exercice D.2 — Supplémentaires
Soit $E = \mathbb{R}^3$, $F = \{(x,y,z) \mid x+y-z = 0\}$ et $G = \text{Vect}((1,0,1))$.

1. Montrer que $F$ et $G$ sont des sev. Calculer leurs dimensions.
2. Montrer que $E = F \oplus G$.

<details>
<summary><strong>✅ Correction complète</strong></summary>

**1.** $F$ est le noyau de $(x,y,z) \mapsto x+y-z$ (linéaire), donc c'est un sev. $\dim F = 3 - 1 = 2$ (une équation de rang 1).

$G$ est engendré par un vecteur non nul, c'est une droite vectorielle. $\dim G = 1$.

**2.** Montrons $F \cap G = \{0\}$ et $F + G = \mathbb{R}^3$.

*Intersection :* Soit $v \in F \cap G$. Alors $v = t(1,0,1)$ pour un $t \in \mathbb{R}$, et $v \in F$ donc $t + 0 - t = 0$. Toujours vrai ! Mais attendons : $v = (t, 0, t)$ et la condition $F$ donne $t + 0 - t = 0$ pour tout $t$. Donc $F \cap G = G$ ?

Vérifions : $(1, 0, 1) \in F$ ? $1 + 0 - 1 = 0$. Oui ! Donc $(1,0,1) \in F \cap G$.

Donc $F \cap G = G \neq \{0\}$. $F$ et $G$ ne sont **pas** supplémentaires dans $\mathbb{R}^3$.

Prenons plutôt $G' = \text{Vect}((1,0,0))$.

$(1,0,0) \in F$ ? $1 + 0 - 0 = 1 \neq 0$. Donc $(1,0,0) \notin F$.

$F \cap G' = \{0\}$ (car si $t(1,0,0) \in F$ alors $t = 0$). ✓

$\dim F + \dim G' = 2 + 1 = 3 = \dim \mathbb{R}^3$. Par la formule de Grassmann, $\dim(F+G') = 3$. Donc $F + G' = \mathbb{R}^3$.

Conclusion : $\mathbb{R}^3 = F \oplus G'$. $\blacksquare$

</details>

---

## 🟡 Thème 5 : Matrices inversibles

### Exercice E.1 — Inversion par Gauss-Jordan
Inverser la matrice $A = \begin{pmatrix} 1 & 2 & 0 \\ 0 & 1 & 3 \\ 1 & 0 & 1 \end{pmatrix}$.

<details>
<summary><strong>✅ Correction complète</strong></summary>

Méthode : augmenter $[A | I_3]$ et réduire à $[I_3 | A^{-1}]$.

$$\left(\begin{array}{ccc|ccc} 1 & 2 & 0 & 1 & 0 & 0 \\ 0 & 1 & 3 & 0 & 1 & 0 \\ 1 & 0 & 1 & 0 & 0 & 1 \end{array}\right)$$

$L_3 \leftarrow L_3 - L_1$ :
$$\left(\begin{array}{ccc|ccc} 1 & 2 & 0 & 1 & 0 & 0 \\ 0 & 1 & 3 & 0 & 1 & 0 \\ 0 & -2 & 1 & -1 & 0 & 1 \end{array}\right)$$

$L_3 \leftarrow L_3 + 2L_2$ :
$$\left(\begin{array}{ccc|ccc} 1 & 2 & 0 & 1 & 0 & 0 \\ 0 & 1 & 3 & 0 & 1 & 0 \\ 0 & 0 & 7 & -1 & 2 & 1 \end{array}\right)$$

$L_3 \leftarrow L_3/7$ :
$$\left(\begin{array}{ccc|ccc} 1 & 2 & 0 & 1 & 0 & 0 \\ 0 & 1 & 3 & 0 & 1 & 0 \\ 0 & 0 & 1 & -1/7 & 2/7 & 1/7 \end{array}\right)$$

$L_2 \leftarrow L_2 - 3L_3$ :
$$\left(\begin{array}{ccc|ccc} 1 & 2 & 0 & 1 & 0 & 0 \\ 0 & 1 & 0 & 3/7 & 1/7 & -3/7 \\ 0 & 0 & 1 & -1/7 & 2/7 & 1/7 \end{array}\right)$$

$L_1 \leftarrow L_1 - 2L_2$ :
$$\left(\begin{array}{ccc|ccc} 1 & 0 & 0 & 1/7 & -2/7 & 6/7 \\ 0 & 1 & 0 & 3/7 & 1/7 & -3/7 \\ 0 & 0 & 1 & -1/7 & 2/7 & 1/7 \end{array}\right)$$

$$A^{-1} = \frac{1}{7}\begin{pmatrix} 1 & -2 & 6 \\ 3 & 1 & -3 \\ -1 & 2 & 1 \end{pmatrix}$$

*Vérification :* $AA^{-1} = I_3$ (à vérifier en multipliant). ✓

</details>


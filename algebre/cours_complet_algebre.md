# 📐 Cours Complet — Algèbre 1 & 2
### L1 Informatique — Institut Galilée, Université Paris 13
> Rédigé pour réussir les partiels. Algèbre 1 : structures ensemblistes & logique. Algèbre 2 : nombres complexes, algèbre linéaire.

---

# PARTIE 1 — ALGÈBRE 1 : Structures Mathématiques

---

## Chapitre 1 — Ensembles, sous-ensembles, éléments

### 1.1 Notions fondamentales

**Définition.** Un **ensemble** est une collection d'objets appelés **éléments**, avec la propriété que pour tout objet donné, l'assertion qu'il appartient à la collection est soit vraie, soit fausse.

**Notation.** $x \in E$ signifie "$x$ appartient à $E$". $x \notin E$ signifie "$x$ n'appartient pas à $E$".

**Ensembles de nombres.** $\mathbb{N} \subset \mathbb{Z} \subset \mathbb{Q} \subset \mathbb{R} \subset \mathbb{C}$.

**Ensemble vide.** Il existe un unique ensemble ne contenant aucun élément, noté $\emptyset$.

**Ensemble en extension.** $E = \{1, 2, 3, 4\}$ (liste des éléments).

**Ensemble en compréhension.** $E = \{x \in A \mid P(x)\}$ (éléments de $A$ vérifiant la propriété $P$).

**Singleton.** Ensemble contenant exactement un élément : $\{a\}$.

### 1.2 Inclusion et égalité

**Définition (inclusion).** $A \subset B$ si tout élément de $A$ est aussi un élément de $B$.
$$A \subset B \iff \forall x,\ (x \in A \Rightarrow x \in B)$$

**Inclusion stricte.** $A \subsetneq B$ si $A \subset B$ et $A \neq B$.

**Égalité.** $A = B$ si et seulement si $A \subset B$ **et** $B \subset A$ (double inclusion).

> ⚠️ **Méthode clé pour les partiels :** Pour prouver $A = B$, on prouve toujours la double inclusion : d'abord "$A \subset B$", puis "$B \subset A$".

**Proposition (transitivité).** Si $A \subset B$ et $B \subset C$, alors $A \subset C$.

**Remarque.** Pour tout ensemble $E$, on a $\emptyset \subset E$ et $E \subset E$.

### 1.3 Ensemble des parties

**Définition.** L'ensemble des **parties** (ou sous-ensembles) de $E$ est noté $\mathcal{P}(E)$.

**Exemple.** $\mathcal{P}(\{1,2\}) = \{\emptyset, \{1\}, \{2\}, \{1,2\}\}$. Si $|E| = n$ alors $|\mathcal{P}(E)| = 2^n$.

---

## Chapitre 2 — Opérations sur les ensembles et propositions

### 2.1 Opérations sur les ensembles

Soient $A, B \subset E$.

| Opération | Notation | Définition |
|-----------|----------|------------|
| **Union** | $A \cup B$ | $\{x \in E \mid x \in A \text{ ou } x \in B\}$ |
| **Intersection** | $A \cap B$ | $\{x \in E \mid x \in A \text{ et } x \in B\}$ |
| **Complémentaire** | $\overline{A}$ ou $E \setminus A$ | $\{x \in E \mid x \notin A\}$ |
| **Différence** | $A \setminus B$ | $\{x \in E \mid x \in A \text{ et } x \notin B\}$ |
| **Différence symétrique** | $A \triangle B$ | $(A \setminus B) \cup (B \setminus A)$ |

**Lois de De Morgan :**
$$\overline{A \cup B} = \overline{A} \cap \overline{B} \qquad \overline{A \cap B} = \overline{A} \cup \overline{B}$$

**Distributivité :**
$$A \cap (B \cup C) = (A \cap B) \cup (A \cap C)$$
$$A \cup (B \cap C) = (A \cup B) \cap (A \cup C)$$

### 2.2 Propositions logiques

**Définition.** Une **proposition** est une assertion qui est soit vraie (V), soit fausse (F). (Principe du tiers exclu.)

**Connecteurs logiques :**

| Connecteur | Notation | Lecture |
|-----------|----------|---------|
| Négation | $\neg P$ | "non $P$" |
| Conjonction | $P \wedge Q$ | "$P$ et $Q$" |
| Disjonction | $P \vee Q$ | "$P$ ou $Q$" |
| Implication | $P \Rightarrow Q$ | "si $P$ alors $Q$" |
| Équivalence | $P \Leftrightarrow Q$ | "$P$ si et seulement si $Q$" |

**Tables de vérité fondamentales :**

| $P$ | $Q$ | $P \wedge Q$ | $P \vee Q$ | $P \Rightarrow Q$ | $P \Leftrightarrow Q$ |
|-----|-----|------|------|------|------|
| V | V | V | V | V | V |
| V | F | F | V | F | F |
| F | V | F | V | V | F |
| F | F | F | F | V | V |

> ⚠️ $P \Rightarrow Q$ est **fausse uniquement** si $P$ vraie et $Q$ fausse.

**Contraposée.** $P \Rightarrow Q$ est équivalente à $\neg Q \Rightarrow \neg P$.

**Négation des connecteurs :**
$$\neg(P \wedge Q) \equiv \neg P \vee \neg Q \qquad \neg(P \vee Q) \equiv \neg P \wedge \neg Q$$
$$\neg(P \Rightarrow Q) \equiv P \wedge \neg Q$$

---

## Chapitre 3 — Les quantificateurs

**Quantificateur universel.** "$\forall x \in E,\ P(x)$" signifie "pour tout $x$ dans $E$, $P(x)$ est vraie."

**Quantificateur existentiel.** "$\exists x \in E,\ P(x)$" signifie "il existe au moins un $x$ dans $E$ tel que $P(x)$ est vraie."

**Négation des quantificateurs :**
$$\neg(\forall x \in E,\ P(x)) \equiv \exists x \in E,\ \neg P(x)$$
$$\neg(\exists x \in E,\ P(x)) \equiv \forall x \in E,\ \neg P(x)$$

**Ordre des quantificateurs.** L'ordre est **crucial** :
- $\forall m \in \mathbb{N},\ \exists k \in \mathbb{N},\ m < k$ (vrai : pour tout entier, il en existe un plus grand)
- $\exists k \in \mathbb{N},\ \forall m \in \mathbb{N},\ m < k$ (faux : il n'existe pas d'entier supérieur à tous les autres)

**Exemple type.** La définition de la limite $\lim_{n\to\infty} u_n = \ell$ :
$$\forall \varepsilon > 0,\ \exists N \in \mathbb{N},\ \forall n \geq N,\ |u_n - \ell| < \varepsilon$$

---

## Chapitre 4 — Types de démonstrations

### 4.1 Méthodes de preuve

**Preuve directe.** On suppose $P$ vraie et on déduit $Q$ par une chaîne d'implications.

**Preuve par contraposée.** Pour montrer $P \Rightarrow Q$, on montre $\neg Q \Rightarrow \neg P$.

**Preuve par l'absurde.** Pour montrer $P$, on suppose $\neg P$ et on aboutit à une contradiction.

**Preuve par cas.** On distingue tous les cas possibles et on prouve le résultat dans chacun.

**Preuve par équivalences successives.** $P \Leftrightarrow P_1 \Leftrightarrow P_2 \Leftrightarrow \cdots \Leftrightarrow Q$.

### 4.2 Démonstrations classiques

**$\sqrt{2}$ est irrationnel (absurde).** Supposons $\sqrt{2} = p/q$ avec $p, q \in \mathbb{Z}$, $q > 0$, $\gcd(p,q) = 1$. Alors $2q^2 = p^2$, donc $p^2$ est pair, donc $p$ est pair, donc $p = 2k$, donc $q^2 = 2k^2$, donc $q$ est pair. Contradiction avec $\gcd(p,q) = 1$.

---

## Chapitre 5 — Produit cartésien et relations

### 5.1 Produit cartésien

**Définition.** $A \times B = \{(a, b) \mid a \in A,\ b \in B\}$.

**Exemple.** $\{1,2\} \times \{a,b\} = \{(1,a),(1,b),(2,a),(2,b)\}$.

**Cardinal.** $|A \times B| = |A| \cdot |B|$.

### 5.2 Relations

**Définition.** Une **relation** sur $E$ est un sous-ensemble $R \subset E \times E$. On note $xRy$ si $(x,y) \in R$.

**Relation d'équivalence.** $R$ est une relation d'équivalence si elle est :
- **Réflexive :** $\forall x,\ xRx$
- **Symétrique :** $xRy \Rightarrow yRx$
- **Transitive :** $xRy$ et $yRz$ $\Rightarrow xRz$

**Classe d'équivalence.** $\bar{x} = \{y \in E \mid xRy\}$.

**Relation d'ordre.** $R$ est un **ordre** si elle est réflexive, **antisymétrique** ($xRy$ et $yRx$ $\Rightarrow x = y$) et transitive.

---

## Chapitre 6 — Les applications

### 6.1 Définitions

**Définition.** Une **application** (ou fonction) $f : A \to B$ associe à chaque élément $x \in A$ un unique élément $f(x) \in B$.

- $A$ : **ensemble de départ** (ou domaine)
- $B$ : **ensemble d'arrivée** (ou codomaine)
- $f(A) = \{f(x) \mid x \in A\}$ : **image** de $f$

**Image directe.** $f(S) = \{f(x) \mid x \in S\}$ pour $S \subset A$.

**Image réciproque.** $f^{-1}(T) = \{x \in A \mid f(x) \in T\}$ pour $T \subset B$.

**Propriétés importantes :**
- $f(S_1 \cup S_2) = f(S_1) \cup f(S_2)$ ✓
- $f(S_1 \cap S_2) \subset f(S_1) \cap f(S_2)$ (inclusion stricte possible)
- $f^{-1}(T_1 \cap T_2) = f^{-1}(T_1) \cap f^{-1}(T_2)$ ✓

---

## Chapitre 7 — Injections, surjections, bijections

**Définition (injection).** $f : A \to B$ est **injective** si :
$$\forall x, x' \in A,\ f(x) = f(x') \Rightarrow x = x'$$
Équivalent : $x \neq x' \Rightarrow f(x) \neq f(x')$.

**Définition (surjection).** $f : A \to B$ est **surjective** si :
$$\forall y \in B,\ \exists x \in A,\ f(x) = y$$
Équivalent : $f(A) = B$.

**Définition (bijection).** $f$ est **bijective** si elle est injective ET surjective. Chaque élément de $B$ a exactement un antécédent dans $A$.

**Application réciproque.** Si $f : A \to B$ est bijective, il existe une unique application $f^{-1} : B \to A$ telle que $f^{-1} \circ f = \text{id}_A$ et $f \circ f^{-1} = \text{id}_B$.

**Composition.** $(g \circ f)(x) = g(f(x))$.
- $f$ injective et $g$ injective $\Rightarrow g \circ f$ injective
- $f$ surjective et $g$ surjective $\Rightarrow g \circ f$ surjective

---

## Chapitre 8 — Récurrence et entiers naturels

### 8.1 Principe de récurrence

**Théorème (récurrence simple).** Soit $P(n)$ une propriété dépendant de $n \in \mathbb{N}$.
Si :
1. **Initialisation :** $P(0)$ est vraie
2. **Hérédité :** pour tout $n \in \mathbb{N}$, si $P(n)$ est vraie alors $P(n+1)$ est vraie

Alors $P(n)$ est vraie pour tout $n \in \mathbb{N}$.

**Récurrence forte.** Si $P(0)$ vraie et $\forall n$, $[P(0) \wedge \ldots \wedge P(n)] \Rightarrow P(n+1)$, alors $P(n)$ vraie pour tout $n$.

**Exemples fondamentaux :**
$$\sum_{k=1}^n k = \frac{n(n+1)}{2}, \qquad \sum_{k=1}^n k^2 = \frac{n(n+1)(2n+1)}{6}, \qquad \sum_{k=1}^n k^3 = \left(\frac{n(n+1)}{2}\right)^2$$

$$\sum_{k=0}^n x^k = \frac{x^{n+1}-1}{x-1} \text{ si } x \neq 1$$

---

## Chapitre 9 & 10 — Ensembles finis, cardinal et combinatoire

### 9.1 Cardinal

**Définition.** Le **cardinal** $|A|$ d'un ensemble fini $A$ est son nombre d'éléments.

**Formule d'inclusion-exclusion :**
$$|A \cup B| = |A| + |B| - |A \cap B|$$
$$|A \cup B \cup C| = |A| + |B| + |C| - |A \cap B| - |A \cap C| - |B \cap C| + |A \cap B \cap C|$$

### 10.1 Combinatoire

**Arrangements (ordonnés, sans répétition).** Nombre de façons de choisir $k$ éléments parmi $n$ en tenant compte de l'ordre :
$$A_n^k = \frac{n!}{(n-k)!}$$

**Combinaisons (non ordonnées).** Nombre de sous-ensembles de taille $k$ d'un ensemble de taille $n$ :
$$\binom{n}{k} = \frac{n!}{k!(n-k)!}$$

**Propriétés des coefficients binomiaux :**
- $\binom{n}{0} = \binom{n}{n} = 1$
- $\binom{n}{k} = \binom{n}{n-k}$
- **Formule de Pascal :** $\binom{n}{k} + \binom{n}{k+1} = \binom{n+1}{k+1}$
- **Binôme de Newton :** $(a+b)^n = \sum_{k=0}^n \binom{n}{k} a^k b^{n-k}$

---

## Chapitres 11 & 12 — Entiers relatifs, rationnels, réels

### 11.1 Division euclidienne

**Théorème.** Pour tous $a \in \mathbb{Z}$, $b \in \mathbb{Z}^*$, il existe un unique couple $(q, r)$ avec $0 \leq r < |b|$ tel que $a = bq + r$.

**PGCD.** Le plus grand commun diviseur de $a$ et $b$ est l'unique entier $> 0$ divisant à la fois $a$ et $b$ et divisé par tout diviseur commun.

**Algorithme d'Euclide.** $\gcd(a, b) = \gcd(b, r)$ où $r = a \mod b$.

**Théorème de Bézout.** $\gcd(a,b) = 1 \Leftrightarrow \exists u, v \in \mathbb{Z},\ au + bv = 1$.

**Lemme de Gauss.** Si $a \mid bc$ et $\gcd(a,b) = 1$, alors $a \mid c$.

**Théorème fondamental de l'arithmétique.** Tout entier $\geq 2$ s'écrit de façon unique (à l'ordre des facteurs près) comme produit de nombres premiers.

---

# PARTIE 2 — ALGÈBRE 2 : Algèbre Linéaire

---

## Chapitre I — Les Nombres Complexes

### I.1 Définitions et opérations

**Définition.** Un **nombre complexe** est une expression $z = a + bi$ avec $a, b \in \mathbb{R}$ et $i^2 = -1$.
- $\text{Re}(z) = a$ : **partie réelle**
- $\text{Im}(z) = b$ : **partie imaginaire**
- $\mathbb{C}$ : ensemble des nombres complexes

**Addition.** $(a+bi) + (a'+b'i) = (a+a') + (b+b')i$

**Multiplication.** $(a+bi)(a'+b'i) = (aa' - bb') + (ab' + a'b)i$

> **Astuce :** se rappeler $i^2 = -1$ et développer comme un polynôme.

**Division.** $\frac{z}{z'} = \frac{z \cdot \overline{z'}}{|z'|^2}$ (multiplier par le conjugué du dénominateur).

### I.2 Conjugué et module

**Conjugué.** $\overline{z} = \overline{a+bi} = a - bi$.

**Propriétés du conjugué :**
- $\overline{z + z'} = \overline{z} + \overline{z'}$
- $\overline{z \cdot z'} = \overline{z} \cdot \overline{z'}$
- $z \in \mathbb{R} \Leftrightarrow z = \overline{z}$
- $z \in i\mathbb{R} \Leftrightarrow z = -\overline{z}$
- $\text{Re}(z) = \frac{z + \overline{z}}{2}$, $\text{Im}(z) = \frac{z - \overline{z}}{2i}$

**Module.** $|z| = \sqrt{a^2 + b^2} = \sqrt{z \overline{z}}$.

**Propriétés du module :**
- $|zz'| = |z||z'|$
- $|z/z'| = |z|/|z'|$
- $|z + z'| \leq |z| + |z'|$ (inégalité triangulaire)
- $|z| = 0 \Leftrightarrow z = 0$

### I.3 Forme trigonométrique (polaire)

**Argument.** L'**argument** de $z \neq 0$ est l'angle orienté $\theta = \text{Arg}(z)$ entre l'axe réel positif et le vecteur $z$.

**Calcul de l'argument :**
- Si $\text{Re}(z) > 0$ : $\theta = \arctan\!\left(\frac{\text{Im}(z)}{\text{Re}(z)}\right)$
- Si $\text{Re}(z) < 0$ : $\theta = \arctan\!\left(\frac{\text{Im}(z)}{\text{Re}(z)}\right) + \pi$
- Si $\text{Re}(z) = 0$ et $\text{Im}(z) > 0$ : $\theta = \pi/2$

**Notation exponentielle.** $e^{i\theta} = \cos\theta + i\sin\theta$ (formule d'Euler).

**Forme polaire.** Tout $z \neq 0$ s'écrit $z = re^{i\theta}$ avec $r = |z| > 0$ et $\theta = \text{Arg}(z)$.

**Multiplication en forme polaire.** $re^{i\theta} \cdot r'e^{i\theta'} = rr'e^{i(\theta+\theta')}$

**Formule de Moivre.** $(e^{i\theta})^n = e^{in\theta}$, soit $(\cos\theta + i\sin\theta)^n = \cos(n\theta) + i\sin(n\theta)$.

### I.4 Racines et équations

**Racines $n$-ièmes de l'unité.** Les solutions de $z^n = 1$ sont les $n$ nombres :
$$\omega_k = e^{2ik\pi/n} = \cos\!\left(\frac{2k\pi}{n}\right) + i\sin\!\left(\frac{2k\pi}{n}\right), \quad k = 0, 1, \ldots, n-1$$

Ils forment les sommets d'un polygone régulier à $n$ côtés inscrit dans le cercle unité.

**Propriété.** La somme des racines $n$-ièmes de l'unité vaut $0$ (pour $n \geq 2$).

**Racines $n$-ièmes de $a \in \mathbb{C}^*$.** Si $a = re^{i\theta}$, les solutions de $z^n = a$ sont :
$$z_k = r^{1/n} e^{i(\theta/n + 2k\pi/n)}, \quad k = 0, 1, \ldots, n-1$$

**Équation du second degré.** $az^2 + bz + c = 0$ ($a \neq 0$). Discriminant $\Delta = b^2 - 4ac$.
- Si $\Delta = 0$ : une solution $z = -b/(2a)$
- Si $\Delta \neq 0$ : deux solutions $z = \frac{-b \pm \sqrt{\Delta}}{2a}$ (où $\sqrt{\Delta}$ est une racine carrée complexe de $\Delta$)

> **Attention :** dans $\mathbb{C}$, toute équation du second degré a toujours (au moins) une solution !

**Racines carrées d'un complexe.** Pour trouver $z^2 = u = \alpha + \beta i$, poser $z = a + bi$ et résoudre le système :
$$a^2 - b^2 = \alpha, \quad 2ab = \beta, \quad a^2 + b^2 = |u|$$

---

## Chapitre II — Systèmes Linéaires

### II.1 Définitions

**Équation linéaire.** $a_1 x_1 + a_2 x_2 + \cdots + a_n x_n = b$ avec $a_j, b \in \mathbb{K}$ ($\mathbb{K} = \mathbb{R}$ ou $\mathbb{C}$).

**Système linéaire.** Ensemble de $p$ équations linéaires à $n$ inconnues :
$$\begin{cases} a_{11}x_1 + a_{12}x_2 + \cdots + a_{1n}x_n = b_1 \\ a_{21}x_1 + a_{22}x_2 + \cdots + a_{2n}x_n = b_2 \\ \vdots \\ a_{p1}x_1 + a_{p2}x_2 + \cdots + a_{pn}x_n = b_p \end{cases}$$

**Système homogène.** Quand tous les $b_i = 0$. Toujours compatible (solution nulle).

### II.2 Méthode du pivot de Gauss

**Opérations élémentaires sur les lignes :**
- $L_i \leftarrow \lambda L_i$ ($\lambda \neq 0$) : multiplier une ligne par un scalaire non nul
- $L_i \leftarrow L_i + \lambda L_j$ : ajouter un multiple d'une ligne à une autre
- $L_i \leftrightarrow L_j$ : échanger deux lignes

Ces opérations **ne changent pas l'ensemble des solutions**.

**Forme échelonnée.** Une matrice est échelonnée si :
1. Les lignes nulles sont en bas
2. Dans deux lignes non nulles consécutives, la seconde a plus de zéros à gauche que la première

**Forme échelonnée réduite.** Échelonnée, avec de plus :
3. L'élément de tête de chaque ligne non nulle vaut 1
4. L'élément de tête est le seul coefficient non nul de sa colonne

**Algorithme de Gauss :**
1. Trouver le pivot (premier élément non nul de la colonne la plus à gauche)
2. Mettre des zéros en dessous du pivot
3. Passer à la sous-matrice inférieure
4. Remonter pour la forme réduite (Gauss-Jordan)

**Structure des solutions.** Si le système est compatible, l'ensemble des solutions est de la forme :
$$\{x_{\text{part}} + \text{Ker}(A)\}$$
où $x_{\text{part}}$ est une solution particulière et $\text{Ker}(A)$ est l'espace des solutions du système homogène associé. Le nombre de **variables libres** est $n - \text{rang}(A)$.

### II.3 Système de Cramer

Si le système est carré ($n = p$) et $\det(A) \neq 0$, il admet une unique solution :
$$x_j = \frac{\det(A_j)}{\det(A)}$$
où $A_j$ est la matrice $A$ dont la $j$-ème colonne est remplacée par le second membre.

---

## Chapitre III — Espaces et sous-espaces vectoriels

### III.1 Espace vectoriel

**Définition.** Un $\mathbb{K}$-espace vectoriel est un ensemble $E$ muni d'une addition $+$ et d'une multiplication scalaire $\cdot : \mathbb{K} \times E \to E$ satisfaisant 8 axiomes (commutativité, associativité, élément neutre $0_E$, opposés, distributivités, associativité mixte, $1 \cdot v = v$).

**Exemples :** $\mathbb{R}^n$, $\mathbb{C}^n$, $\mathbb{K}^n$, l'espace des matrices $M_{p,n}(\mathbb{K})$, l'espace des polynômes $\mathbb{K}[X]$, l'espace des fonctions continues sur $[a,b]$.

### III.2 Sous-espace vectoriel

**Définition.** Un sous-ensemble $F \subset E$ est un **sous-espace vectoriel (sev)** si :
1. $0_E \in F$
2. $\forall u, v \in F,\ u + v \in F$ (stable par addition)
3. $\forall \lambda \in \mathbb{K},\ \forall u \in F,\ \lambda u \in F$ (stable par multiplication scalaire)

**Critère compact.** $F$ est un sev $\Leftrightarrow$ $F \neq \emptyset$ et $\forall u, v \in F,\ \forall \lambda, \mu \in \mathbb{K},\ \lambda u + \mu v \in F$.

**Exemples de sev :**
- $\{0\}$ et $E$ (sev triviaux)
- Toute droite ou plan passant par l'origine dans $\mathbb{R}^n$
- $\text{Ker}(f)$ et $\text{Im}(f)$ pour $f$ linéaire
- L'ensemble des solutions d'un système homogène

### III.3 Familles de vecteurs

**Combinaison linéaire.** $v = \lambda_1 v_1 + \lambda_2 v_2 + \cdots + \lambda_k v_k$ avec $\lambda_i \in \mathbb{K}$.

**Sous-espace engendré.** $\text{Vect}(v_1, \ldots, v_k)$ = ensemble de toutes les combinaisons linéaires des $v_i$.

**Famille libre (linéairement indépendante).** $(v_1, \ldots, v_k)$ est libre si :
$$\lambda_1 v_1 + \lambda_2 v_2 + \cdots + \lambda_k v_k = 0 \Rightarrow \lambda_1 = \lambda_2 = \cdots = \lambda_k = 0$$

**Famille liée.** Non libre : l'un des vecteurs est combinaison linéaire des autres.

> 💡 **Méthode pour tester la liberté :** poser $\sum \lambda_i v_i = 0$, résoudre le système linéaire, et vérifier si la seule solution est $\lambda_i = 0$ pour tout $i$.

**Famille génératrice.** $(v_1, \ldots, v_k)$ est génératrice de $E$ si tout vecteur de $E$ est combinaison linéaire des $v_i$, i.e., $\text{Vect}(v_1, \ldots, v_k) = E$.

**Base.** Une famille à la fois **libre** et **génératrice**.

---

## Chapitre IV — Espaces vectoriels de dimension finie

### IV.1 Dimension

**Théorème.** Toutes les bases d'un espace vectoriel de dimension finie ont le même cardinal, appelé **dimension** de l'espace et noté $\dim E$.

**Dimensions usuelles :** $\dim \mathbb{K}^n = n$, $\dim M_{p,n}(\mathbb{K}) = pn$, $\dim \mathbb{K}_d[X] = d+1$.

**Théorème de la base incomplète.** Toute famille libre peut être complétée en une base.

### IV.2 Résultats fondamentaux

**Théorème.** Soit $E$ de dimension $n$ et $(v_1, \ldots, v_n)$ une famille de $n$ vecteurs :
$$\text{libre} \Leftrightarrow \text{génératrice} \Leftrightarrow \text{base}$$

(N'importe laquelle des trois conditions implique les deux autres, si on a exactement $n$ vecteurs !)

**Dimension d'un sev.** Si $F \subset E$, alors $\dim F \leq \dim E$. Égalité $\Leftrightarrow F = E$.

**Formule de Grassmann (dimension de la somme) :**
$$\dim(F + G) = \dim F + \dim G - \dim(F \cap G)$$

**Somme directe.** $F$ et $G$ sont en **somme directe** (notée $F \oplus G$) si $F \cap G = \{0\}$.
Dans ce cas : $\dim(F \oplus G) = \dim F + \dim G$.

**Sous-espaces supplémentaires.** $F$ et $G$ sont supplémentaires dans $E$ si $F + G = E$ et $F \cap G = \{0\}$, i.e., $E = F \oplus G$. Alors tout vecteur de $E$ s'écrit **de façon unique** comme $v = f + g$ avec $f \in F$ et $g \in G$.

---

## Chapitre V — Matrices

### V.1 Définitions et opérations

**Matrice.** Un tableau $A = (a_{ij})$ de taille $p \times n$ ($p$ lignes, $n$ colonnes).

**Addition.** $(A+B)_{ij} = a_{ij} + b_{ij}$ (même taille).

**Multiplication scalaire.** $(\lambda A)_{ij} = \lambda a_{ij}$.

**Produit matriciel.** $C = AB$ avec $A \in M_{p,n}$ et $B \in M_{n,q}$ : $c_{ij} = \sum_{k=1}^n a_{ik} b_{kj}$.

> ⚠️ Le produit matriciel est **non commutatif** en général : $AB \neq BA$.

**Matrices spéciales :**
- $I_n$ : matrice identité $n \times n$
- $0$ : matrice nulle
- $A^T$ : transposée ($a^T_{ij} = a_{ji}$)

### V.2 Matrices inversibles

**Définition.** $A \in M_n$ est **inversible** s'il existe $B$ tel que $AB = BA = I_n$. On note $B = A^{-1}$.

**Calcul de l'inverse.** Par la méthode de Gauss-Jordan : augmenter la matrice $[A | I_n]$ et réduire à $[I_n | A^{-1}]$.

**Déterminant.** $\det(A) \neq 0 \Leftrightarrow A$ est inversible.

**Formule pour $2 \times 2$ :**
$$A = \begin{pmatrix} a & b \\ c & d \end{pmatrix}, \quad \det(A) = ad - bc, \quad A^{-1} = \frac{1}{ad-bc}\begin{pmatrix} d & -b \\ -c & a \end{pmatrix}$$

**Règle de Sarrus (pour $3 \times 3$).** Développement par cofacteurs ou règle des diagonales.

### V.3 Rang d'une matrice

**Définition.** Le **rang** de $A$ est la dimension de l'espace engendré par les colonnes (ou par les lignes).

**Calcul.** Par l'échelonnement : $\text{rang}(A)$ = nombre de pivots dans la forme échelonnée.

**Propriété.** $\text{rang}(A) \leq \min(p, n)$. $A$ inversible $\Leftrightarrow \text{rang}(A) = n$ (pour $A$ carrée).

---

## Chapitre VI — Applications Linéaires

### VI.1 Définitions

**Définition.** $f : E \to F$ est **linéaire** si :
1. $\forall u, v \in E,\ f(u + v) = f(u) + f(v)$
2. $\forall \lambda \in \mathbb{K},\ \forall u \in E,\ f(\lambda u) = \lambda f(u)$

Équivalent : $f(\lambda u + \mu v) = \lambda f(u) + \mu f(v)$.

**Noyau.** $\text{Ker}(f) = \{u \in E \mid f(u) = 0\}$ — c'est un sev de $E$.

**Image.** $\text{Im}(f) = \{f(u) \mid u \in E\} = f(E)$ — c'est un sev de $F$.

**Injectivité.** $f$ injective $\Leftrightarrow \text{Ker}(f) = \{0\}$.

### VI.2 Théorème du rang

**Théorème (fondamental).** Si $E$ est de dimension finie :
$$\dim(\text{Ker}(f)) + \dim(\text{Im}(f)) = \dim E$$

**Corollaires :**
- Si $\dim E = \dim F$ : $f$ injective $\Leftrightarrow f$ surjective $\Leftrightarrow f$ bijective
- $\text{rang}(A) + \dim(\text{Ker}(A)) = n$ (nombre de colonnes)

### VI.3 Matrice d'une application linéaire

**Principe.** Si $\mathcal{B} = (e_1, \ldots, e_n)$ est une base de $E$ et $\mathcal{B}' = (f_1, \ldots, f_p)$ une base de $F$, la matrice de $f$ dans ces bases est la matrice $A$ dont la $j$-ème colonne contient les coordonnées de $f(e_j)$ dans $\mathcal{B}'$.

**Composition.** $\text{Mat}(g \circ f) = \text{Mat}(g) \cdot \text{Mat}(f)$.

**Changement de base.** Si $P$ est la matrice de changement de base ($P$ inversible), la nouvelle matrice est $P^{-1}AP$.

---

## Récapitulatif — Méthodes clés pour les partiels

### Boîte à outils Algèbre 1

| Problème | Réflexe |
|----------|---------|
| Prouver $A = B$ | Double inclusion |
| Montrer $\neg(\forall x, P(x))$ | Trouver un contre-exemple |
| Prouver $P \Rightarrow Q$ | Direct, contraposée, ou absurde |
| Montrer une propriété pour tout $n$ | Récurrence |
| Cardinal de $A \cup B$ | $|A| + |B| - |A \cap B|$ |
| Nombre de bijections $\{1,\ldots,n\} \to \{1,\ldots,n\}$ | $n!$ |

### Boîte à outils Algèbre 2

| Problème | Réflexe |
|----------|---------|
| Mettre $z$ sous forme polaire | Calculer $\|z\|$ et $\text{Arg}(z)$ |
| Résoudre $z^n = a$ | Forme polaire + racines |
| Résoudre $az^2+bz+c = 0$ | Discriminant $\Delta$, racine carrée complexe |
| Montrer $F$ est un sev | Vérifier $0 \in F$, stable $+$, stable $\cdot$ |
| Tester liberté d'une famille | Résoudre $\sum \lambda_i v_i = 0$ |
| Dimension d'un sev défini par équations | $n - \text{rang}(A)$ |
| Trouver base de $\text{Ker}(f)$ | Résoudre $Ax = 0$ par Gauss |
| Trouver base de $\text{Im}(f)$ | Colonnes formant une famille libre de $A$ |
| Théorème du rang | $\dim\text{Ker} + \dim\text{Im} = \dim E$ |
| Montrer $f$ bijective (même dim) | Montrer injective OU surjective |


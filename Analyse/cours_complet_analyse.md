# 📚 Cours Complet — Analyse 1 & 2
### L1 Informatique — Institut Galilée, Université Paris 13
> Rédigé pour réussir les partiels. Toutes les définitions, théorèmes et preuves essentielles sont ici.

---

# PARTIE 1 — ANALYSE 1

---

## Chapitre 1 — Les Nombres Réels

### 1.1 Majorants, minorants, borne supérieure, borne inférieure

**Définition.** Soit $A \subset \mathbb{R}$, $A \neq \emptyset$.
- $M$ est un **majorant** de $A$ si $\forall x \in A,\ x \leq M$.
- $m$ est un **minorant** de $A$ si $\forall x \in A,\ x \geq m$.
- $A$ est **majorée** s'il existe un majorant. **Minorée** s'il existe un minorant. **Bornée** si les deux.

**Définition (Borne supérieure).** Le plus petit des majorants de $A$, noté $\sup A$, est la **borne supérieure** de $A$.

> ⚠️ $\sup A$ n'appartient pas forcément à $A$ ! (ex : $\sup\, ]0,1[ = 1 \notin ]0,1[$)

**Théorème (axiome de la borne supérieure).** Toute partie non vide et majorée de $\mathbb{R}$ admet une borne supérieure.

**Caractérisation fondamentale.** $M = \sup A$ si et seulement si :
1. $M$ est un majorant de $A$
2. $\forall \varepsilon > 0,\ \exists x \in A$ tel que $x > M - \varepsilon$

**Exemple.** $A = \left\{2 + \frac{(-1)^n}{n},\ n \in \mathbb{N}^*\right\}$
- Les termes pairs sont $> 2$, les impairs sont $< 2$.
- $\sup A = 3$ (atteint pour $n=1$), $\inf A = 1$ (atteint pour $n=1$... non, analysons : pour $n=1$ on a $2 - 1 = 1$, pour $n=2$ on a $2 + 1/2 = 5/2$, ...). $\inf A = 1$.

**Propriété importante.** $\mathbb{Q}$ est **dense** dans $\mathbb{R}$ : tout intervalle $]x, y[$ (avec $x < y$) contient un rationnel. De même $\mathbb{R} \setminus \mathbb{Q}$ est dense dans $\mathbb{R}$.

---

### 1.2 Partie entière

**Définition.** Pour $x \in \mathbb{R}$, la **partie entière** $E(x) = \lfloor x \rfloor$ est l'unique entier vérifiant $E(x) \leq x < E(x) + 1$.

**Propriétés clés :**
- $E(x) \leq x < E(x)+1$
- $nE(x) \leq E(nx) < nE(x)+n$ pour $n \in \mathbb{N}^*$
- $E(E(x)/n) = E(x/n)$ (attention aux pièges)

---

## Chapitre 2 — Les Suites Réelles

### 2.1 Définitions fondamentales

**Définition (Limite).** On dit que la suite $(u_n)$ **converge vers $\ell \in \mathbb{R}$** si :
$$\forall \varepsilon > 0,\ \exists N \in \mathbb{N},\ \forall n \geq N,\ |u_n - \ell| < \varepsilon$$

**Définition (Suite bornée).** $(u_n)$ est bornée si $\exists M > 0,\ \forall n \in \mathbb{N},\ |u_n| \leq M$.

**Définition (Divergence vers $+\infty$).** $(u_n) \to +\infty$ si $\forall A > 0,\ \exists N,\ \forall n \geq N,\ u_n > A$.

**Théorème fondamental.** Toute suite **monotone et bornée** est convergente.

**Théorème des gendarmes.** Si $\forall n \geq N_0$, $a_n \leq u_n \leq b_n$ et $a_n \to \ell$, $b_n \to \ell$, alors $u_n \to \ell$.

### 2.2 Suites adjacentes

**Définition.** Deux suites $(u_n)$ et $(v_n)$ sont **adjacentes** si :
- l'une est croissante, l'autre est décroissante
- $v_n - u_n \to 0$

Alors elles convergent vers la même limite.

### 2.3 Suites récurrentes — méthode

Pour étudier $u_{n+1} = f(u_n)$ :
1. Trouver les points fixes de $f$ ($f(\ell) = \ell$)
2. Étudier la monotonie de $(u_n)$ en comparant $u_{n+1}$ et $u_n$
3. Montrer que la suite est bornée
4. Conclure par convergence monotone, puis identifier la limite en passant à la limite dans $u_{n+1} = f(u_n)$

**Exemple type (partiel 2023-2024).** $u_{n+1} = \frac{1}{2}u_n + 1$.
- Point fixe : $\ell = \frac{1}{2}\ell + 1 \Rightarrow \ell = 2$.
- Si $u_0 > 2$ : montrons $u_n > 2$ par récurrence, puis $u_{n+1} - u_n = \frac{1}{2}(u_n - 1) - u_n + 1 = -\frac{1}{2}(u_n - 2) < 0$ donc décroissante, bornée par 2, converge vers 2.
- La suite $(v_n = u_n - 2)$ est géométrique de raison $\frac{1}{2}$.

### 2.4 Calcul de limites

**Opérations usuelles.** Si $u_n \to \ell$ et $v_n \to m$ ($\ell, m \in \mathbb{R}$) :
- $u_n + v_n \to \ell + m$
- $u_n \cdot v_n \to \ell \cdot m$
- $u_n / v_n \to \ell/m$ si $m \neq 0$

**Formes indéterminées.** $\infty - \infty$, $0 \cdot \infty$, $\infty/\infty$, $0/0$ → factoriser, comparer les ordres.

**Exemple.** $\frac{n^2 + 4n + 2}{n^2 + n + 4} = \frac{1 + 4/n + 2/n^2}{1 + 1/n + 4/n^2} \to 1$.

**Règle de D'Alembert pour les suites.** Si $u_n > 0$ et $\frac{u_{n+1}}{u_n} \to a$ :
- $a < 1$ : $u_n \to 0$
- $a > 1$ : $u_n \to +\infty$
- $a = 1$ : indéterminé

---

## Chapitre 3 — Fonctions et Applications

### 3.1 Notions fondamentales

**Injectivité, surjectivité, bijectivité.**
- $f: X \to Y$ est **injective** si $f(x) = f(x') \Rightarrow x = x'$
- **surjective** si $\forall y \in Y,\ \exists x \in X,\ f(x) = y$
- **bijective** si injective ET surjective

**Image directe / image réciproque.**
- $f(A \cup B) = f(A) \cup f(B)$ ✓
- $f(A \cap B) \subseteq f(A) \cap f(B)$ (inclusion stricte possible si $f$ non injective)

**Parité.** $f$ paire si $f(-x) = f(x)$, impaire si $f(-x) = -f(x)$.

---

## Chapitre 4 — Limites de Fonctions

**Définition.** $\lim_{x \to a} f(x) = \ell$ si $\forall \varepsilon > 0,\ \exists \eta > 0,\ |x - a| < \eta \Rightarrow |f(x) - \ell| < \varepsilon$.

**Caractérisation séquentielle.** $\lim_{x \to a} f(x) = \ell$ si et seulement si pour toute suite $(x_n)$ vérifiant $x_n \to a$ (et $x_n \neq a$), on a $f(x_n) \to \ell$.

**Utilité.** Pour montrer qu'une limite **n'existe pas** : trouver deux suites $x_n \to a$ et $y_n \to a$ avec $f(x_n) \to \ell_1 \neq \ell_2 \leftarrow f(y_n)$.

**Théorème des gendarmes pour les fonctions.** Si $g(x) \leq f(x) \leq h(x)$ au voisinage de $a$ et $\lim_{x\to a} g(x) = \lim_{x \to a} h(x) = \ell$, alors $\lim_{x\to a} f(x) = \ell$.

---

## Chapitre 5 — Continuité et Dérivabilité

### 5.1 Continuité

**Définition.** $f$ est continue en $a$ si $\lim_{x \to a} f(x) = f(a)$.

**Théorème des valeurs intermédiaires (TVI).** Si $f$ est continue sur $[a,b]$ et $f(a) \cdot f(b) < 0$, alors $\exists c \in ]a,b[$ tel que $f(c) = 0$.

**Version générale.** Si $f$ est continue sur $[a,b]$ et $y$ est compris entre $f(a)$ et $f(b)$, alors $\exists c \in [a,b]$ tel que $f(c) = y$.

> 💡 **Application clé au partiel :** Pour montrer l'existence d'une solution à $f(x) = k$, on pose $g(x) = f(x) - k$ et on applique le TVI en trouvant $a, b$ tels que $g(a)$ et $g(b)$ sont de signes opposés.

**Théorème de Weierstrass.** Toute fonction continue sur un **fermé borné** $[a,b]$ est bornée et atteint ses bornes.

### 5.2 Dérivabilité

**Définition.** $f$ est dérivable en $x_0$ si $\lim_{x \to x_0} \frac{f(x) - f(x_0)}{x - x_0}$ existe et est finie. On la note $f'(x_0)$.

**Formulas de dérivation.**

| Fonction | Dérivée | Domaine |
|----------|---------|---------|
| $x^n$ | $nx^{n-1}$ | $\mathbb{R}$ |
| $e^x$ | $e^x$ | $\mathbb{R}$ |
| $\ln x$ | $1/x$ | $]0,+\infty[$ |
| $\sin x$ | $\cos x$ | $\mathbb{R}$ |
| $\cos x$ | $-\sin x$ | $\mathbb{R}$ |
| $\tan x$ | $1 + \tan^2 x = 1/\cos^2 x$ | $]-\pi/2+k\pi, \pi/2+k\pi[$ |
| $\arctan x$ | $\frac{1}{1+x^2}$ | $\mathbb{R}$ |
| $\arcsin x$ | $\frac{1}{\sqrt{1-x^2}}$ | $]-1,1[$ |
| $\arccos x$ | $-\frac{1}{\sqrt{1-x^2}}$ | $]-1,1[$ |
| $\sqrt{x}$ | $\frac{1}{2\sqrt{x}}$ | $]0,+\infty[$ |

**Règles.** $(uv)' = u'v + uv'$, $(u/v)' = (u'v - uv')/v^2$, $(f \circ g)' = (f' \circ g) \cdot g'$.

**Théorème de Rolle.** Si $f$ continue sur $[a,b]$, dérivable sur $]a,b[$ et $f(a) = f(b)$, alors $\exists c \in ]a,b[$ tel que $f'(c) = 0$.

**Théorème des accroissements finis (TAF).** Si $f$ continue sur $[a,b]$, dérivable sur $]a,b[$, alors $\exists c \in ]a,b[$ tel que :
$$f(b) - f(a) = f'(c)(b-a)$$

> 💡 **Usage au partiel :** Pour montrer une inégalité du type $|f(b)-f(a)| \leq M|b-a|$, appliquer le TAF puis majorer $|f'(c)|$.

**Corollaire (monotonie et dérivée).**
- $f' \geq 0$ sur $I$ $\Leftrightarrow$ $f$ croissante sur $I$
- $f' > 0$ sur $I$ $\Rightarrow$ $f$ strictement croissante

### 5.3 Fonctions réciproques

**Théorème.** Si $f: I \to J$ est bijective, de classe $C^1$, et $f'(x_0) \neq 0$, alors $f^{-1}$ est dérivable en $y_0 = f(x_0)$ et :
$$(f^{-1})'(y_0) = \frac{1}{f'(f^{-1}(y_0))}$$

**Exemples.**
- $(\arctan)'(x) = \frac{1}{1+x^2}$ (car $\tan' = 1 + \tan^2$)
- $(\arcsin)'(x) = \frac{1}{\sqrt{1-x^2}}$ (car $\sin' = \cos = \sqrt{1-\sin^2}$ sur $]-\pi/2, \pi/2[$)

**Propriétés des fonctions arc :**
- $\arcsin x + \arccos x = \pi/2$ pour $x \in [-1,1]$
- $\arctan x + \arctan(1/x) = \pi/2$ pour $x > 0$
- $\arcsin$ et $\arctan$ sont impaires

---

# PARTIE 2 — ANALYSE 2

---

## Chapitre 1 — Dérivées d'ordre supérieur

### 1.1 Dérivée seconde et convexité

**Définition.** $f$ est **deux fois dérivable** sur $I$ si $f'$ est dérivable sur $I$. On note $f'' = (f')'$.

**Définition (Convexité).** $f$ est **convexe** sur $I$ si pour tout $(x_1, x_2) \in I^2$ et tout $t \in [0,1]$ :
$$f(x_1 + t(x_2 - x_1)) \leq f(x_1) + t(f(x_2) - f(x_1))$$
Géométriquement : la courbe est **en dessous des cordes**.

**Remarque.** En particulier (avec $t = 1/2$) : $f\!\left(\frac{x_1+x_2}{2}\right) \leq \frac{f(x_1)+f(x_2)}{2}$ (inégalité de la moyenne arithmétique-géométrique).

**Théorème (lien convexité — dérivée seconde).**
- $f'' \geq 0$ sur $I$ $\Leftrightarrow$ $f$ convexe sur $I$
- $f'' \leq 0$ sur $I$ $\Leftrightarrow$ $f$ concave sur $I$

**Théorème (position courbe/tangente).** Si $f'' > 0$ sur $I$, la courbe est **au-dessus de toutes ses tangentes** sur $I$.

**Point d'inflexion.** Un point $(x_0, f(x_0))$ est un point d'inflexion si $f''$ s'annule **en changeant de signe** en $x_0$.

**Inégalités classiques issues de la convexité :**
- $\exp$ est convexe sur $\mathbb{R}$ → $\forall x \in \mathbb{R},\ e^x \geq 1 + x$
- $\sin$ est concave sur $[0, \pi/2]$ → $\forall x \in [0, \pi/2],\ \frac{2x}{\pi} \leq \sin x \leq x$
- $(1+x)^\alpha \geq 1 + \alpha x$ pour $\alpha > 1$ et $x > -1$ (inégalité de Bernoulli, $x \mapsto (1+x)^\alpha$ convexe)

---

### 1.2 Dérivées d'ordre $n$ et classes $C^n$

**Définition.** $f$ est **$n$ fois dérivable** sur $I$ si on peut définir $f^{(0)} = f$, $f^{(k)} = (f^{(k-1)})'$ pour $k = 1, \ldots, n$.

**Définition (Classe $C^n$).** $f$ est de **classe $C^n$** sur $I$ si $f$ est $n$ fois dérivable sur $I$ et $f^{(n)}$ est continue sur $I$.

**Définition (Classe $C^\infty$).** $f$ est de **classe $C^\infty$** (indéfiniment dérivable) si elle est $C^n$ pour tout $n \in \mathbb{N}$.

**Inclusions strictes :**
$$C^\infty \subset \cdots \subset C^2 \subset D^2 \subset C^1 \subset D^1 \subset C^0$$

> ⚠️ $C^n \subsetneq D^n$ ! On peut être $n$ fois dérivable sans être de classe $C^n$.

**Régularité des fonctions usuelles :** polynômes, $\sin$, $\cos$, $\exp$, $\ln$, $\tan$, $\arctan$ sont $C^\infty$ sur leur domaine de définition.

**Dérivées usuelles d'ordre $n$ :**
- $(\exp)^{(n)} = \exp$
- $(\sin)^{(2n)} = (-1)^n \sin$, $(\sin)^{(2n+1)} = (-1)^n \cos$
- $(x^\alpha)^{(n)} = \alpha(\alpha-1)\cdots(\alpha-n+1) x^{\alpha-n}$ pour $n \leq \lfloor\alpha\rfloor$ (ou $\alpha \notin \mathbb{N}$)
- Pour $P$ polynôme de degré $n$ : $P^{(n+1)} = 0$

---

### 1.3 Théorème des opérations et formule de Leibniz

**Théorème.** Si $f, g \in C^n(I)$ et $\alpha \in \mathbb{R}$ :
- $\alpha f + g \in C^n(I)$
- $f \cdot g \in C^n(I)$
- $f \circ g \in C^n(I)$ (si $g : I \to J$ et $f : J \to \mathbb{R}$, toutes deux $C^n$)
- $1/g \in C^n(I)$ si $g$ ne s'annule pas

**Formule de Leibniz.** Pour $f, g \in C^n(I)$ :
$$(f \cdot g)^{(n)} = \sum_{k=0}^{n} \binom{n}{k} f^{(k)} \cdot g^{(n-k)}$$

> 💡 C'est comme le binôme de Newton mais pour la dérivation.

**Coefficients binomiaux.** $\binom{n}{k} = \frac{n!}{k!(n-k)!}$. Relation de Pascal : $\binom{n}{k} + \binom{n}{k+1} = \binom{n+1}{k+1}$.

**Application type (partiel 2024).** $f(x) = (x^2 + x + 1)e^{-x}$.
- $g(x) = e^{-x}$ → $g^{(n)}(x) = (-1)^n e^{-x}$
- $h(x) = x^2 + x + 1$ → $h^{(0)} = x^2+x+1$, $h^{(1)} = 2x+1$, $h^{(2)} = 2$, $h^{(k)} = 0$ pour $k \geq 3$
- Par Leibniz : $f^{(n)}(x) = \sum_{k=0}^{\min(n,2)} \binom{n}{k} h^{(k)}(x) \cdot (-1)^{n-k} e^{-x}$

---

## Chapitre 2 — Intégration

### 2.1 Intégrale de Riemann

**Construction.** Pour $f$ continue sur $[a,b]$, on découpe en $n$ intervalles de longueur $(b-a)/n$ :
- **Somme de Darboux inférieure :** $S_n^-(f) = \frac{b-a}{n} \sum_{k=0}^{n-1} \min_{[a_k, a_{k+1}]} f$
- **Somme de Darboux supérieure :** $S_n^+(f) = \frac{b-a}{n} \sum_{k=0}^{n-1} \max_{[a_k, a_{k+1}]} f$
- **Somme de Riemann :** $S_n(f, u) = \frac{b-a}{n} \sum_{k=0}^{n-1} f(u_k)$ avec $u_k \in [a_k, a_{k+1}]$

On a toujours : $S_n^- \leq S_n \leq S_n^+$.

**Théorème.** Pour $f$ continue sur $[a,b]$, les trois suites convergent vers la même limite, appelée **intégrale de Riemann** :
$$\int_a^b f(t)\, dt$$

**Convergence des Darboux pour $f$ monotone :**
$$S_n^+ - S_n^- = \frac{(b-a)|f(b)-f(a)|}{n} \to 0$$

Pour $f$ de classe $C^1$ avec $M = \sup|f'|$ :
$$S_n^+ - S_n^- \leq \frac{M(b-a)^2}{n}$$

---

### 2.2 Propriétés de l'intégrale

| Propriété | Énoncé |
|-----------|--------|
| **Linéarité** | $\int_a^b (\lambda f + g) = \lambda \int_a^b f + \int_a^b g$ |
| **Positivité** | $f \geq 0$ sur $[a,b]$ $\Rightarrow$ $\int_a^b f \geq 0$ |
| **Monotonie** | $f \leq g$ sur $[a,b]$ $\Rightarrow$ $\int_a^b f \leq \int_a^b g$ |
| **Inégalité de la moyenne** | $m(b-a) \leq \int_a^b f \leq M(b-a)$ |
| **Relation de Chasles** | $\int_a^b f = \int_a^c f + \int_c^b f$ |
| **Inégalité triangulaire** | $\left|\int_a^b f\right| \leq \int_a^b |f|$ |

**Convention.** $\int_b^a f = -\int_a^b f$, $\int_a^a f = 0$.

**Théorème de la moyenne.** Si $f$ continue sur $[a,b]$, $\exists c \in [a,b]$ tel que $\frac{1}{b-a}\int_a^b f = f(c)$.

---

### 2.3 Primitives

**Définition.** $F$ est une **primitive** de $f$ sur $I$ si $F' = f$ sur $I$.

**Proposition.** Si $F$ est une primitive de $f$ sur $I$, les primitives de $f$ sont les $F + C$ ($C \in \mathbb{R}$).

**Primitives usuelles (table complète) :**

| $f(x)$ | Primitive $F(x)$ | Intervalle |
|--------|-----------------|------------|
| $x^n$ ($n \neq -1$) | $\frac{x^{n+1}}{n+1}$ | $\mathbb{R}$ (ou $]0,+\infty[$ si $n < 0$) |
| $\frac{1}{x}$ | $\ln|x|$ | $\mathbb{R}^*$ |
| $e^x$ | $e^x$ | $\mathbb{R}$ |
| $\sin x$ | $-\cos x$ | $\mathbb{R}$ |
| $\cos x$ | $\sin x$ | $\mathbb{R}$ |
| $\frac{1}{\cos^2 x}$ | $\tan x$ | $]-\pi/2+k\pi, \pi/2+k\pi[$ |
| $\tan x$ | $-\ln|\cos x|$ | $]-\pi/2+k\pi, \pi/2+k\pi[$ |
| $\frac{1}{1+x^2}$ | $\arctan x$ | $\mathbb{R}$ |
| $\frac{1}{\sqrt{1-x^2}}$ | $\arcsin x$ | $]-1,1[$ |
| $\frac{1}{\sqrt{x^2+1}}$ | $\ln(x + \sqrt{x^2+1})$ | $\mathbb{R}$ |
| $\frac{1}{\sqrt{x^2-1}}$ | $\ln|x + \sqrt{x^2-1}|$ | $]-\infty,-1[\cup]1,+\infty[$ |

---

### 2.4 Théorème fondamental du calcul intégral

**Théorème (TFA).** Soit $f$ continue sur $I$ et $a \in I$. La fonction $\Phi(x) = \int_a^x f(t)\, dt$ est dérivable sur $I$ et $\Phi' = f$.

> C'est l'**unique** primitive de $f$ sur $I$ qui s'annule en $a$.

**Corollaire.** Si $F$ est une primitive de $f$ continue sur $[a,b]$ :
$$\int_a^b f(t)\, dt = [F(x)]_a^b = F(b) - F(a)$$

**Application.** $\ln x = \int_1^x \frac{dt}{t}$ (définition du logarithme).

---

### 2.5 Méthodes de calcul

**Intégration par parties (IPP).** Si $u, v$ de classe $C^1$ sur $[a,b]$ :
$$\int_a^b u'(t) v(t)\, dt = [u(t)v(t)]_a^b - \int_a^b u(t) v'(t)\, dt$$

**Mémo IPP :** on choisit $u'$ = facile à primitiver, $v$ = facile à dériver.
- $\int x e^x\, dx$ : $u' = e^x$, $v = x$ → $u = e^x$, $v' = 1$
- $\int \ln x\, dx$ : $u' = 1$, $v = \ln x$ → $u = x$, $v' = 1/x$
- $\int x^n \ln x\, dx$ : $u' = x^n$, $v = \ln x$

**Changement de variable.** Si $\phi : [\alpha, \beta] \to [a, b]$ de classe $C^1$ et $f$ continue :
$$\int_a^b f(t)\, dt = \int_\alpha^\beta f(\phi(s)) \phi'(s)\, ds$$

**Stratégie :** poser $t = \phi(s)$, calculer $dt = \phi'(s)\, ds$, changer les bornes.

**Exemples classiques de changements de variable :**
- $\sqrt{1-x^2}$ → poser $x = \sin\theta$
- $\sqrt{x^2+1}$ → poser $x = \tan\theta$ ou $x = \sinh\theta$
- $\int_0^1 f(\sqrt{x})\, dx$ → poser $x = u^2$, $dx = 2u\, du$

---

### 2.6 Formule de Taylor avec reste intégral

**Théorème (Taylor-Laplace).** Si $f \in C^{n+1}([a, x])$ :
$$f(x) = \sum_{k=0}^{n} \frac{f^{(k)}(a)}{k!}(x-a)^k + \int_a^x \frac{(x-t)^n}{n!} f^{(n+1)}(t)\, dt$$

Le dernier terme est le **reste intégral de Laplace** $R_n(x)$.

**Cas $n=0$ (formule de la moyenne) :** $f(x) = f(a) + \int_a^x f'(t)\, dt$

**Inégalité sur le reste.** Si $|f^{(n+1)}| \leq M$ sur $[a, x]$ :
$$|R_n(x)| \leq M \frac{|x-a|^{n+1}}{(n+1)!}$$

---

## Chapitre 3 — Développements Limités

### 3.1 Définition et premières propriétés

**Définition.** $f$ admet un **développement limité à l'ordre $n$ en $a$** (noté DL$_n(a)$) s'il existe des réels $a_0, a_1, \ldots, a_n$ tels que :
$$f(a+h) = a_0 + a_1 h + a_2 h^2 + \cdots + a_n h^n + o(h^n) \quad \text{quand } h \to 0$$

**Notation $o$.** $f = o(g)$ en $a$ signifie $\lim_{x \to a} f(x)/g(x) = 0$.

**Unicité.** Le DL est unique.

**Formule de Taylor-Young.** Si $f \in C^n$ au voisinage de $a$ :
$$f(a + h) = \sum_{k=0}^n \frac{f^{(k)}(a)}{k!} h^k + o(h^n)$$

**Translation.** Pour un DL en 0, on remplace $x$ par $x - a$ pour obtenir un DL en $a$.

---

### 3.2 DL usuels en 0

$$e^x = 1 + x + \frac{x^2}{2!} + \frac{x^3}{3!} + \cdots + \frac{x^n}{n!} + o(x^n)$$

$$\sin x = x - \frac{x^3}{3!} + \frac{x^5}{5!} - \cdots + \frac{(-1)^n x^{2n+1}}{(2n+1)!} + o(x^{2n+2})$$

$$\cos x = 1 - \frac{x^2}{2!} + \frac{x^4}{4!} - \cdots + \frac{(-1)^n x^{2n}}{(2n)!} + o(x^{2n+1})$$

$$\ln(1+x) = x - \frac{x^2}{2} + \frac{x^3}{3} - \cdots + \frac{(-1)^{n-1}x^n}{n} + o(x^n)$$

$$(1+x)^\alpha = 1 + \alpha x + \frac{\alpha(\alpha-1)}{2!}x^2 + \cdots + \frac{\alpha(\alpha-1)\cdots(\alpha-n+1)}{n!}x^n + o(x^n)$$

$$\frac{1}{1-x} = 1 + x + x^2 + \cdots + x^n + o(x^n)$$

$$\frac{1}{1+x} = 1 - x + x^2 - \cdots + (-1)^n x^n + o(x^n)$$

$$\arctan x = x - \frac{x^3}{3} + \frac{x^5}{5} - \cdots + \frac{(-1)^n x^{2n+1}}{2n+1} + o(x^{2n+2})$$

$$\arcsin x = x + \frac{x^3}{6} + \frac{3x^5}{40} + o(x^5)$$

$$\sh x = x + \frac{x^3}{6} + \frac{x^5}{120} + o(x^5) \qquad \ch x = 1 + \frac{x^2}{2} + \frac{x^4}{24} + o(x^4)$$

---

### 3.3 Opérations sur les DL

**Troncature.** Si $f = \sum_{k=0}^n a_k x^k + o(x^n)$, le DL à l'ordre $p < n$ est obtenu en gardant les termes de degré $\leq p$.

**Somme et produit.** On additionne/multiplie les polynômes, puis on tronque à l'ordre voulu.

**Substitution.** Si $f$ a un DL en 0 et $u(x) = ax^p + o(x^p)$, on substitue $u(x)$ dans le DL de $f$ et on garde les termes jusqu'à l'ordre voulu.

**Intégration.** Si $f(x) = a_0 + a_1 x + \cdots + a_n x^n + o(x^n)$, alors :
$$\int_0^x f(t)\, dt = a_0 x + \frac{a_1 x^2}{2} + \cdots + \frac{a_n x^{n+1}}{n+1} + o(x^{n+1})$$

**Division (quotient).** Pour calculer le DL de $f/g$, on peut utiliser la division selon les puissances croissantes ou écrire $f = g \cdot q$ et identifier les coefficients.

**Composition.** Remplacer dans le DL de $f$ la variable par le DL de $g$, et tronquer.

**⚠️ Erreur classique.** Dans $e^{u(x)}$, si $u(x) = x^2 - x^3 + o(x^3)$, calculer $e^{u(x)}$ en développant $e^u = 1 + u + u^2/2 + \cdots$ en substituant.

---

### 3.4 Applications des DL

**Calcul de limites.** Notamment les formes $0/0$ ou $\infty - \infty$.

**Exemple.** $\lim_{x \to 0} \frac{\sin x - x}{x^3}$ :
$$\sin x = x - \frac{x^3}{6} + o(x^3) \Rightarrow \frac{\sin x - x}{x^3} = \frac{-x^3/6 + o(x^3)}{x^3} = -\frac{1}{6} + o(1) \to -\frac{1}{6}$$

**Position courbe/tangente.** La tangente en $x_0$ est $T(x) = f(x_0) + f'(x_0)(x-x_0)$. Le DL de $f(x) - T(x)$ donne la position :
- Premier terme non nul de degré pair et positif → minimum local
- Premier terme non nul de degré pair et négatif → maximum local
- Premier terme non nul de degré impair → point d'inflexion

**Développements asymptotiques.** Pour étudier le comportement en $+\infty$, on factorise par la puissance dominante.

**Exemple.** $f(x) = \sqrt{x^2 + x} = x\sqrt{1 + 1/x}$. En posant $u = 1/x \to 0^+$ :
$$\sqrt{1+u} = 1 + \frac{u}{2} - \frac{u^2}{8} + o(u^2) \Rightarrow f(x) = x + \frac{1}{2} - \frac{1}{8x} + o(1/x)$$
Asymptote oblique : $y = x + 1/2$.

---

## Récapitulatif — Méthodes clés pour les partiels

### Boîte à outils Analyse 1

| Problème | Méthode |
|----------|---------|
| Montrer $\sup A = M$ | Vérifier (i) $M$ majorant, (ii) $\forall \varepsilon, \exists x \in A, x > M-\varepsilon$ |
| Convergence d'une suite récurrente | Monotonie + borné → limite = point fixe |
| Limite n'existe pas | Trouver 2 sous-suites de limites différentes |
| Existence d'un zéro | TVI sur $g = f - k$ |
| Inégalité $\|f(b)-f(a)\| \leq M\|b-a\|$ | TAF + $\|f'\| \leq M$ |
| $f$ bijective | Montrer strictement monotone + $f(I) = J$ |

### Boîte à outils Analyse 2

| Problème | Méthode |
|----------|---------|
| Montrer une inégalité par convexité | Trouver $f'' \geq 0$, appliquer Thm 2 |
| Calculer $f^{(n)}$ | Leibniz si produit, récurrence, formule directe |
| Calculer $\int f$ | Primitives usuelles, IPP, changement de variable |
| Limite avec DL | Développer au bon ordre, simplifier |
| Asymptote oblique en $\pm\infty$ | Développement asymptotique (factoriser + DL) |
| Montrer $f \in C^n$ | Composition/produit de $C^n$ + théorème des opérations |


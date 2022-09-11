# La trigonométrie.

*L'idée de base est de chercher à comprendre un peu mieux comment son liées les longueurs et les angles dans un triangle.*

## A - Une grosse introduction

### 1 - Les triangles semblables

Un premier bon réflexe est de faire un rappel sur les triangles semblables.

**Rappel vieux mais important :**

- **la somme des angles dans un triangle fait 180°.**


**Nouveauté du chapitre triangles semblables.**

- **Deux triangles sont semblables s'ils ont les trois mêmes angles.**
- **Deux triangles semblables ont des côtés deux à deux proportionnels.**

Ici, on découvre l'idée que dans un triangle la notion d'angle et de longueur sont en lien. Il y a une question de proportionnalité. On peut passer d'une longueur à une autre en multipliant toujours par un même nombre.

### 2 - Le triangle rectangle.

On pourrait le faire pour tous les triangles (au programme de première ou term), mais pour que ça soit plus simple, on va juste se concentrer sur les triangles rectangles. On peut visualise cette idée assez simplement :

![triangles](https://raw.githubusercontent.com/homeostasie/petits-pedestres/master/2022.d/trigo.d/triangles.png)

Ici le côté [BC] est plus petit que [BD] et de même [AC] est plus petit que [AD]... et ça, c'est à cause de l'angle en A, BÂD qui est plus grand que celui BÂC.

En lien avec les rappels; Comme on a un angle droit (=90°) dès qu'on connaît un angle de plus, on peut calculer le troisième angle.

**ex1 : Calculer les angles dans un triangle.**


### 3 - La proportionnalité

L'idée de départ de la trigo (un peu dur à prouver simplement) :

Si on a un triangle rectangle et qu'on connaît un angle et un côté, alors on va pouvoir calculer les autres côtés. On a besoin de trouver ce *"cœfficient"* qui me permet de *"jongler"* entre les côtés.

La question est comment avoir ce cœfficient... Ben, on a un peu de chance parce que des gens se sont un peu cassés la tête à ça avant... Avant, on nous donnait des tables sur papier, voir pour les plus riches une règle à calculer.

![tables](https://raw.githubusercontent.com/homeostasie/petits-pedestres/master/2022.d/trigo.d/table.png)

![règles](https://raw.githubusercontent.com/homeostasie/petits-pedestres/master/2022.d/trigo.d/regle.jpg)

### 4 - Les cœfficients 

Il reste deux questions : 

1. Comment avoir ce cœfficient ?
2. Comment l'appliquer ?


#### Calculer le cœfficient

Maintenant on a un peu de chance, on a la calculatrice. La calculatrice permet de calculer directement ces cœfficients. On s'assure que la calculatrice est en mode degré (mesure d'angle et un petit d affiché en haut de l'écran.)

Par exemple, dans ce triangle rectangle avec un angle de 30° (et l'autre de 60°) et un grand côté qui fait 10cm.

![reciproque](https://raw.githubusercontent.com/homeostasie/petits-pedestres/master/2022.d/trigo.d/tria1.png)

* Le côté du dessous fait **10 × cos(30) = 8,66cm**.
* Le côté de gauche fait **10 × sin(30) = 5cm**.

L'idée est que la calculatrice va nous donner ces cœfficients en fonction de l'angle qu'on précise.

cos(30) pour un angle de 30°. Si l'angle avait été 48°, on calcule cos(48)

Ici, c'est bien de manipuler un peu ces calculs de cœfficients avant de vraiment rentrer dans les exercices un peu plus dur. 

On reste dans cette configuration de triangle et on change un peu la longueur du grand côté et l'angle.

**ex2 - calculer des cœfficients**

* Si le grand côté mesure 12 et l'angle 45°
    * le côté du dessous mesure : **12 × cos(45)**
    * le côté de gauche mesure  : **12 × sin(45)**


Si pas trop allergique à la proportionnalité, on peut marquer cette phrase : 

**Dans un triangle rectangle, si on connaît le grand côté : l'hypoténuse, alors on peut calculer les deux autres avec un cœfficient de réduction qui dépend de l'angle.**


#### Le vocabulaire

On va devoir se sensibiliser au fait que les notations "grand côté, petit côté, côté du haut, du bas, de gauche, de droite" ne sont pas satisfaisante. 

On introduit le vocabulaire.

Dans un triangle rectangle, si on marque un angle, on peut nommer les trois côtés : 

* **Hypoténuse** : le grand côté, en face de l'angle droit.
* **Adjacent** : le côté entre l'angle droit et l'angle marqué.
* **opposé** : le côté opposé à l'angle marqué.


**ex3 : Repérer le nom mathématiques des côtés dans des triangles rectangles.**

On peut reprendre l'exercice 2 avec plus de précision.

**adj = hyp × cos(angle)**
**opp = hyp × sin(angle)**

Il faut essayer de bien insister sur le fait que 

* **$\cos(angle)$ est le cœfficient qui permet de calculer le côté adjacent à partir de l'hypoténuse.**
* **$\sin(angle)$ est le cœfficient qui permet de calculer le côté opposé à partir de l'hypoténuse.**

Et si déjà on arrive à ce point, alors la trigonométrie est comprise. Maintenant, il reste à réussir à l'appliquer tout le temps et rapidement.

## B - On rentre dans le chapitre

Pour s'en sortir en trigonométrie, il faut des pré-requis : 

* **La somme des angles dans un triangle fait 180°.**
* **Savoir repérer : l'hypoténuse, l'opposé et l'adjacent dans un triangle rectangle avec un angle marqué.**

Ensuite il faut accepter l'objectif de base : 

**Dans un triangle rectangle, à partir d'un angle et d'un côté, je vais pouvoir calculer les deux autres côtés.**

Pour faire tout ça, on a besoin de trois formules : les 3 coeff qui dépendent des angles : 

* **cosinus**
* **sinus**
* **tangente**

* **adj = hyp × cos(angle)**
* **opp = hyp × sin(angle)**
* **opp = adj × tan(angle)**

Un problème :  il est assez dur d'apprendre ces trois formules dans ce sens. Il est souvent plus simple de retenir les formules avec les quotients.

* **cos = adj / hyp**
* **sin = opp / hyp**
* **tan = opp / adj**

Il y a deux phrases mnémotechniques pour les retenir : 

* **CAH SOH TOA** (une sorte de *casse-o-toi*)
* **SOH CAH TOA** 

La difficulté est vraiment, vraiment maintenant. Parce qu'on doit adapté nos envies et nos connaissances. Il ne faut pas partir que "le côté que je cherche est égal à celui que je connais fois le coeff".

Parce qu'à partir d'une définition, je vais pouvoir calculer de deux manières.

**cos = adj / hyp** => **adj = hyp × cos(angle)** ET **hyp = adj / cos(angle)**
**sin = opp / hyp** => **opp = hyp × sin(angle)** ET **hyp = opp / sin(angle)**
**tan = opp / adj** => **opp = adj × tan(angle)** ET **adj = opp × tan(angle)**

Là, la stratégie est de se poser les questions : 

**"Qu'est-ce que j'ai ?" et "Qu'est-ce que je veux ?"

**ex4 : Modéliser : "je vais utiliser".**


**ex5 : l'exo type ; on donne une longueur et un angle et on demande les autres longueurs**






## C - Dans l'autre sens.

Souvent quand ça marche bien dans un sens, on se pose toujours la question de savoir si on ne pourrait pas s'en servir dans l'autre. (ex réciproque de Pythagore) L'idée de base ici est que si on nous donne un triangle rectangle avec deux longueurs (et pas seulement une), alors on va pouvoir calculer les angles de ce triangle.

### À partir des coeff

* Dans l'idée si je peux connaître le coefficient à partir de l'angle : **sin(30) = 0.5** 

* J'ai envie de dire que si je connais le coefficient alors je dois aussi pouvoir connaître l'angle : **30 = arcsin(0.5)**.


Les trois fonctions réciproques : **arccos**, **arcsin**, **arctan** sont accessibles via la calculatrice. On demande à la calculatrice : *Je te donne le cœfficient : **cos**, **sin** ou **tan** et toi, tu me donnes l'angle.*. Souvent l'accès est avec la touche seconde ou shift puis la touche cos, sin et tan.

**ex6 : Calculer l'angle à partir du cœfficient.**

### À partir des côtés

C'est un peu plus dur, à partir des longueurs car il faut repartir des définitions.

En effet, comme : 

* **cos = adj / hyp**
* **sin = opp / hyp**
* **tan = opp / adj**

On peut facilement connaître la valeur d'un de ces cœfficients. Époque moderne, on se passe de table, la calculatrice va aussi pouvoir nous donner la valeur exacte de l'angle en fonction de la valeur du cœfficient.

![reciproque](https://raw.githubusercontent.com/homeostasie/petits-pedestres/master/2022.d/trigo.d/reciproque.png)

Ici, on connaît :

* **Hyp = 10cm**
* **Adj = 7cm**

Donc on peut calculer la valeur du cosinus

**cos = 6/10 = 0.6**

Pour connaître la valeur de l'angle, on utilise ce qu'on appelle la fonction réciproque. Attention à bien mettre les parenthèses : arccos(6/10 ne marche pas comme il faut.

**angle = arccos(6/10) = 53,13°**

**ex7 : Calculer l'angle à partir des longueurs.**


## D - Le paradis des problèmes

La trigonométrie est le paradis des problèmes parce qu'on peut mélanger des questions d'angles et des questions de longueurs. On a juste besoin d'un triangle rectangle... et c'est souvent le cas en math. Dès qu'on nous donne un triangle rectangle, une longueur et un angle, ça veut dire : *"probablement de la trigo."*
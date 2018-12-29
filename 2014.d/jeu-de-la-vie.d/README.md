# Le jeu de la vie.

> [ - Wikipédia -](http://fr.wikipedia.org/wiki/Jeu_de_la_vie) 
Le jeu de la vie imaginé par John Horton Conway en 1970 est un automate cellulaire. Le jeu se déroule sur un plateau dont les cases appelés cellules sont *vivantes* ou *mortes*. L’évolution des cellules est déterminée par l’état de ses huit voisines.

> * Une cellule morte possédant exactement trois voisines vivantes devient vivante (elle naît).
* Une cellule vivante possédant deux ou trois voisines vivantes le reste, sinon elle meurt.

## Organisation

* *Cellule* : Classe pour la cellule.
* *Plateau* : Classe pour le plateau et les règles de jeu.

## Utilisation

### Cellules
```c++
// Créer une cellule morte
Cellule cell_morte(0);
// Créer une cellule vivante
Cellule cell_vivante(1);
```

### Plateau
```c++
// Plateau carré de taille 3x3.
Plateau plateau_de_3(3);

// Évoluer une fois.
plateau_de_3.Evolution();

// Évoluer *n* fois.
plateau_de_3.Evolution(n);
```
### Affichage
```c++
// Afficher le plateau dans la sortie standart.
plateau_de_3.show();
// Afficher le plateau ainsi que les bords utiles pour le calcul. 
plateau_de_3.showTotal();
```


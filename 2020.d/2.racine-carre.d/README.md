# Collection

*Combien faut-il acheter de paquet de cartes afin de former une collection complète ?*

## mini-présentation

En voilà une question hautement pertinent pour les fans de carte panini, magic et même pour ceux qui se pose la question de l'intérêt d'acheter des boosters pour leur badge steam.

On va tenter d'apporter quelques éléments de réponses par le biais de la statistique en simulant un grand nombre d'achat et voir en combien de temps on peut espérer avoir enfin une collection complète.

On souhaite regarder le nombre d'achat nécéssaire de paquet de taille variable : **tailleLot** afin de compléter une collection de taille variable : **tailleCollection**.

## objectif

Le but est dans un premier temps d'attacher à regarder quelques nombres pour des valeurs remarquables puis de comparer un peu les résultats.


## langage : R - [(Lien)](http://www.r-project.org/)

### Éxecution 


* Windows à l'aide rgui
* Linux ou Mac à l'aide de la commannde dans le dossier racine du dépôt.

```
$ R -q --vanilla < collection-de-carte.R
```

### Méthodologie

#### Recueil

Le recueil de donnée reste aisé avec la plupart des langages de programmations capables de tirer des nombres uniformes entre 0 et 1. Nous avons fait ce tirage *(ligne 70)* à l'aide de la commande **runif(1)** sous R.

Pour récupérer des entiers uniformément distribué entre 1 et 70 , on multiplie notre uniforme par 70 et on lui rajoute 1 (pour éviter d'être entre 0 et 69) puis on passe ce décimal à la moulinette à l'aide de la fonction partie entière : **floor** pour en retirer en nombre entier.

Par exemple pour un tirage aléatoire d'un dé à six faces, on aurait fait **floor(6*runif(1)+1)**

#### Traitement

On se propose de regarder trois critères.

1. Le nombre d'achat nécéssaire pour compléter une collection.
2. Le nombre maximum d'une même carte par collection complète.
3. Le nombre moyen de carte par collection complète.

Les principales caractéristiques de position et de dispersion de notre première série : **Min**, **Q1**, **Médiane**, **Moyenne**, **Q3**, **Max** sont obtenues à l'aide de la fonction **summary()**. La redirection dans la sortie standard se fait à l'aide de **print()** sinon, la sortie est celle du prompt de R. *(ligne 131)*

```
> print(summary(dataCollection$nbrAchat))
   Min. 1st Qu.  Median    Mean 3rd Qu.    Max. 
  12.00   21.00   24.00   26.92   33.00   69.00 
```

La représentation choisie des différentes valeurs à été un histogramme des critères couplés à un boxplot en dessous afin de mieux visualiser les critères. L'export en pdf est réalisé à l'aide de la fonction **pdf(file="ton-nom-de-fichier.pdf")**.

On organise le fichier à l'aide de la fonction **par(fig=c(x_0, x_1, y_0, y_1))** qui place une image dans le rectangle suivant. 

![position rectangle]'https://github.com/homeostasie/Collection/raw/master/doc/traitement/position-image.pdf)

Afn d'agrandir un peu le boxplot, on le superpose un peu en hauteur vers l'histogramme. 0.5 > 0.3 et on finit l'histogramme en 0.9 afin d'avoir un graphique plus agréable. *(ligne 100)*


```
pdf(file="nombre-achats.pdf")
	
par(fig=c(0,1,0.3,.9), new=TRUE)
hist(dataCollection$nbrAchat, freq=FALSE,  col="grey",
	main="Nombre d'achats",
	xlab=NULL,
	ylab="Fréquence")
    	lines(density(dataCollection$nbrAchat), col="red")
par(fig=c(0,1,0,0.5), new=TRUE)
boxplot(dataCollection$nbrAchat, horizontal = TRUE, col="grey")
```

![Nombre d'achat](https://github.com/homeostasie/Collection/raw/master/doc/exemple/1-nombre-achats.pdf)


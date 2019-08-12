##################################################################################
#                                                                                #
#            Combien faut-il d'achat de carte pour finir une collection.         #
#                                                                                #
##################################################################################

####################
#
# 1 - Paramètres de la simulation

# La taille de la collection
# abrégé en TC dans les commentaires
tailleCollection = 90

# Le nombre de carte par lot lors de l'achat.
# abrégé en TL dans les commentaires
tailleLot = 2

# Le nombre de simulation total et les itérations succéssives
nbrSimulation = 5000
iteSimulation = 100


####################
# 2 - Structure du tableau de donnée

# A - dataCollection
# Tableau de données de notre simulation pour faire nos stats sur
# le nombre d'achat nécéssaire pour compléter une collection.
#
# dataCollection : 4 x nbrSimulation
# -- numSimulation : Le numéro de la simulation     - entier
# -- nbrAchat      : Le nombre d'achat nécéssaire   - entier
# -- maxDouble     : Le plus grand nombre de double - entier
# -- moyCarte      : Le nombre moyen de carte       - réel

dataCollection = data.frame(numSimulation=1:nbrSimulation, nbrAchat=0, 
	                    maxDouble=0, moyCarte = 0)

# B - aCollection
# Tableau de donnée par simulation recueillant l'ensemble des 
# cartes achetées.
#	
# aCollection : tableau de TCx2.
# -- numCarte : Numéro de carte        - entier (1 à TC).
# -- nbrCarte : Nombre de carte aquise -  entier.


####################
# 3 - Départ de la simulation

while(iteSimulation <= nbrSimulation)
{

	# initialisation de notre collection
	aCollection = data.frame(numCarte=1:tailleCollection, nbrCarte=0)

	# La collection est fini quand la somme du nombre de cartes 
 	# possédant au moins un exemplaire est égale à la taille de 
	# la collection
	while(sum(aCollection$nbrCarte!=0) != tailleCollection)
	{
		
		# Il y a TL cartes par paquet acheté
		ech=0
		while( ech < tailleLot )
		{
			# tirage : achat d'une carte au hasard parmi TC
			# sortie équiprobable d'un nombre entier de 1 à TC compris
			tirage = floor(tailleCollection*runif(1)+1)

			# On rajoute 1 au numéro de carte nouvellement aquis.
			aCollection$nbrCarte[tirage] = aCollection$nbrCarte[tirage] + 1 
			ech = ech +1	
		}
	}# La collection est complète

	# On récupère les données, on n'oublie pas la virgule pour 
	# intégrer les données sur la ligne et non dans la colonne
	dataCollection[iteSimulation,] = c(iteSimulation, 
				      sum(aCollection$nbrCarte),
				      max(aCollection$nbrCarte),
				      mean(aCollection$nbrCarte))

	# On passe à la simulation suivante
	iteSimulation = iteSimulation + 1

}# Le nombre de simulation est suffisant
# la simulation est terminé, on passe au traitement... 


####################
# 4 - Traitement des données

# Trois histogrammes et leur boxplot associé sont tracés
# - 1 - Le nombre d'achat de paquet à la fin d'une collection
# - 2 - Le plus grand nombre de double moyen à la fin d'une collection
# - 3 - Le nombre moyen de carte à la fin d'une collection 
pdf(file="1-nombre-achats.pdf")
	
	par(fig=c(0,1,0.3,.9), new=TRUE)
	hist(dataCollection$nbrAchat, freq=FALSE,  col="grey",
 		main="Nombre d'achats",
		xlab=NULL,
		ylab="Fréquence")
	    	lines(density(dataCollection$nbrAchat), col="red")
	par(fig=c(0,1,0,0.5), new=TRUE)
	boxplot(dataCollection$nbrAchat, horizontal = TRUE, col="grey")


pdf(file="2-maximum-doubles.pdf")
	par(fig=c(0,1,0.3,.9), new=TRUE)
	hist(dataCollection$maxDouble, freq=FALSE,  col="grey",
 		main="Maximum de doubles",
		xlab=NULL,
		ylab="Fréquence")
	    	lines(density(dataCollection$maxDouble), col="red")
	par(fig=c(0,1,0,0.5), new=TRUE)
	boxplot(dataCollection$maxDouble, horizontal = TRUE, col="grey")

pdf(file="3-moyenne-cartes.pdf")
	par(fig=c(0,1,0.3,.9), new=TRUE)
	hist(dataCollection$moyCarte, freq=FALSE,  col="grey",
 		main="Nombre moyen de cartes",
		xlab=NULL,
		ylab="Fréquence")
	    	lines(density(dataCollection$moyCarte), col="red")
	par(fig=c(0,1,0,0.5), new=TRUE)
	boxplot(dataCollection$moyCarte, horizontal = TRUE, col="grey")

# Quelques informations importantes concernant le nombre de paquets achetés sont 
# affichées dans la sortie standart : Min, Q1, Mediane, Moyenne, Q3, Max 
print(summary(dataCollection$nbrAchat))
print(summary(dataCollection$maxDouble))
print(summary(dataCollection$moyCarte))

	

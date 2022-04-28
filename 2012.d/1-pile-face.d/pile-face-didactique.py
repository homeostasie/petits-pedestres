#!/usr/bin/env python

# LABORATOIRE OUVERT LYONNAIS
# CONTRIBUTEURS
# - THOMAS

# LICENCE
# GPL v3

# Petite introduction à l'ia avec de l'adaptation et de la triche.
# pile-face-didactique se propose de suivre l'évolution du code sans pour autant la supprimer.
# C'est une bonne chose pour comprendre la démarche

# Importation des modules 
import random

# Structure du test de pile ou face simple et unique avec affichage

#if 0.25 <= 0.5:
#	print("pile")
#else:
#	print("face")

# Tirage aléatoire uniforme entre 0 et 1
# random.random()

#if random.random() < 0.5:
#	print("pile")
#else:
#	print("face")

# On structure en fonction

def pilefacesimple():
	if random.random() < 0.5:
		print("pile")
	else:
		print("face")

# On tente un appel
# pilefacesimple()
# It's works !

# On essaye alors plusieurs = maxtirage



def pilefacemax(maxtirage):

# Notre compteur de tirage qu'on initialise
	tirage = 0

	while ( tirage < maxtirage):
		if random.random() < 0.5:
			print("pile")
		else:
			print("face")
		tirage = tirage + 1

# On tente un appel pour vérifier le nombre de tirage
# pilefacemax(5)
# It's works


# On essage maintenant de biaiser le jeu

def pilefacebiais(biais, maxtirage):

	# Notre compteur de tirage qu'on initialise
	tirage = 0

	while ( tirage < maxtirage):
		# On rajoute le biais ici.
		# Si on est inférieux à se nombre alors pile
		# sinon face

		if random.random() < biais:
			print("pile")
		else:
			print("face")
		tirage = tirage + 1

# On tente un appel pour vérifier le nombre de tirage
# pilefacebiais(0.001, 5)
# It's works


# On améliore maintenant notre système en compartimentant
# la sortie et l'affichage.
# On écrit la sortie dans un fichier texte


def fpileface(biais, maxtirage):

	# Notre compteur de tirage qu'on initialise
	tirage = 0

	# Notre valeur de pile et face
	pile = 0
	face = 1
	# notre sortie=joute sous forme d'un fichier
	# avec une ligne par colonne

	# On ouvre en écriture un fichier (que l'on crée)
	joute = open("joute.csv","w")
	
	
	while ( tirage < maxtirage):
		

		if random.random() < biais:
			# on écrit dans le fichier et on saute une ligne
			joute.write("0\n")
		else:
			joute.write("1\n")
		tirage = tirage + 1
	# On ferme le fichier
	joute.close()

# Fonction qui affiche le résultat du lancer

def resulpileface(files):

	# On ouvre en lecture notre fichier passer en paramètre
	# On crée une liste de chaine de caractère avec nos réponses
	resulstring= open(files,"r").read().splitlines()
	
	# Notre pile de réponses
	resul = []

	tirage = 0
	maxtirage= len(resulstring)

	while tirage < maxtirage:
		
		# On rajoute notre valeur nouvelle entière en haut de la pile
		resul.append(int(resulstring[tirage]))
		tirage = tirage + 1

	#On imprime une première ligne informative
	print("-- RESULTAT --")
	print("0 = PILE -- 1 = FACE\n")
	
	print(resul)
	



fpileface(0.8,100000)
#resulpileface("joute.csv")


# On commence la notion de joueur.
# Ici le joueur va essayer de trouver la face sur laquelle la pièce va tomber.
# Pour se faire, il va devoir choisir entre pile ou face au départ,
# puis regarder le résultat et en fonction de ce dernier adapter sa stratégie

# Pour les joueurs suivants, il n'y a pas vraiment d'adaptation ni d'intéligence.
# Pour autant, c'est un bon point de départ.

# Soit le joueur 1 = j1_opt l'optimiste qui répond toujours pile = 1. 
# Soit le joueur 2 = j2_pes le péssimiste qui répond toujours face =0.
# Soit le joueur 3 = j3_haz qui répond au hasard avec une probabilité 0.5 

# Les joueurs suivants tentent de réfléchier un poil et utilisent leur mémoire,
# enfin la notre... ^^

# Soit le joueur 10 = j10-tout qui calcule à chaque pas la fréquence de pile et de face.
# ... il a un gros cerveau et va donc recopier la liste entier au fil du temps. 

def j1_opt(files):
	
	#On importe les résultats (sans pour autant les lire)

	# On ouvre en lecture notre fichier passer en paramètre

	resulstring= open(files,"r").read().splitlines()
	resul = []
	
	# le choix éffectué par j1
	j1_choix = []
	#j1_choix.append(0)

	# Le gain
	j1_gain = []

	tirage = 0
	maxtirage= len(resulstring)

	# Pourcentage de réussite
	j1_pour = 0

	while tirage < maxtirage:
		
		resul.append(int(resulstring[tirage]))
		j1_choix.append(0)
		
		if resul[tirage] - j1_choix[tirage] == 0:
			j1_gain.append(1)
			j1_pour = j1_pour + 1

		else:
			j1_gain.append(0)
		tirage = tirage + 1
	
#	print("\n")
#	print("-- J1 - l'optimiste --")
#	print(j1_choix)
	print("\n")
	print("j1 -- 1 = GAGNER -- 0 = PERDU \t % = ",j1_pour/maxtirage)
#	print(j1_gain)


j1_opt("joute.csv")


def j2_pes(files):
	
	#On importe les résultats (sans pour autant les lire)

	# On ouvre en lecture notre fichier passer en paramètre

	resulstring= open(files,"r").read().splitlines()
	resul = []
	
	# le choix éffectué par j1
	j2_choix = []
	#j1_choix.append(0)

	# Le gain
	j2_gain = []

	tirage = 0
	maxtirage= len(resulstring)

	j2_pour = 0

	while tirage < maxtirage:
		
		resul.append(int(resulstring[tirage]))
		j2_choix.append(1)
		
		if resul[tirage] - j2_choix[tirage] == 0:
			j2_gain.append(1)
			j2_pour = j2_pour + 1

		else:
			j2_gain.append(0)
		tirage = tirage + 1

#	print("\n")
#	print("-- J2 - le pessimiste --")
#	print(j2_choix)
	print("\n")
	print("j2 -- 1 = GAGNER -- 0 = PERDU \t % = ",j2_pour/maxtirage)
#	print(j2_gain)

j2_pes("joute.csv")



def j3_cop(files):
	
	#On importe les résultats (sans pour autant les lire)

	# On ouvre en lecture notre fichier passer en paramètre

	resulstring= open(files,"r").read().splitlines()
	resul = []
	
	# le choix éffectué par j3
	j3_choix = []

	# Premier choix au hasard
	if random.random() < 0.5:
		j3_choix.append(0)
	else:
		j3_choix.append(1)
	
	# Le gain
	j3_gain = []

	tirage = 0
	maxtirage= len(resulstring)
	
	# Pourcentage de réussite
	j3_pour = 0

	while tirage < maxtirage:
		
		resul.append(int(resulstring[tirage]))
		# On pense que le résultat suivant sera le même que le précédent :petit_con: 
		j3_choix.append(resul[tirage])
		
		if resul[tirage] - j3_choix[tirage] == 0:
			j3_gain.append(1)
			j3_pour = j3_pour + 1

		else:
			j3_gain.append(0)
		tirage = tirage + 1

	# On régularise la liste en supprimant le dernier élément qui est en trop.
	j3_choix.pop()

#	print("\n")
#	print("-- J3 - copie le coup d'avant --")
#	print(j3_choix)
	print("\n")
	print("j3 -- 1 = GAGNER -- 0 = PERDU \t % = ",j3_pour/maxtirage)
#	print(j3_gain)

j3_cop("joute.csv")



def j4_invcop(files):
	
	#On importe les résultats (sans pour autant les lire)

	# On ouvre en lecture notre fichier passer en paramètre

	resulstring= open(files,"r").read().splitlines()
	resul = []
	
	# le choix éffectué par j4
	j4_choix = []

	# Premier choix au hasard
	if random.random() < 0.5:
		j4_choix.append(0)
	else:
		j4_choix.append(1)
	
	# Le gain
	j4_gain = []

	tirage = 0
	maxtirage= len(resulstring)
	
	# Pourcentage de réussite
	j4_pour = 0

	while tirage < maxtirage:
		
		resul.append(int(resulstring[tirage]))

		# On joue l'inverse du coup d'avant.
		if resul[tirage] == 1:
			j4_choix.append(0)
		else:
			j4_choix.append(1)
		
		if resul[tirage] - j4_choix[tirage] == 0:
			j4_gain.append(1)
			j4_pour = j4_pour + 1

		else:
			j4_gain.append(0)
		tirage = tirage + 1

	# On régularise la liste en supprimant le dernier élément qui est en trop.
	j4_choix.pop()

#	print("\n")
#	print("-- J4 - joue l'inverse du coup d'avant --")
#	print(j4_choix)
	print("\n")
	print("j4 -- 1 = GAGNER -- 0 = PERDU \t % = ",j4_pour/maxtirage)
#	print(j4_gain)

j4_invcop("joute.csv")



def j5_proba(files):
	
	#On importe les résultats (sans pour autant les lire)

	# On ouvre en lecture notre fichier passer en paramètre

	resulstring= open(files,"r").read().splitlines()
	resul = []
	
	# le choix éffectué par j5
	j5_choix = []

	# Premier choix au hasard
	if random.random() < 0.5:
		j5_choix.append(0)
	else:
		j5_choix.append(1)
	
	# Le gain
	j5_gain = []

	tirage = 0
	maxtirage= len(resulstring)
	
	# Pourcentage de réussite
	j5_pour = 0

	# Pourcentage de pile compter par j5
	pile_pour = 0

	while tirage < maxtirage:
		
		resul.append(int(resulstring[tirage]))

		# On compte le nombre de pile qui tombe.
		if resul[tirage] == 0:
			pile_pour = pile_pour + 1

		# et on joue selon cette probabilité
		if random.random() < (pile_pour / (tirage+1)):
			j5_choix.append(0)
		else:
			j5_choix.append(1)


		if resul[tirage] - j5_choix[tirage] == 0:
			j5_gain.append(1)
			j5_pour = j5_pour + 1

		else:
			j5_gain.append(0)
		tirage = tirage + 1

	# On régularise la liste en supprimant le dernier élément qui est en trop.
	j5_choix.pop()

#	print("\n")
#	print(P"-- J5 - joue selon la meme proba--")
#	print(j5_choix)
	print("\n")
	print("j5 -- 1 = GAGNER -- 0 = PERDU \t % = ",j5_pour/maxtirage)
#	print(j5_gain)

j5_proba("joute.csv")



def j6_proba5(files,groupe):
	
	#On importe les résultats (sans pour autant les lire)

	# On ouvre en lecture notre fichier passer en paramètre

	resulstring= open(files,"r").read().splitlines()
	resul = []
	
	# le choix éffectué par j6
	j6_choix = []

	# Les 5 premiers choix au hasard
	tirage = 0
	
	# Le gain
	j6_gain = []

	maxtirage= len(resulstring)
	
	# Pourcentage de réussite
	j6_pour = 0

	# Première proba
	pa = 0.5

	while tirage < maxtirage:
		
		tirage5 = 0
		pile5 = 0

		while tirage5 < groupe:
			
			# On choisit selon la proba des "groupes" derniers
			if random.random() < pa:
				j6_choix.append(0)
			else:
				j6_choix.append(1)

			resul.append(int(resulstring[tirage + tirage5]))
		
			# On compte le nombre de pile par groupe
			pile5 = pile5 + (1 - resul[tirage + tirage5])
		
			if resul[tirage + tirage5] - j6_choix[tirage + tirage5] == 0:
				j6_gain.append(1)
				j6_pour = j6_pour + 1

			else:
				j6_gain.append(0)
			tirage5 = tirage5 + 1

		tirage = tirage + groupe
		# On calcul la probabilité
		pa = pile5 / groupe

	# On régularise la liste en supprimant le dernier élément qui est en trop.

#	print("\n")
#	print("-- J6 - joue selon la meme proba pendant 5 coups--")
#	PRINT(J6_choix)
	print("\n")
	print("J6 -- 1 = GAGNER -- 0 = PERDU \t % = ",j6_pour/maxtirage)
#	print(j6_gain)

j6_proba5("joute.csv",10)


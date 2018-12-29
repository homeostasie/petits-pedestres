from __future__ import division
# -*- coding: utf-8 -*-
import math
import random
random.seed()

#########################################################
#                                                       #
#              Lièvre                                   #
#                VS                                     #
#              Tortue                                   #
#                                                       #
#########################################################

# On fait tourner un grand nombre de partie et on compte
# les manches gagnées par le lapin et par la tortue.
# --- Entrées
# - nombremanche : le nombre de manche joué.
# - case : Nombre de case que doit parcourir la tortue afin 
# de gagner.
# --- Sorties
# - partieLapin
# - partieTortue

def manche(nombreManche, case):
    # Le nombre de partie gagné par le lapin
    partieLapin = 0

    # Le nombre de partie gagné par la tortue
    partieTortue = 0

    # On part à la partie 1
    for i in range( 0, nombreManche):
        if lot(case) == 0:
            partieLapin  += 1
            #print("Lapin")
        else:
            partieTortue += 1
            #print("tortue")
            
    return( [partieLapin, partieTortue])


# Fonction lot() :
# --- Entrée :
# 
# --- Sorties
# - 1 : si le lapin gagne.
# - 0 : si la tortue gagne.

def lot(case):
    # caseLapin   : Fait avancer le lapin
    caseLapin = 0
    # caseTortue  : Fait avancer la tortue
    caseTortue = 0
 
    # Soit le lapin avance et gagne.
    # Soit la tortue arrive à avancer suffisament loin 
    # jusqu'à un certain nombre de case.
    while (caseLapin != 1 and caseTortue != case):
        de = random.randint(1,6)
        # Si on fait un 6, le lapin avance
        if(de == 6):
            caseLapin = 1
            # et gagne (on écrit retourne un 0)
            return(0)
        # Sinon, la tortue avance
        caseTortue += 1

    # La tortue a gagné
    return(1)


# Execution du programme.

print("-------- Lièvre ---------")
print("--------   VS   ---------")
print("-------- Lapin  ---------")

# Nombre de partie
N = 1000


# La tortue doit avancer de quatre cases.
print("Si la tortue doit avancer de 4 cases")

res = manche(N,4)
print("Resultat = [lapin , tortue]",res)

# La tortue doit avancer de trois cases.
print("Si la tortue doit avancer de 3 cases")
res = manche(N,3)
print("Resultat = [lapin , tortue]",res)


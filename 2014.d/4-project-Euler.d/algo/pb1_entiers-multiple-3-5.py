#!/usr/bin/env python3

"""
-----------------------------------------------------------------
Contributeur :
- Thomas LAFOND
-----------------------------------------------------------------
PROJECT EULER
-----------------------------------------------------------------
Problème 1 :
- La somme des entiers multiples de 3 ou 5.
-----------------------------------------------------------------
 L'algorithme parcourt les entiers les uns à la suite des autres 
en testant dans la boucle s'ils sont multiples ou non de 3 ou 5.
Si oui, on les ajoute à la somme de retour.
-----------------------------------------------------------------
"""


# aNombre est-il multiple de aCoeff ?
# Entrée : 
# - aNombre
# -  aCoeff
# Sortie :
# - True si aNombre est un multiple de aCoeff
# - False sinon 
def EstMultiple(aNombre, aCoeff):
    if aNombre%aCoeff == 0:
        return True
    else:
        return False

# La somme des entiers entre aDepart et aFin divisible par 3 ou 5
# Entrée : 
# - aDepart = Le nombre de départ non compris
# - aFin = Le nombre de fin non compris
# Sortie :
# - La somme des mutliples
def SommeMultiple(aDepart,aFin):

    # On commence avec le premier entier et
    # On initialise la somme à 0
    nombreEntier = aDepart
    somme=0

    # On boucle jusqu'au dernier entier (non compris)
    while(nombreEntier < aFin-1):
        nombreEntier += 1
        # Multiple de 3 OU multiple de 5
        if EstMultiple(nombreEntier,3) or EstMultiple(nombreEntier,5):
            somme += nombreEntier
    return somme

# Main
dep = 0
fin = 1000

# Affiche la somme
print("somme : ",SommeMultiple(dep,fin))


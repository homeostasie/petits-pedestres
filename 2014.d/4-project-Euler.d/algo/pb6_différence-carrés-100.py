#!/usr/bin/env python3

"""
-----------------------------------------------------------------
Contributeur :
- Thomas LAFOND
-----------------------------------------------------------------
PROJECT EULER
-----------------------------------------------------------------
Problème 6 :
- La différence entre le carré de la somme des cents premiers 
entiers et la somme des cents premiers entiers au carré.
-----------------------------------------------------------------
- Fonction 1 : Carré de la somme
- Fonction 2 : Somme des carrés
-----------------------------------------------------------------
"""

# 
def carreSomme(aLast):
    return (aLast*(aLast+1)//2)*(aLast*(aLast+1)//2)


# Le prochain nombre premier
def sommeCarre(aLast):
    return (2*aLast + 1)*(aLast + 1)*aLast//6

def diffopti(aLast):
    return aLast*(aLast + 1)*(3*aLast*aLast - aLast -2)//12

# Main
#print(carreSomme(100) - sommeCarre(100))
print(diffopti(100))

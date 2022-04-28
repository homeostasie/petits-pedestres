#!/usr/bin/env python3

"""
-----------------------------------------------------------------
Contributeur :
- Thomas LAFOND
-----------------------------------------------------------------
PROJECT EULER
-----------------------------------------------------------------
Problème 2 :
- Les nombres de fibonacci pair.
-----------------------------------------------------------------
 L'algorithme 1 calcule la suite de nombre de Fibonacci et 
ne fait la somme que des nombres pairs.
 L'algorithme 2 s'appuie sur la 3-périodicité des nombres pairs
dans la suite de Fibonacci.
-----------------------------------------------------------------
"""

def SommeFibonacciPair(aFin):

    # Les deux premiers termes
    aFib1 = 1
    aFib2 = 2

    somme = 2

    while(aFib2 < aFin):
        # b2 -> a1 + b1
        # a2 -> b1 -> b2 - a1 
        aFib2 += aFib1
        aFib1 = aFib2-aFib1
        
        # On vérifie si aFib2 est pair
        if aFib2 % 2 == 0:
            somme += aFib2
            
    return somme 

# Utilisation de la parité
def SommeFibonacciPair3(aFin):

    # Les deux premiers termes
    aFib1 = 1
    aFib2 = 2

    somme = 0

    while(aFib2 < aFin):
        somme += aFib2
        # b2 -> a1 + b1
        # a2 -> b1 -> b2 - a1 
        
        # itérations 1
        aFib2 += aFib1
        aFib1 = aFib2-aFib1
        # itération 2
        aFib2 += aFib1
        aFib1 = aFib2-aFib1
        # itération 3
        aFib2 += aFib1
        aFib1 = aFib2-aFib1      

    return somme 


# Main
fin = 4000000


# Affiche la somme
print("1 - somme des nombres de Fibonacci pairs: ",SommeFibonacciPair(fin))
print("2 - somme des nombres de Fibonacci pairs: ",SommeFibonacciPair3(fin))

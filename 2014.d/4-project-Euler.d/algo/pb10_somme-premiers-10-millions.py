#!/usr/bin/env python3

"""
-----------------------------------------------------------------
Contributeur :
- Thomas LAFOND
-----------------------------------------------------------------
PROJECT EULER
-----------------------------------------------------------------
Problème 10 :
- La somme des premiers en dessous de 2 millions.
-----------------------------------------------------------------

-----------------------------------------------------------------
"""

# Return True if aNombre is prime
def EstPremier(aNombre):
    if aNombre == 2:
        estPremier = True
    elif aNombre % 2 == 0:
       estPremier = False
    else:
        p = 3
        estPremier = True
        miNombre = aNombre // 2
        while (p < miNombre and estPremier):
            if aNombre % p == 0:
                estPremier = False
            else:
                p +=2  
    return estPremier


# Return the next prime after aNombre
def ProchainPremier(aNombre):
    suivPremier = aNombre +1
    while(not EstPremier(suivPremier)):
        suivPremier += 1
    return(suivPremier)


# Return the sum of prime under aNombre
def sommeNPremier(aNombre):
    sumPrem = 1
    prem = 1
    while prem < aNombre:
        prem = ProchainPremier(prem)
        sumPrem += prem
        print(prem, ", ",sumPrem)
    return sumPrem


# Main
nombre = 2000000

print (sommeNPremier(nombre))

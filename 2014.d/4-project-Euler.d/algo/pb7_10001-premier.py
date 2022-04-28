#!/usr/bin/env python3

"""
-----------------------------------------------------------------
Contributeur :
- Thomas LAFOND
-----------------------------------------------------------------
PROJECT EULER
-----------------------------------------------------------------
Problème 7 :
- Le 10001 nombre premier.
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


# Return the aNombre prime
def niemePremier(aNombre):
    i = 1
    prem = 1
    while i <= aNombre:
        prem = ProchainPremier(prem)
        i += 1
        
    return prem


# Main
nombre = 10001

print (niemePremier(nombre))

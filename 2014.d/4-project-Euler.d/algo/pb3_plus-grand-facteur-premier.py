#!/usr/bin/env python3

"""
-----------------------------------------------------------------
Contributeur :
- Thomas LAFOND
-----------------------------------------------------------------
PROJECT EULER
-----------------------------------------------------------------
Problème 3 :
- Le plus grand facteur premier (de 600851475143).
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


# Return the last prime factor
def DernierPremier(aNombre):
    suiNombre = aNombre
    p = 2
    while suiNombre > p:
        while suiNombre % p == 0:
            suiNombre = suiNombre / p
        p = ProchainPremier(p)
        
    return p


# Main
nombre = 600851475143
print(" Plus grand facteur premier de",nombre, " = ",DernierPremier(nombre))


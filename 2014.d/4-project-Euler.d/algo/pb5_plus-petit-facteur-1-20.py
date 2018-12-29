#!/usr/bin/env python3

"""
-----------------------------------------------------------------
Contributeur :
- Thomas LAFOND
-----------------------------------------------------------------
PROJECT EULER
-----------------------------------------------------------------
Problème 5 :
- Le plus petit nombre qui est divisible par tous les entiers 
compris entre 1 et 20.
-----------------------------------------------------------------
- Fonctions 1 et 2 issues du problème 3.
- - EstPremier et ProchainPremier
- Cacule de la puissance des nombres premiers inférieurs à 20
-----------------------------------------------------------------
"""

# True si aNombre est premier
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


# Le prochain nombre premier
def ProchainPremier(aNombre):
    suivPremier = aNombre +1
    while(not EstPremier(suivPremier)):
        suivPremier += 1
    return(suivPremier)

# Cacule de la puissance des nombres premiers inférieurs à aNombre
def maxFactor(aNombre):
	lstfact = []
	p = ProchainPremier(1)
	i = 0
	maxfact = 1
	
	# Parcours des nombres premiers
	while p < aNombre:
		
		lstfact.append(p)
		alpha = p
		
		# Maximise les facteurs
		while(lstfact[i] *  alpha < aNombre):
			lstfact[i] = lstfact[i] *  alpha

		p = ProchainPremier(p)
		# Effectue le produit
		maxfact *= lstfact[i]
		i += 1
		
	return maxfact

	
# Main
print("min facteur",maxFactor(100))


###########################################################################
#												  #
#	Traffic routier									  #
#												  #
###########################################################################
##
##  Flux continu
##
############################

#On connait maintenant les les paramètres
#On prends les deux voies et on cherche le nombre de voitures qui s'accumulent
#le temps du feu

#Nombre de voiture arrété au feu si aucune au départ pendant le temps 
length(flux_1[flux_1<30])
length(flux_2[flux_2<30])



##################
## 
lambda_1 = 4
lambda_2 = 3
# v = 30 km / heure, on veut en mètre par min
v = 0.5

#Calcul de L
v/2 * (5 - 4/60 * 5* (lambda_1 + lambda_2))

L = 0.6

#d1 + d2 = 5minutes - 2L/v
5 - 2*L / v

#d1 >=
4/60 * 4 *5 

#d2 >=
4/60 * 3 * 5
2L/v
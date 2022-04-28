###########################################################################
#												  #
#	Traffic routier									  #
#												  #
###########################################################################
##
##  Flux continu
##
############################

#On récupère un échantillon:

#Simulation des tau : le temps entre l'arrivé de deux voitures
#n le nombre de voiture compté
n_1 = 50
n_2 = 50


#lambda_theo_1 le paramètre
lambda_theo_1 = 0.12
lambda_theo_2 = 0.13


#Tau_1 est le fichier récupérer de l'intervalle de temps entre le passage de deux voitures
tau_1 = rexp(n_1, rate = lambda_theo_1)
tau_2 = rexp(n_1, rate = lambda_theo_1)

#plot(tau_1,type="b")
#plot(tau_1,type="s")

#En second
#En moyenne, il passe une voiture en mean(tau) en seconde
#tau_1
#mean(tau_1)
On peut ainsi récupérer
lambda_exp_1 = 1/mean(tau_1)
lambda_exp_2 = 1/mean(tau_2)


#
flux_1 = tau_1
for(i in 2:n_1)
{
	flux_1[i]=flux_1[i-1]+flux_1[i]
}
flux_2 = tau_2
for(i in 2:n_2)
{
	flux_2[i]=flux_2[i-1]+flux_2[i]
}

#Graph
par(mfrow=c(2,2))
plot(tau_1,type="s")
title("Intervalle d'arrivée entre deux voitures sur la voie 1")
plot(flux_1,seq(1,n_1),type="s")
title("Temps de passage au point de départ sur la voie 1")

plot(tau_2,type="s")
title("Intervalle d'arrivée entre deux voitures sur la voie 2")
plot(flux_2,seq(1,n_2),type="s")
title("Temps de passage au point de départ sur la voie 2")


tau_1
tau_2


#Deuxième méthode:
 #On compte le nombre de voiture dans un intervalle de 30s
fluxx_1 = rpois(50, lambda=lambda_1*30)
fluxx_1
for(i in 2:n_1)
{
	fluxx_1[i]=fluxx_1[i-1]+fluxx_1[i]
}

plot( seq(1,n_1*30,30), fluxx_1,type="s")




# Estimation de la longueur de la file pour la chantier routier

## Paramètres
N=5000;#     // nombre d'échantillons   (npmbre de simulations)
n=500;#    // taille des échantillons (durée de chaque simulation)

a=4/60;   # // a= 4 sec. = 4/60 mn.
lambda1= 4;
lambda2= 3;
L=.6;
v=.5;
d1=1.5;
d2=1.1;

K= floor(d1/a);
mu1= lambda1 * d1;
mu2= lambda1 * (d2+2*L/v);
#// Simulation de la suite X(i) (1 <= i <= n)
Y = matrix(0,N,n);
Z = matrix(0,N,n);
X = matrix(0,N,n);

for (i in 1:n)
{
	Y[,i]=rpois(N,mu1);
	Z[,i]=rpois(N,mu2);
}

#Nombre de voiture
#Calcul de Xn
i=1
while (i < n)
{
	j = 1
	while (j <= N)
	{
		X[j, i+1] = max(0 ,X[j, i]+Y[j, i] - K ) + Z[j, i];
		j = j +1
	}
	i = i +1
}

#Longueur de file
i = 1
XX = matrix(0,N,1)
while (i <= N) 
{
	XX[i] = mean(max(X[i,])) *(0.6*5 + 0.3 *10 + 0.1*20)
	i = i + 1;
}

#Nombre de voitures moyen
moy_long = mean(X[, n])
#Longeur de file moyenne
moy_file = moy_long*(0.6*5 + 0.3 *10 + 0.1*20)

#Affichage des boxplots 
par(mfrow=c(1,2))
boxplot(X[,n])
title("Boxplot du nombre voitures au bout de 500 cycles")
boxplot(XX)
title("Boxplot de la longueur de la file au bout de 500 cycles")

#Affichage des histogrammes
par(mfrow=c(1,2))
hist(X, freq=TRUE)
hist(XX)

length(XX[XX>235]) / N

# frequences empiriques
femp = table(X)/(n*N)              
hist(femp)
title("Fréquences empiriques")


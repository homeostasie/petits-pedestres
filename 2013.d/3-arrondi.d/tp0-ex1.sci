//Le TP0 Erreur d'arrondi
// LAFOND Thomas
//Exo 1 - Le but est d'approximer la fonction cosinus d'une manière stable
//a - Volontairement on va faire selon la série entière classique...

function [a1_cos]=F_a1_cos(x)

   // A1_cos est la fonction de sortie
   // x est l'entrée de la fonction
   
   // N est le nombre d'itération qu'on va faire pour la série entière.
N=50
   // On part avec une série entière avec un premier terme a1 = 1 
   a1_cos=1
 //on part à k = 1!!! car on a déjà pris un a1
 
    for k=1:1:N
	// On calcul la factoriel à chaque rang tout rang
        facto=prod([1:2*k])     
        a1_cos=a1_cos+(((-1)^k)*(x**(2*k)/facto)),
    end
endfunction

function [a2_cos]=F_a2_cos(x)

   // a2_cos est la fonction de sortie
   // x est l'entrée de la fonction
   
   // N est le nombre d'itération qu'on va faire pour la série entière.
N=50
   // Pour faire un calcul plus juste on utilise la périodicité de cos. en effet cos(a)=cos(2*pi*a)  
x_mod=pmodulo(x,2*%pi) 
   
   // On part avec une série entière avec un premier terme a1 = 1 
   a2_cos=1
 //on part à k = 1!!! car on a déjà pris un a1
 
    for k=1:1:N
	// On calcul la factoriel à chaque rang tout rang
        facto=prod([1:2*k])     
        a2_cos=a2_cos+(((-1)^k)*(x_mod**(2*k)/facto)),
    end
endfunction

function [a3_cos]=F_a3_cos(x)

   // a3_cos est la fonction de sortie
   // x est l'entrée de la fonction
   // N est le nombre d'itération qu'on va faire pour la série entière.
N=50
//un sert a faire l'alternance des termes de la série entière
un=1
//a3_cos est initialisé à un
som1(1)=1
prod1(1)=1
for i=1:1:N-1
    prod1(i+1)=prod1(i)*(x/(2*i))*(x/(2*i-1)),
    un=(-1)*un,	
    som1(i+1)=som1(i)+(un*prod1(i+1)),
  end
  a3_cos=som1(N)
endfunction



function [a4_cos]=F_a4_cos(x)

   // a3_cos est la fonction de sortie
   // x est l'entrée de la fonction
   // N est le nombre d'itération qu'on va faire pour la série entière.
N=50
   // Pour faire un calcul plus juste on utilise la périodicité de cos. en effet cos(a)=cos(2*pi*a)  
x_mod=pmodulo(x,2*%pi) 
//un sert a faire l'alternance des termes de la série entière
un=1
//a3_cos est initialisé à un
som1(1)=1
prod1(1)=1
for i=1:1:N-1
    prod1(i+1)=prod1(i)*(x_mod/(2*i))*(x_mod/(2*i-1)),
    un=(-1)*un,	
    som1(i+1)=som1(i)+(un*prod1(i+1)),
  end
  a4_cos=som1(N)
endfunction


a1_cos=F_a1_cos;
a2_cos=F_a2_cos;
a3_cos=F_a3_cos;
a4_cos=F_a4_cos;

inter=30:0.1:39.5;
plot2d(inter,a1_cos(inter),style=5)
plot2d(inter,a2_cos(inter))

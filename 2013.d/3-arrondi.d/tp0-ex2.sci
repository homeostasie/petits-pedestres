//Le TP0 Erreur d'arrondi
// LAFOND Thomas
//Exo 2 - Un peu de récurrence - Voir document pdf pour les questions théoriques.
function [I_x5] = F_intpos(n_in)
  //I_x5 est la variable de sortie sous forme d'un tableau qui sort les valeurs trouver par récurrence positif.
  //n_in est la variable d'entrée qui demande jusqu'a quel rang nous appliquerons la récurrence.
  //soit I_x5(1,3) le calcul au rang 0
  

I_x5(1)=log(11/10)

// i est la variable utilisé pour la boucle while on la commence à 1 pour ne pas avoird de souci avec les tableaux
i=1
while i<n_in
  //On réalise la récurrence
  I_x5(i+1)=1/i-10*I_x5(i)
  //On encadre le tabeau dans les 2ieme et 3ieme colonnes par les vérifications d'encadrement
   i=i+1,
end
endfunction


function [I_xinv5] = F_intinv(n_in)
  //I_xinv5 est la variable de sortie sous forme d'un tableau qui sort les valeurs trouver par récurrence inverse.
  //n_in est la variable d'entrée qui demande à quel rang on affecte le premier terme par son approximation.

  
I_xinv5(n_in)=1/(10*(n_in+1))

  // n_in est une variable d entree qui indique le nombre d'itération à faire
   // Le I_xinv5 1 range les In trouvé par récurrence en partant de In entre 1/(11*(n_in+1)) et 1/(10*(n_in+1))
   // Le I_xinv5 2 teste la première inégalités et renvoie le résultat
   
i=n_in-1 
  while i>0
    I_xinv5(i) = (1/10)*(1/(i)-I_xinv5(i+1)),
    i=i-1
  end
endfunction

function [tab_comp] = F_tab_comp(n_in)
[I_x5] = F_intpos(n_in);
[I_xinv5] = F_intinv(n_in);

for j=0:1:n_in-1
  tab_comp(j+1,1)=j;
  tab_comp(j+1,2)=1/(11*(j+1));
  tab_comp(j+1,3)=1/(10*(j+1));
  tab_comp(j+1,4)=I_x5(j+1);
  tab_comp(j+1,5)=I_xinv5(j+1);
end

endfunction

[tab_comp] = F_tab_comp(30)
j=1:1:15
plot2d(j,tab_comp(j,2))
plot2d(j,tab_comp(j,3))
plot2d(j,tab_comp(j,4),style=5)
plot2d(j,tab_comp(j,5),style=[color("green")])

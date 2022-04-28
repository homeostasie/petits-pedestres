// n+1 est le nombre de points dans [a,b]. n correspond également au degré du polynôme.
// X_n ces points 
//fin+1 un nombre de point bien plus précis pour X_fin sur le même intervalle
//inter est l'intervalle d'étude
//fon_tp crée les fonctions utilisées pour le tester le TP
exec('fon_tp.sci');


//main avec boite de lancement
choix=x_choose(['Racine de X sur [0 1]';'Valeur absolue de X sur [-1 1]';'x**n'],['Choisissez l exercice'])
if choix==1
  inter=[0 1];
  n=4; 
  fon_uti=F_fon_sqrt;
  ite=6
elseif choix==2
  inter=[-1 1];
  n=6; 
  fon_uti=F_fon_abs;
  ite=6
elseif choix==3
  sig=x_mdialog('choisir n',['n'],['5'])
  n=evstr(sig(1))
  inter=[-1 1]
  fon_uti=F_xpuisn
  ite=10
end

fin=100;
Erreur=0.1;

//intervalle.sci crée deux vecteurs d'abscisses
  exec('intervalle.sci');
  [X_n,X_fin]=F_interval(inter,fin);
//fon_tp crée les fonctions utilisées pour le tester le TP
//Ici on choisit la fonction qu'on va utilisé


//On execute l'algorythme de Tchebytchev qui nous sort une matrice avec les coefficients alterné du polynome dans la matrice Coef_poly et l'Erreur. On construit également le polynôme.
//Dans l'exec se situe aussi le graph de la fonction demandé sur les X_fin
plot2d(X_fin,fon_uti(X_fin),style=5)
j=1
while j<ite
  exec('tcheby.sci');
  exec('remez.sci');
  
  //disp('Erreur =',Erreur)

[Cprime]=F_remez(Poly_tcheby);
 


  //disp('Cprime =',Cprime)
  
//On trace les fonction
plot2d(X_fin,F_Poly_Tcheby(X_fin))
plot2d(X_n,F_Poly_Tcheby(X_n),style=-2)
xpause(10**6)
//on appelle l'algo de remez
  exec('algofin_remez.sci');
  [X_n]=F_alog_remez(Cprime,X_n);
  //disp(X_n);
  j=j+1;
end

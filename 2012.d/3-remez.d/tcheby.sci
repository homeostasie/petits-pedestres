funcprot(0)
function [Coef_poly,Erreur]=F_Coef_Tcheby(fon_uti)
//Soit Coef_poly la matrice des coéfficients du polynôme
//Soit Vender la matrice de Vandermonde

  for i=1:1:n+1
    for j=0:1:n
      Vander(i,j+1)=X_n(i)**j,
    end
    Vander(i,n+1)=(-1)**(i+1)
  end
 //Soit ColFunc1 le vecteur colonne de la fonction fon_uti aux points de X_n
  for i=1:1:n+1
    ColFunc1(i)=fon_uti(X_n(i))
  end
  Coef_poly=lsq(Vander,ColFunc1)
  Erreur=abs(Coef_poly(n+1))
  
endfunction

funcprot(0)

function [Poly_tcheby]=F_Poly_Tcheby(x)
  //On construit le polynome à partir des coefficients obtenu par Tcheby 
  //On appelle la fonction qui calcul les coeffs
 A=0
  for i=1:1:n
     A=A+Coef_poly(i)*(x)^(i-1)
  end
  Poly_tcheby=A
 
endfunction

[Coef_poly,Erreur]=F_Coef_Tcheby(fon_uti);
[Poly_tcheby]=F_Poly_Tcheby;

funcprot(0)

function [fmoinsp]=F_fmoinsp(x)
  fmoinsp=fon_uti(x)-Poly_tcheby(x)
endfunction

funcprot(0)
[fmoinsp]=F_fmoinsp;
function [Cprime]=F_remez(Poly_tcheby)
//Soit Col_diff la matrice de f(x) - p(x) sur cet petit intervalle
  for i=1:1:fin+1
    Col_diff(i)=abs(fmoinsp(X_fin(i)))
  end
 //On cr�e un couple ordonn�e, abscisse; Cmax pour rentrer les donn�es utiles ult�rieurement
 [Cmax(2),Cmax(1)]=max(Col_diff)
 Cprime=X_fin(Cmax(1))
endfunction





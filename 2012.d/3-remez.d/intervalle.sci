function [X_n,X_fin]=F_interval(inter,fin)
//On peut utiliser la fonction linspace(a,n,b)
  
  X_n(1)=inter(1)
  X_fin(1)=inter(1)
  
  for i=1:1:n
    X_n(i+1)=inter(1)+i*(inter(2)-inter(1))/(n),
  end
    
  for i=1:1:fin
     X_fin(i+1)=inter(1)+i*(inter(2)-inter(1))/(fin),
  end
      
endfunction
    
 
  
function [X_n]=F_permut(X_n,val,place)
  // si place = 1 alors on incrémente a partir du premier et si place = -1 on incremente à partir du dernier
  Xtemp=X_n
  if place ==1 then
    X_n(1)=val
    for i1=1:1:length(X_n)-1
      X_n(i1+1)=Xtemp(i1)
    end 
  else
    X_n(length(X_n))=val
    for i1=1:1:length(X_n)-1
      X_n(i1)=Xtemp(i1+1)
    end
  end
endfunction
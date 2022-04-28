function [X_n]=F_alog_remez(Cprime,X_n)
l=0
  
if X_n(1)<=Cprime & Cprime<X_n(2)
     if sign(fmoinsp(X_n(2))) == sign(fmoinsp(Cprime))
        X_n(2)=Cprime
        disp('display',10)
     else
        [X_n]=F_permut(X_n,Cprime,1)
        disp('display',20)
     end
     l=1
end  
  
 
 if  l==0 
  if  X_n(n)< Cprime & Cprime <=X_n(n+1)
        if sign(fmoinsp(X_n(n))) == sign(fmoinsp(Cprime))
          X_n(n)=Cprime
          disp('display',30)
        else
          [X_n]=F_permut(X_n,Cprime,-1)
          disp('display',40)
        end
        l=1
   end
 end
 
 
if l==0
  k=3
  while (X_n(k)<Cprime)
     k=k+1
  end
  
    
  if sign(fmoinsp(X_n(k)))== -sign(fmoinsp(Cprime))
      X_n(k-1)=Cprime
      disp('display',50)
      l=1
    else
      X_n(k)=Cprime
      disp('display',60)
      l=1
   end
 end
 
endfunction
// LAFOND Thomas
function [fon_exo3] = F_fon_exo3(x)
  fon_exo3=abs(log(x))
endfunction

fon_exo3= F_fon_exo3

function [U_n] = f_rec(U_0,n)
  i=0
  U_n=U_0
  while i<n
    U_n=F_fon_exo3(U_n)
    i=i+1
  end
endfunction

[U_n] = f_rec
k=1.5:0.005:2.5;

plot2d(k,U_n(k,30))

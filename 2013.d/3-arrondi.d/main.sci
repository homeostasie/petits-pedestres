// Main
// LAFOND Thomas
//Exo 1
exec('tp0-ex1.sci');
halt



//Exo 2
n_in=evstr(x_dialog('Grandeur de la r�currence ?','30'))
xset("window",1); 
exec('tp0-ex2.sci');
tab_comp(n_in)
halt
x_dialog (['Exo 2';'En rouge la r�currence classique et en vert l-invers�';'On trouve que la r�currence simple est passablement fausse d�s le rang 13']);
zoom_rect([12.8,0.005,14.2,0.0075])
halt
//Exo 3
xset("window",2); 
exec('tp0-ex3.sci');

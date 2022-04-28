// Main
// LAFOND Thomas
//Exo 1
exec('tp0-ex1.sci');
halt



//Exo 2
n_in=evstr(x_dialog('Grandeur de la récurrence ?','30'))
xset("window",1); 
exec('tp0-ex2.sci');
tab_comp(n_in)
halt
x_dialog (['Exo 2';'En rouge la récurrence classique et en vert l-inversé';'On trouve que la récurrence simple est passablement fausse dès le rang 13']);
zoom_rect([12.8,0.005,14.2,0.0075])
halt
//Exo 3
xset("window",2); 
exec('tp0-ex3.sci');

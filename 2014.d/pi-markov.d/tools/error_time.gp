# -- Export png
set terminal png size 1200,800
set output 'output/error-time.png'

set title 'Error by computation time'

set grid;

## ÉCHELLE

# -- X --
set xrange [0:1.2];
set xtics 0.1;
set xlabel ' Temps (seconds)';

# -- Y --
set yrange [0:0.2];
set ytics 0.01;
set ylabel ' Erreur (unité)';

# Légende
set key on inside center top 

plot 'output/data.txt' u 6:5 w p notitle 

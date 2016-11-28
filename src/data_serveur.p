# Script Gnuplot pout creer les graph a partir du fichier "data_serveur.txt" genere par Domotique.
# Ce fichier s'appelle data_serveur.p

set autoscale
unset log
unset label
set xtic auto
set ytic auto
set title "ValPhen, ValCtrl et Etat Courant"
set xlabel "tic"
set grid ytics
plot "data_serveur.txt" using 1:2 title 'ValPhen' with linespoints linecolor rgb "red" pointtype 7,\
"data_serveur.txt" using 1:3 title 'ValCtrl' with linespoints linecolor rgb "blue" pointtype 7,\
"data_serveur.txt" using 1:4 title 'Etat Courant' with linespoints linecolor rgb "green" pointtype 7,\

# Script Gnuplot pout creer les graph a partir du fichier "data_serveur.dat" genere par Domotique.
# Ce fichier s appelle data_serveur.p
#
set autoscale
unset log
unset label
set xtic auto
set ytic auto
set xlabel "tic"
set grid ytics
#
set multiplot layout 2,1
set title "Evolution de la zone 1"
plot "data_serveur.dat" using 1:2 title 'ValPhen' with linespoints linecolor rgb "red" pointtype 7,\
	"data_serveur.dat" using 1:3 title 'ValCtrl' with linespoints linecolor rgb "blue" pointtype 7,\
	"data_serveur.dat" using 1:4 title 'Etat Courant' with linespoints linecolor rgb "green" pointtype 7 
#
set title "Evolution de la zone 2"
plot "data_serveur.dat" using 1:5 title 'ValPhen' with linespoints linecolor rgb "red" pointtype 7,\
	"data_serveur.dat" using 1:6 title 'ValCtrl' with linespoints linecolor rgb "blue" pointtype 7,\
	"data_serveur.dat" using 1:7 title 'Etat Courant' with linespoints linecolor rgb "green" pointtype 7 
#
unset multiplot

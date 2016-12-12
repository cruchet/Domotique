# Script Gnuplot pout creer les graph a partir du fichier "data_serveur.dat" genere par Domotique.
# Ce fichier s appelle data_serveur.p
#
set autoscale
unset log
unset label
set xtic auto
set ytic auto
set xlabel "tic (1/min)"
set grid ytics
#
set multiplot layout 2,1
set title "Evolution de la chambre"
set ylabel "Température"
plot "data_serveur.dat" using 1:2 title 'ValPhen' with linespoints lc rgb "0x008000" pointtype -1,\
	"data_serveur.dat" using 1:3 title 'ValCtrl' with linespoints lc rgb "blue" lt 0 lw 0.5,\
	"data_serveur.dat" using 1:4 title 'Etat Courant' with linespoints lc rgb "red" pointtype -1 
#
set title "Evolution de l aquarium"
set ylabel "pH"
plot "data_serveur.dat" using 1:5 title 'ValPhen' with linespoints lc rgb "0x008000" pointtype -1,\
	"data_serveur.dat" using 1:6 title 'ValCtrl' with linespoints lc rgb "blue" lt -1 lw 0.5,\
	"data_serveur.dat" using 1:7 title 'Etat Courant' with linespoints lc rgb "red" pointtype -1 


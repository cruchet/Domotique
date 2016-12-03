# Script Gnuplot pout creer les graph a partir du fichier "data_serveur.dat" genere par Domotique.
# Adapté pour ploter DEUX zones EXACTEMENTS. Pas encore au point...
# Ce fichier s appelle data_serveur.p

set autoscale
unset log
unset label
set xtic auto
set ytic auto
set xlabel "tic"
set grid ytics

do for [t=0:1]  { 
	set term x11 t
	set title "Zone ".(t+1)
	plot "data_serveur.dat" every :::t::t using 1:2 title 'ValPhen' with linespoints linecolor rgb "red" pointtype 7,\
	"data_serveur.dat" every :::t::t using 1:3 title 'ValCtrl' with linespoints linecolor rgb "blue" pointtype 7,\
	"data_serveur.dat" every :::t::t using 1:4 title 'Etat Courant' with linespoints linecolor rgb "green" pointtype 7 
}


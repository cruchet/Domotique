/*
 * Serveur.cpp
 *
 *  Created on: 14 nov. 2016
 *      Author: jordanmetz
 */

#include "Serveur.h"

namespace Domotique {
using namespace std;

Serveur::Serveur(string nom, string nom_fichier): Processus(nom), nom_fichier_(nom_fichier), tic_(0){}


Serveur::~Serveur() {

}

void Serveur::save(double valphen, double etat, double val_ctrl) {
	string dest_name(nom_fichier_);

	// ouverture du flot de sortie
	ofstream f_dest(dest_name.c_str(), ios::out); // ouverture du fichier destination
	// verification que le fichier a pu etre ouvert (en mode ecriture)
	if (f_dest.fail()) {
		cout << "Erreur: impossible d'ouvrir le fichier " << dest_name << " en ecriture" << endl;
	}
	f_dest << "# Ordre: tic\tVALPHEN\tVALCTRL\tETAT COURANT" << endl;

	// Ecriture sur une ligne du fichier
	f_dest << tic_ << "\t" << valphen << "\t" << etat << "\t" << val_ctrl << endl;

	//Fermeture du fichier
	f_dest.close();
}

void Serveur::run(void){
	tic_++;
}

} /* namespace Domotique */

/*
 * Serveur.cpp
 *
 *  Created on: 14 nov. 2016
 *      Author: jordanmetz
 */

#include "Serveur.h"

namespace Domotique {
using namespace std;

Serveur::Serveur(string nom, string nom_fichier): Processus(nom),
		nom_fichier_(nom_fichier), tic_(0), ligne_(""){
	string dest_name(nom_fichier);

	// ouverture du flot de sortie
	ofstream f_dest(dest_name.c_str(), ios::out); // ouverture du fichier destination
	// verification que le fichier a pu etre ouvert (en mode ecriture)
	if (f_dest.fail()) {
		cout << "Erreur: impossible d'ouvrir le fichier " << dest_name << " en ecriture" << endl;
	}
	f_dest << "# Ordre: tic\tVALPHEN\tVALCTRL\tETAT COURANT" << endl;
	f_dest << tic_ << "\t";
	f_dest.close();
}


Serveur::~Serveur() {

}

void Serveur::save(double valphen, double etat, double val_ctrl) {
	string add;          // string which will contain the result
	ostringstream convert;   // stream used for the conversion
	convert << valphen << "\t"<< val_ctrl << "\t"<< etat << "\t";      // insert the textual representation of 'Number' in the characters in the stream
	add = convert.str();
	ligne_ = ligne_ +add;
}

void Serveur::run(int tic){
	tic_ = tic + 1;
	string dest_name(nom_fichier_);
	ofstream f_dest(dest_name.c_str(), ios::app); // ouverture du fichier destination
	if (f_dest.fail()) {
		cout << "Erreur: impossible d'ouvrir le fichier " << dest_name << " en ecriture" << endl;
	}

	f_dest << ligne_<< endl;
	ligne_.clear();
	string add;
	ostringstream convert;
	convert << tic_ << "\t";
	add = convert.str();
	ligne_ = add;
}

} /* namespace Domotique */

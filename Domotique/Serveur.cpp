/*
 * Serveur.cpp
 *
 *  Created on: 14 nov. 2016
 *      Author: jordanmetz
 */

#include "Serveur.h"
#include <string>
#include <fstream>
#include <iostream>

namespace Domotique {
using namespace std;

Serveur::Serveur(): Processus(), valphen_(0), valctrl_(0), etat_courant_(0) {}

Serveur::~Serveur() {}
void Serveur::run(){
	string source_name;
	string dest_name("dom_serv.txt");

	// ouverture du flot de sortie
	ofstream f_dest(dest_name.c_str(), ios::app); // ouverture du fichier destination
	// vérification que le fichier a pu être ouvert (en mode écriture)
	if (f_dest.fail()) {
	cout << "Erreur: impossible d'ouvrir le fichier " << dest_name << " en écriture" << endl;
	}

	// Ecriture
	for (int i=0; i <= etat_courant_.size(); i++){
		f_dest << i << " "
				<<valphen_.at(i) << " "
				<< valctrl_.at(i) << " "
				<< etat_courant_.at(i) << " "
				<<endl;
	}
	f_dest.close();
}

} /* namespace Domotique */

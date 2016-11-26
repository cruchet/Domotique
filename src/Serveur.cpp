/*
 * Serveur.cpp
 *
 *  Created on: 14 nov. 2016
 *      Author: jordanmetz
 */

#include "../src/Serveur.h"

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

#include "../src/Processus.h"

namespace Domotique {
using namespace std;

Serveur::Serveur(string nom, vector<double> setting):
		Processus(nom, "serveur", setting), nom_fichier_("data_serveur.txt"),
		data_(setting.at(0)), nb_zone_(setting.at(0)), zone_courante_(0), nb_tic_(0)
		{}

Serveur::~Serveur() {}

string Serveur::ecriture(){
	string dest_name(nom_fichier_);

	cout << "Enregistrement dans le fichier: " << nom_fichier_ << endl;
	// ouverture du flot de sortie
	ofstream f_dest(dest_name.c_str(), ios::app); // ouverture du fichier destination
	// verification que le fichier a pu etre ouvert (en mode ecriture)
	if (f_dest.fail()) {
		cout << "Erreur: impossible d'ouvrir le fichier " << dest_name << " en ecriture" << endl;
	}

	// Ecriture
	for (int zone=0; zone==nb_zone_; zone++)
	{
		f_dest << "# ZONE n°" << zone << endl;
		vector<vector< double> > pourchaquetic= data_.at(zone);
		for (unsigned int tic=0; tic <= nb_tic_; tic++){
			vector<double> threedata = pourchaquetic.at(tic);
			f_dest << tic << " "
					<<threedata.at(VALPHEN) << " "
					<< threedata.at(ETAT_COURANT) << " "
					<< threedata.at(VALCTRL) << " "
					<<endl;
		}
	}
	f_dest.close();
	return nom_fichier_;
}
vector<double> Serveur::run(vector<double> param){
	nb_tic_= nb_tic_+1;
	(data_.at(zone_courante_)).push_back(param);
	zone_courante_=zone_courante_ +1;
	if (zone_courante_==nb_zone_){
		zone_courante_=0;
	}
	return param;
}

} /* namespace Domotique */

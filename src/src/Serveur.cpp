/*
 * Serveur.cpp
 *
 *  Created on: 14 nov. 2016
 *      Author: jordanmetz
 */

#include "Serveur.h"

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

namespace Domotique {
using namespace std;

Serveur::Serveur(string nom, vector<double> setting):
		Processus(nom, "serveur", setting), nom_fichier_("data_serveur.txt"),
		nb_zone_(setting.at(0)), zone_courante_(0), nb_tic_(0)
		{vector< vector <vector <double> > >data(nb_zone_, vector<vector<double> > (nb_tic_, vector<double>(3)));
		data_ =data;}


Serveur::~Serveur() {}

string Serveur::ecriture(vector<string> nom_zone){
	string dest_name(nom_fichier_);

	cout << "Enregistrement dans le fichier: " << nom_fichier_ << endl;
	// ouverture du flot de sortie
	ofstream f_dest(dest_name.c_str(), ios::out); // ouverture du fichier destination
	// verification que le fichier a pu etre ouvert (en mode ecriture)
	if (f_dest.fail()) {
		cout << "Erreur: impossible d'ouvrir le fichier " << dest_name << " en ecriture" << endl;
	}

	// Ecriture
	f_dest << "# Ordre: VALPHEN\tVALCTRL\tETAT COURANT" << endl;
	cout << nb_zone_ << endl;
	for (int zone=0; zone<nb_zone_; zone++)
	{
		f_dest << "# ZONE: " << nom_zone.at(zone) << endl;
		for (unsigned int tic=0; tic < nb_tic_; tic++){
			f_dest << tic << "\t"
					<<data_.at(zone).at(tic).at(VALPHEN) << "\t"
					<< data_.at(zone).at(tic).at(VALCTRL) << "\t"
					<< data_.at(zone).at(tic).at(ETAT_COURANT) << endl;


		}
	}
	f_dest.close();
	return nom_fichier_;
}
vector<double> Serveur::run(vector<double> param){
	(data_.at(zone_courante_)).push_back(param);
	zone_courante_++;
	if (zone_courante_==nb_zone_){
		zone_courante_=0;
		nb_tic_++;
	}
	return param;
}

} /* namespace Domotique */

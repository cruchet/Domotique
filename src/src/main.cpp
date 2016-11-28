/*
 * main.cpp
 *
 *  Created on: 21 nov. 2016
 *      Author: Vassili & Jordan
 */

#include <vector>
#include <list>
#include <string>
#include <stdio.h>
#include <iostream>
#include <ctime>

#include "../src/Serveur.h"
#include "../src/Sim.h"
#include "../src/Processus.h"
#include "../src/Control.h"
#include "../src/Etat.h"
#include "../src/Phenomene.h"
#include "../src/tinyxml_epfl/tinyxml.h"
#include "../src/tinyxml_epfl/xml_utils.h"

using namespace Domotique;

void lecture_xml(string nom_fichier,vector<vector<Processus*> >* paysage,
		vector<string>* nom_zone, vector<double>* etat_initial);

int main(void) {
	srand(std::time(NULL));
	vector<vector<Processus*> > paysage;
	vector<string> nom_zone;
	vector<double> etat_initial;
	lecture_xml("paysage.xml", paysage*, nom_zone*, etat_initial*);

	//----- Creation du simulateur et lancement de la simulation ------//
	Sim * sim = new Sim(paysage, paysage.size(), 2);

	vector<double> setting;
	setting.push_back(paysage.size()); //nb_zone
	Serveur * serveur = new Serveur("Serveur", setting);
	string out_file = sim->run(serveur, nom_zone);

	return 0;
}

void lecture_xml(string nom_fichier,vector<vector<Processus*> >* paysage,
		vector<string>* nom_zone, vector<double>* etat_initial){


}

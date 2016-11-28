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

#include "Control.h"
#include "Etat.h"
#include "Phenomene.h"
#include "Processus.h"
#include "Serveur.h"
#include "Sim.h"
#include "tinyxml_epfl/tinyxml.h"
#include "tinyxml_epfl/xml_utils.h"
#include "Parser.h"


using namespace Domotique;

int main(void) {
	std::srand(std::time(NULL));

	//----- Lecture du fichier xml et creation du paysage -----//
	Parser parser("payage.xml");
	vector<vector<Processus*> > paysage = parser.get_paysage();
	vector<string> nom_zone = parser.get_nom_zone();


	//----- Creation du simulateur et lancement de la simulation ------//
	Sim * sim = new Sim(paysage, paysage.size(), 2);

	vector<double> setting;
	setting.push_back(paysage.size()); //nb_zone
	Serveur * serveur = new Serveur("Serveur", setting);
	string out_file = sim->run(serveur, nom_zone);

	return 0;
}

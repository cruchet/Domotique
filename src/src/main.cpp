/*
 * main.cpp
 *
 *  Created on: 21 nov. 2016
 *      Author: Vassili & Jordan
 */
//A envoyer: eytan.zysman@epfl.ch
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
#include "AParser.h"


using namespace Domotique;

int main(void) {
	srand(std::time(NULL));

	//----- Lecture du fichier xml et creation du paysage -----//
	AParser aparser("paysage.xml");
	vector<vector<Processus*> > paysage = aparser.get_paysage();
	vector<string> nom_zone = aparser.get_nom_zone();


	//----- Creation du simulateur et lancement de la simulation ------//
	Sim * sim = new Sim(paysage, paysage.size(), 2);

	vector<double> setting;
	setting.push_back(paysage.size()); //nb_zone
	Serveur * serveur = new Serveur("Serveur", setting);
	string out_file = sim->run(serveur, nom_zone);

	return 0;
}

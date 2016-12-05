/*
 * main.cpp
 *
 *  Created on: 21 nov. 2016
 *      Author: Vassili & Jordan
 */

#include "Sim.h"
#include "Parser.h"


#include <vector>
#include <list>
#include <string>
#include <stdio.h>
#include <iostream>
#include <ctime>

using namespace Domotique;

int main(void) {
	srand(std::time(NULL));
	unsigned int nb_tic;
	string nom_fichier = "paysage.xml";

	//----- Creation du simulateur et lancement de la simulation ------//
	Sim * sim = new Sim(nb_tic);
	lecture_xml(nom_fichier, &nb_tic, sim);

	sim->run();

	return 0;
}


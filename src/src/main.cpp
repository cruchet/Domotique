/*
 * main.cpp
 *
 *  Created on: 21 nov. 2016
 *      Author: Vassili & Jordan
 */

#include "Sim.h"
#include "Parser.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctime>

using namespace Domotique;
void lecture_xml(string nom_fichier, unsigned int* nb_tic, Sim* simulateur);

int main(void) {
	srand(std::time(NULL));
	unsigned int nb_tic = 100;
	string nom_fichier = "paysage.xml";

	//----- Creation du simulateur et lancement de la simulation ------//
	Sim * sim = new Sim();
	lecture_xml(nom_fichier, &nb_tic, sim);
	sim->init(nb_tic);

	sim->run();

	return 0;
}

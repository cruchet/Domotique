/*
 * main.cpp
 *
 *  Created on: 21 nov. 2016
 *      Author: Vassili & Jordan
 */

#include "Sim.h"
#include "Parser.h"

#include "Serveur.h"
#include "Sim.h"
#include "Processus.h"
#include "Control_ON_OFF.h"
#include "Control_prop.h"
#include "Etat.h"
#include "Phenomene_sinus.h"
#include "Phenomene_pulse.h"

#include <vector>
#include <list>
#include <string>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <stdio.h>
#include <iostream>
#include <ctime>

using namespace Domotique;
void lecture_xml(string nom_fichier, unsigned int* nb_tic, Sim* simulateur);

int main(void) {
	srand(std::time(NULL));
	unsigned int nb_tic = 100;
	string nom_fichier = "paysage.xml";

	//----- Creation du simulateur et lancement de la simulation ------//
	Sim * sim = new Sim(nb_tic);
	lecture_xml(nom_fichier, &nb_tic, sim);

	sim->run();

	return 0;
}


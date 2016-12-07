/*
 * Control.cpp
 *
 *  Created on: 14 nov. 2016
 *      Author: Vassili
 */

#include "Control.h"

#include <iostream>

using namespace std;

namespace Domotique {

Control::Control(string nom):
		Processus(nom), p_serveur_(NULL), p_etat_(NULL) {}

Control::~Control() {}

void Control::init(Serveur* p_serveur, Etat* p_etat)
{
	cout << "[Control] Initialisation de "<< nom_ << endl;
	p_serveur_=p_serveur;
	p_etat_=p_etat;
}
} /* namespace Domotique */

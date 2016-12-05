/*
 * Etat.cpp
 *
 *  Created on: 14 nov. 2016
 *      Author: Vassili
 */

#include "Etat.h"

#include <vector>
#include <iostream>

namespace Domotique {

Etat::Etat(string nom): Processus(nom), Iphen_(0), Ictrl_(0),
		valphen_(0), etat_(0), valctrl_(0){
	cout << "[Etat] Création de "<< nom << endl;
}

Etat::~Etat() {}

void Etat::run(void) {
	etat_ = etat_+(valphen_-etat_)*Iphen_+(valctrl_ - etat_) * Ictrl_;
}

void Etat::init(double Iphen, double Ictrl, double etat_init):
Iphen_(Iphen), Ictrl_(Ictrl), valphen_(0), etat_(etat_init), valctrl_(0){
	cout << "[Etat] Initialisation de "<<nom_<<endl;
}

} /* namespace Domotique */

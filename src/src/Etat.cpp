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

Etat::Etat(string nom): Processus(nom), Iphen_(0), Ictrl_(0), etat_init_(0),
		valphen_(0), etat_(0), valctrl_(0){
	cout << "[Etat] Création de "<< nom << endl;
}

Etat::~Etat() {}

void Etat::run(void) {
	param.at(ETAT_COURANT)= calcul_etat_eff(param);
	return param;
}

void Etat::init(double Iphen, double Ictrl, double etat_init):
Iphen_(Iphen), Ictrl_(Ictrl), etat_(etat_init){
	cout << "[Etat] Initialisation de "<<nom_<<endl;
}

double Etat::calcul_etat_eff(vector<double> param) {
	double Iphen = (this->get_setting()).at(0);
	double Ictrl = (this->get_setting()).at(1);
	double etat_eff = param.at(ETAT_COURANT)
					+ (param.at(VALPHEN) - param.at(ETAT_COURANT))*Iphen
					+ (param.at(VALCTRL) - param.at(ETAT_COURANT))*Ictrl;
	return etat_eff;
}
} /* namespace Domotique */

/*
 * Etat.cpp
 *
 *  Created on: 14 nov. 2016
 *      Author: Vassili
 */

#include "../src/Etat.h"

#include <vector>
#include <iostream>
#include "../src/Processus.h"

namespace Domotique {

Etat::Etat(string nom, vector<double> setting):
	Processus(nom, "etat", setting) {}

double Etat::calcul_etat_eff(vector<double> param) {
	double Iphen = (this->get_setting()).at(0);
	double Ictrl = (this->get_setting()).at(1);
	double etat_eff = param.at(ETAT_COURANT)
					+ (param.at(VALPHEN) - param.at(ETAT_COURANT))*Iphen
					+ (param.at(VALCTRL) - param.at(ETAT_COURANT))*Ictrl;
	return etat_eff;
}

vector<double> Etat::run(vector<double> param) {
	param.at(ETAT_COURANT)= calcul_etat_eff(param);
	return param;
}
Etat::~Etat() {}

} /* namespace Domotique */

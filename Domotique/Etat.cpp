/*
 * Etat.cpp
 *
 *  Created on: 14 nov. 2016
 *      Author: Vassili
 */

#include "Processus.h"
#include "Etat.h"
#include <vector>

namespace Domotique {

Etat::Etat(string nom, double Iphen, double Ictrl):
	Processus("etat", nom), Iphen_(Iphen), Ictrl_(Ictrl) {}

double Etat::calcul_etat_eff(vector<double> param) {

	double etat_eff = param.at(ETAT_COURANT)
					+ (param.at(VALPHEN) - param.at(ETAT_COURANT))*Iphen_
					+ (param.at(VALCTRL) - param.at(ETAT_COURANT))*Ictrl_;
	return etat_eff;
}

void Etat::run() {
	vector<double> param = this->get_param();

	param.at(ETAT_COURANT)= calcul_etat_eff(param);
	this->set_param(param);
}
Etat::~Etat() {}

} /* namespace Domotique */

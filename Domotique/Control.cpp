/*
 * Control.cpp
 *
 *  Created on: 14 nov. 2016
 *      Author: Vassili
 */

#include "Processus.h"
#include "Control.h"
#include "Etat.h"

using namespace std;

namespace Domotique {

Control::Control(): Processus("ctrl"), valsat_(10) {}

void Control::run(void) {
	vector<double> param=this->get_param();

	param.at(VALCTRL) = calcul_valctrl(param.at(ETAT_COURANT));

	this->set_param(param);
}
double Control::calcul_valctrl(double etat_courant) {
	double valctrl;
	if(etat_courant > valsat_)
		valctrl = valsat_;
	else
		valctrl = etat_courant;
	return valctrl;
}

Control::~Control() {}

} /* namespace Domotique */

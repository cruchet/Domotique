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

/*vector<double> Control::run(vector<double> param) {
	param.at(VALCTRL) = calcul_valctrl(param.at(ETAT_COURANT));
	return param;
}*/

double Control::calcul_valctrl(double etat_courant) {
	vector<double> param_ctrl = this->get_setting();
	double valctrl;
	if (mode_ == "saturation"){
		double valsat = param_ctrl.at(0);
		if(etat_courant > valsat)
			valctrl = valsat;
		else
			valctrl = etat_courant;
		return valctrl;
	}
	else {return etat_courant;}

}

Control::~Control() {}

} /* namespace Domotique */

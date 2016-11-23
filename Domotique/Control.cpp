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

Control::Control(string nom, string mode, vector<double> setting_ctrl):
		Processus(nom, "ctrl", setting_ctrl), mode_(mode) {}

vector<double> Control::run(vector<double> param) {
	param.at(VALCTRL) = calcul_valctrl(param.at(ETAT_COURANT));
	return param;
}
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

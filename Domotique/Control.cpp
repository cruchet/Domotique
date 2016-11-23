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

Control::Control(string nom, string mode, vector<double> param_ctrl):
		Processus("ctrl", nom), mode_(mode), param_ctrl_(param_ctrl) {}

void Control::run(void) {
	vector<double> param=this->get_param();

	param.at(VALCTRL) = calcul_valctrl(param.at(ETAT_COURANT));

	this->set_param(param);
}
double Control::calcul_valctrl(double etat_courant) {
	double valctrl;
	if (mode_ == "saturation"){
		double valsat = param_ctrl_.at(0);
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

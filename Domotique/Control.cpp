/*
 * Control.cpp
 *
 *  Created on: 14 nov. 2016
 *      Author: Vassili
 */
/*heheeheh*/

#include "Processus.h"
#include "Control.h"
#include "Serveur.h"
#include "Etat.h"
namespace Domotique {

Control::Control(): Processus(), valphen_(0), etat_courant_(0), val_sat_(10) {}

void Control::run(double valphen, double etat_courant, Serveur &serveur, Etat &etat) {
	set_valphen(valphen);
	serveur.save_valphen(valphen);
	set_etat_courant(etat_courant);
	serveur.save_etat_courant(etat_courant);

	double valctrl = calcul_valctrl(etat_courant_);

	serveur.save_valctrl(valctrl);
	etat.set_valctrl(valctrl);
}
double Control::calcul_valctrl(double etat_courant) {
	double valctrl;
	if(etat_courant > val_sat_)
		valctrl = val_sat_;
	else
		valctrl = etat_courant;
	return valctrl;
}

Control::~Control() {}

} /* namespace Domotique */

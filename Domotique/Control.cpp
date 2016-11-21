/*
 * Control.cpp
 *
 *  Created on: 14 nov. 2016
 *      Author: Vassili
 */
/*heheeheh*/

#include "Processus.h"
#include "Control.h"
#include "Etat.h"

using namespace std;

namespace Domotique {

Control::Control(): Processus("ctrl"), etat_courant_(0), val_sat_(10) {}

void Control::run(void) {
	Serveur& serveur = static_cast<Serveur&>(this->get_refserveur());
	Etat& etat = static_cast<Etat&>(this->get_refetat());

	double valphen = etat.get_valphen();
	double etat_courant =etat.get_etat_courant();

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

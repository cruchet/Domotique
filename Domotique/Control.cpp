/*
 * Control.cpp
 *
 *  Created on: 14 nov. 2016
 *      Author: Vassili
 */
/*Je modifie contrôle*/
#include "Control.h"
#include "Serveur.h"
#include "Etat.h"
namespace Domotique {

Control::Control(): valphen_(0), etat_courant_(0), val_sat_(10) {}

void Control::run(double valphen, double etat_courant, Serveur &serveur, Etat &etat) {
	set_valphen(valphen);
	serveur.save_valphen(valphen);
	set_etat_courant(etat_courant);
	serveur.save_etat_courant(etat_courant);
	double val_ctrl = calcul_val_ctrl(etat_courant_);
	serveur.save_val_ctrl(val_ctrl);
	etat.set_val_ctrl(val_ctrl);
}
double Control::calcul_val_ctrl(double etat_courant) {
	double val_ctrl;
	if(etat_courant > val_sat_)
		val_ctrl = val_sat_;
	else
		val_ctrl = etat_courant;
	return val_ctrl;
}

Control::~Control() {}

} /* namespace Domotique */

/*
 * Etat.cpp
 *
 *  Created on: 14 nov. 2016
 *      Author: Vassili
 */

#include "Processus.h"
#include "Etat.h"

namespace Domotique {

Etat::Etat( double Iphen, double Ictrl):
	Processus(), valphen_(0), valctrl_(0), etat_courant_(0), Iphen_(Iphen), Ictrl_(Ictrl) {}

double Etat::calcul_etat_eff() {
	double etat_eff = etat_courant_ + (valphen_ - etat_courant_)*Iphen_
			   + (valctrl_ - etat_courant_)*Ictrl_;
	return etat_eff;
}

void Etat::run(double valphen) {
	set_valphen(valphen);
	etat_courant_= calcul_etat_eff(); //calcul du nouvel état
}
Etat::~Etat() {}

} /* namespace Domotique */

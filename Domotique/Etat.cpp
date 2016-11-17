/*
 * Etat.cpp
 *
 *  Created on: 14 nov. 2016
 *      Author: Vassili
 */

#include "Etat.h"
#include "Control.h"

namespace Domotique {

Etat::Etat( double Iphen, double Ictrl,):
	valphen_(0), val_ctrl_(0), etat_courant_(0), Iphen_(Iphen), Ictrl_(Ictrl) {}

double Etat::calcul_etat_eff() {
	double etat_eff = etat_courant_ + (valphen_ - etat_courant_)*Iphen_
			   + (val_ctrl_ - etat_courant_)*Ictrl_;
	return etat_eff;
}

void run(double valphen, Control &control) {

}
Etat::~Etat() {}

} /* namespace Domotique */

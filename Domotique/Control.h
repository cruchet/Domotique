/*
 * Control.h
 *
 *  Created on: 14 nov. 2016
 *      Author: Vassili
 */

#ifndef CONTROL_H_
#define CONTROL_H_
#include "Processus.h"
#include "Serveur.h"
#include "Etat.h"

namespace Domotique {

class Control: public Processus {
public:
	Control();
	virtual ~Control();
	void set_valphen(double valphen) {valphen_= valphen;}
	void set_etat_courant(double etat) {etat_courant_ = etat;}
	void run(double valphen, double etat_courant, Serveur &serveur, Etat &etat);
	double calcul_valctrl(double etat_courant);

private:
	double valphen_;
	double etat_courant_;
	const double val_sat_;
};

} /* namespace Domotique */

#endif /* CONTROL_H_ */

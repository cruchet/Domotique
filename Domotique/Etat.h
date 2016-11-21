/*
 * Etat.h
 *
 *  Created on: 14 nov. 2016
 *      Author: Vassili
 */

#ifndef ETAT_H_
#define ETAT_H_

#include "Control.h"
#include "Processus.h"

namespace Domotique {

class Etat: public Processus {
public:
	Etat(double Iphen, double Ictrl);
	virtual ~Etat();
	void set_valctrl(double valctrl) {valctrl_ = valctrl;}
	void set_valphen(double valphen) {valphen_ = valphen;}
	double get_etat_courant(void) {return etat_courant_;}
	double get_valphen(void) {return valphen_;}
	double calcul_etat_eff();
	void run(double valphen, Control &control);

private:
	double valphen_;
	double valctrl_;
	double etat_courant_;
	double Iphen_;
	double Ictrl_;
};

} /* namespace Domotique */

#endif /* ETAT_H_ */

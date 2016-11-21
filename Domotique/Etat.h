/*
 * Etat.h
 *
 *  Created on: 14 nov. 2016
 *      Author: Vassili
 */

#ifndef ETAT_H_
#define ETAT_H_

#include "Processus.h"

namespace Domotique {

class Etat: public Processus {
public:
	Etat(double Iphen, double Ictrl);
	virtual ~Etat();
	void set_valctrl(double valctrl) {valctrl_ = valctrl;}
	void set_valphen(double valphen) {this->set_valphen(valphen);}
	double get_etat_courant(void) {return etat_courant_;}
	double get_valphen(void) {return this->get_valphen();}
	double calcul_etat_eff();
	void run();

private:
	double valctrl_;
	double etat_courant_;
	double Iphen_;
	double Ictrl_;
};

} /* namespace Domotique */

#endif /* ETAT_H_ */

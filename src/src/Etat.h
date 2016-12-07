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
	Etat(string nom, double Iphen, double Ictrl, double etat_init);
	virtual ~Etat();
	void run(void);
	void put_valphen(double valphen);
	void put_valctrl(double valctrl);
	double get_etat(void){return etat_;};
	double get_phen(void){return valphen_;};
private:
	double Iphen_;
	double Ictrl_;
	double valphen_;
	double etat_;
	double valctrl_;
};

} /* namespace Domotique */

#endif /* ETAT_H_ */

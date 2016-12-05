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
	Etat(string nom);
	virtual ~Etat();
	void run(void);
	void init(double Iphen, double Ictrl, double etat_init);
	void put_valphen(double valphen);
	void put_valctrl(double valctrl);
private:
	double Iphen_;
	double Ictrl_;
	double valphen_;
	double etat_;
	double valctrl_;
};

} /* namespace Domotique */

#endif /* ETAT_H_ */

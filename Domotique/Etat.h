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
	double calcul_etat_eff(vector<double> param);
	void run();

private:
	double Iphen_;
	double Ictrl_;
};

} /* namespace Domotique */

#endif /* ETAT_H_ */

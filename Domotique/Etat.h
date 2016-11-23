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
	Etat(string nom, double Iphen, double Ictrl);
	virtual ~Etat();
	void run();

private:
	double Iphen_;
	double Ictrl_;
	double calcul_etat_eff(vector<double> param);
};

} /* namespace Domotique */

#endif /* ETAT_H_ */

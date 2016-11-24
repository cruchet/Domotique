/*
 * Etat.h
 *
 *  Created on: 14 nov. 2016
 *      Author: Vassili
 */

#ifndef ETAT_H_
#define ETAT_H_

#include "../src/Processus.h"

namespace Domotique {

class Etat: public Processus {
public:
	Etat(string nom, vector<double> setting);
	virtual ~Etat();
	vector<double> run(vector<double> param);

private:
	double calcul_etat_eff(vector<double> param);
};

} /* namespace Domotique */

#endif /* ETAT_H_ */

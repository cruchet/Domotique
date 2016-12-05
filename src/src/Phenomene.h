/*
 * Phenomene.h
 *
 *  Created on: 14 nov. 2016
 *      Author: jordanmetz
 */

#ifndef PHENOMENE_H_
#define PHENOMENE_H_
#include "Processus.h"

namespace Domotique {

class Phenomene: public Processus{
public:
	Phenomene(string nom, string mode, vector<double> setting);
	virtual ~Phenomene();
	double get_valphen(){return 0;}
	vector<double> run(vector<double> param);
	virtual double calcul_valphen() = 0;
private:
	string modephen_;
};

} /* namespace Domotique */

#endif /* PHENOMENE_H_ */

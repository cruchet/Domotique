/*
 * Phenomene.h
 *
 *  Created on: 14 nov. 2016
 *      Author: jordanmetz
 */

#ifndef PHENOMENE_H_
#define PHENOMENE_H_
#include "../src/Processus.h"

namespace Domotique {

class Phenomene: public Processus{
public:
	Phenomene(string nom, string mode, vector<double> setting);
	virtual ~Phenomene();
	vector<double> run(vector<double> param);
private:
	double calcul_valphen();
	string modephen_;
};

} /* namespace Domotique */

#endif /* PHENOMENE_H_ */

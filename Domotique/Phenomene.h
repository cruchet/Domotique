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
	Phenomene(string nom, string type, vector<double> setting);
	virtual ~Phenomene();
	double get_valphen(){return 0;}
	vector<double> run(vector<double> param);
private:
	double calcul_valphen();
	string typephen_;
};

} /* namespace Domotique */

#endif /* PHENOMENE_H_ */

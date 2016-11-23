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
	Phenomene(string nom, string type, vector<double> phen_param);
	virtual ~Phenomene();
	void set_phen_param(vector<double> phen_param){phen_param_=phen_param;};
	vector<double> get_phen_param(){return phen_param_;};
	double get_valphen(){return 0;}
	void run(void);
private:
	double calcul_valphen();
	string typephen_;
	vector<double> phen_param_;
};

} /* namespace Domotique */

#endif /* PHENOMENE_H_ */

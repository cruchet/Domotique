/*
 * Phenomene.h
 *
 *  Created on: 14 nov. 2016
 *      Author: jordanmetz
 */

#ifndef PHENOMENE_H_
#define PHENOMENE_H_
#include "Processus.h"
#include "Etat.h"
#include <cassert>
#include <math.h>

namespace math_const{
	const double PI=3.14151696;
	const double SIGMA = 0.2;
};
namespace Domotique {

class Phenomene: public Processus{
public:
	Phenomene(string nom);
	virtual ~Phenomene();
	void init(Etat* p_etat);
protected:
	double box_mull(double val);
	Etat* p_etat_;
};

} /* namespace Domotique */

#endif /* PHENOMENE_H_ */

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
	Phenomene(double valmin, double valmax);
	virtual ~Phenomene();
	void set_valmin(double valmin){valmin_=valmin;};
	void set_valmax(double valmax){valmax_=valmax;};
	double get_valmin(){return valmin_;};
	double get_valmax(){return valmax_;};
	double genere(void);
private:
	double valmin_;
	double valmax_;
};

} /* namespace Domotique */

#endif /* PHENOMENE_H_ */

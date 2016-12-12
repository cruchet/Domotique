/*
 * Phenomene_sinus.h
 *
 *  Created on: 5 déc. 2016
 *      Author: Jordan Metz & Vassili Cruchet
 */

#ifndef SRC_PHENOMENE_SINUS_H_
#define SRC_PHENOMENE_SINUS_H_

#include "Phenomene.h"
#include <vector>
#include <limits>

namespace Domotique {

class Phenomene_sinus: public Phenomene {
public:
	Phenomene_sinus(string nom, double ampl, long int period,
			double sat_max, double sat_min,double offs, long int phase);
	virtual ~Phenomene_sinus();
	void run(int tic);
private:
	double ampl_;
	long int period_;
	double sat_max_;
	double sat_min_;
	double offs_;
	long int phase_;
};

} /* namespace Domotique */

#endif /* SRC_PHENOMENE_SINUS_H_ */

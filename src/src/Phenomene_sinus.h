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
			double offs = 0.0, long int phase=0,
			double sat_max= std::numeric_limits<double>::infinity(),
			double sat_min = -1* std::numeric_limits<double>::infinity());
	virtual ~Phenomene_sinus();
	void run(int tic);
private:
	double ampl_;
	long int period_;
	double offs_;
	long int phase_;
	double sat_max_;
	double sat_min_;
};

} /* namespace Domotique */

#endif /* SRC_PHENOMENE_SINUS_H_ */

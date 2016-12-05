/*
 * Phenomene_pulse.h
 *
 *  Created on: 5 déc. 2016
 *      Author: jordanmetz
 */

#ifndef SRC_PHENOMENE_PULSE_H_
#define SRC_PHENOMENE_PULSE_H_

namespace Domotique {

class Phenomene_pulse: Phenomene {
public:
	Phenomene_pulse();
	virtual ~Phenomene_pulse();
	double calcul_valphen();
};

} /* namespace Domotique */

#endif /* SRC_PHENOMENE_PULSE_H_ */

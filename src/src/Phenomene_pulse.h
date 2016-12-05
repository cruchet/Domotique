/*
 * Phenomene_pulse.h
 *
 *  Created on: 5 déc. 2016
 *      Author: jordanmetz
 */

#ifndef SRC_PHENOMENE_PULSE_H_
#define SRC_PHENOMENE_PULSE_H_

#include "Phenomene.h"

namespace Domotique {

class Phenomene_pulse: Phenomene {
public:
	Phenomene_pulse(string nom);
	virtual ~Phenomene_pulse();
	double calcul_valphen();
	void run(void);
	void init(Etat* p_etat, double v_low, double v_high, long int t_del,
				long int t_rise, long int pwidth, long int t_fall, long int period);
private:
	double v_low_;
	double v_high_;
	long int t_del_;
	long int t_rise_;
	long int pwidth_;
	long int t_fall_;
	long int period_;
};

} /* namespace Domotique */

#endif /* SRC_PHENOMENE_PULSE_H_ */

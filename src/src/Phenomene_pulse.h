/*
 * Phenomene_pulse.h
 *
 *  Created on: 5 déc. 2016
 *      Author: jordanmetz
 */

#ifndef SRC_PHENOMENE_PULSE_H_
#define SRC_PHENOMENE_PULSE_H_

#include "Phenomene.h"
#include <vector>

namespace Domotique {

class Phenomene_pulse: Phenomene {
public:
	Phenomene_pulse(string nom);
	virtual ~Phenomene_pulse();
	double calcul_valphen();
	void run(void);
	void init(Etat* p_etat, vector<double> param);
	enum pulse_param{V_LOW,V_HIGH,T_DEL,T_RISE,PWIDTH,T_FALL,PERIOD};
private:
	vector<double> param_;
};

} /* namespace Domotique */

#endif /* SRC_PHENOMENE_PULSE_H_ */

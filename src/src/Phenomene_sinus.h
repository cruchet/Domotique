/*
 * Phenomene_sinus.h
 *
 *  Created on: 5 déc. 2016
 *      Author: jordanmetz
 */

#ifndef SRC_PHENOMENE_SINUS_H_
#define SRC_PHENOMENE_SINUS_H_

#include "Phenomene.h"
#include <vector>

namespace Domotique {

class Phenomene_sinus: public Phenomene {
public:
	Phenomene_sinus(string nom);
	virtual ~Phenomene_sinus();
	void run(void);
	void init(Etat* p_etat, vector<double> param);
	enum pulse_param{OFFS,AMPL,PHASE,PERIOD,SAT_MAX,SAT_MIN};
private:
	vector<double> param_;
};

} /* namespace Domotique */

#endif /* SRC_PHENOMENE_SINUS_H_ */

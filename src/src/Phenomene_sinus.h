/*
 * Phenomene_sinus.h
 *
 *  Created on: 5 déc. 2016
 *      Author: jordanmetz
 */

#ifndef SRC_PHENOMENE_SINUS_H_
#define SRC_PHENOMENE_SINUS_H_

namespace Domotique {

class Phenomene_sinus: public Phenomene {
public:
	Phenomene_sinus();
	virtual ~Phenomene_sinus();
	double calcul_valphen();
};

} /* namespace Domotique */

#endif /* SRC_PHENOMENE_SINUS_H_ */

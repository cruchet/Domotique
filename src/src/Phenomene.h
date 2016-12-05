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

namespace Domotique {

class Phenomene: public Processus{
public:
	Phenomene(string nom);
	virtual ~Phenomene();
private:
	Etat* p_etat_;
};

} /* namespace Domotique */

#endif /* PHENOMENE_H_ */

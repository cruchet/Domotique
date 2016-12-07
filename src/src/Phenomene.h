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

namespace Domotique {

class Phenomene: public Processus{
public:
	Phenomene(string nom);
	virtual ~Phenomene();
	void init(Etat* p_etat);
protected:
	Etat* p_etat_;
};

} /* namespace Domotique */

#endif /* PHENOMENE_H_ */

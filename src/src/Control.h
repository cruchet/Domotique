/*
 * Control.h
 *
 *  Created on: 14 nov. 2016
 *      Author: Vassili
 */

#ifndef CONTROL_H_
#define CONTROL_H_

#include "Processus.h"
#include "Serveur.h"
#include "Etat.h"

namespace Domotique {

class Control: public Processus {
public:
	Control(string nom);
	virtual ~Control();
protected:
	Serveur* p_serveur_;
	Etat* p_etat_;

	double calcul_valctrl(double etat_courant);
};

} /* namespace Domotique */

#endif /* CONTROL_H_ */

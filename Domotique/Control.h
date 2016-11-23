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
	Control();
	virtual ~Control();
	void run(void);
	double calcul_valctrl(double etat_courant);
	void set_valsat(double valsat){valsat_=valsat;};
private:
	double valsat_;
};

} /* namespace Domotique */

#endif /* CONTROL_H_ */

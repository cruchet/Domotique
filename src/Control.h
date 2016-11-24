/*
 * Control.h
 *
 *  Created on: 14 nov. 2016
 *      Author: Vassili
 */

#ifndef CONTROL_H_
#define CONTROL_H_
#include "../src/Etat.h"
#include "../src/Processus.h"
#include "../src/Serveur.h"

namespace Domotique {

class Control: public Processus {
public:
	Control(string nom, string mode, vector<double> param_ctrl);
	virtual ~Control();
	vector<double> run(vector<double> param);
private:
	string mode_;

	double calcul_valctrl(double etat_courant);
};

} /* namespace Domotique */

#endif /* CONTROL_H_ */

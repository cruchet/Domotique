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
	Control(string nom, string mode, vector<double> param_ctrl);
	virtual ~Control();
	void run(void);
	double calcul_valctrl(double etat_courant);
	vector<double> get_param_ctrl(void){return param_ctrl_;};
	void set_param_ctrl(vector<double> param_ctrl){param_ctrl_=param_ctrl;};
private:
	string mode_;
	vector<double> param_ctrl_;
};

} /* namespace Domotique */

#endif /* CONTROL_H_ */

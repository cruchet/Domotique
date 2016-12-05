/*
 * Etat.h
 *
 *  Created on: 14 nov. 2016
 *      Author: Vassili
 */

#ifndef ETAT_H_
#define ETAT_H_

#include "Processus.h"

namespace Domotique {

class Etat: public Processus {
public:
	Etat(string nom);
	virtual ~Etat();
	void run(void);
	void put_valphen(double valphen);
	void put_valctrl(double valctrl);
	void init(vector<double> param);
	enum param_etat{IPHEN,ICTRL,VALPHEN_INIT,ETAT_INIT, VALCTRL_INIT};
private:
	double Iphen_;
	double Ictrl_;
	double valphen_init;
	double etat_init;
	double valctrl_init;
	double valphen_;
	double etat_;
	double valctrl_;
	double calcul_etat_eff();

};

} /* namespace Domotique */

#endif /* ETAT_H_ */

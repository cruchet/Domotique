/*
 * Processus.h
 *
 *  Created on: 14 nov. 2016
 *      Author: jordanmetz
 */

#ifndef PROCESSUS_H_
#define PROCESSUS_H_
#include <string>
namespace Domotique {
using namespace std;

class Processus {
public:
	Processus(string type);
	virtual ~Processus();
	virtual void run() =0;

	string get_type(void){return type_;};
	double get_valphen(void){return valphen_;};
	double get_etat_courant(void){return etat_courant_;};
	double get_valctrl(void){return valctrl_;};

	void set_valphen(double valphen){valphen_=valphen;};
	void set_etat_courant(double etat_courant){etat_courant_=etat_courant;};
	void set_valctrl(double valctrl){valctrl_=valctrl;};

private:
	string type_;
	double valphen_;
	double etat_courant_;
	double valctrl_;
};

} /* namespace Domotique */

#endif /* PROCESSUS_H_ */

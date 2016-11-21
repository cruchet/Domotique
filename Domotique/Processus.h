/*
 * Processus.h
 *
 *  Created on: 14 nov. 2016
 *      Author: jordanmetz
 */

#ifndef PROCESSUS_H_
#define PROCESSUS_H_
#include <string.h>
namespace Domotique {
using namespace std;

class Processus {
public:
	Processus(string type);
	virtual ~Processus();
	virtual void run() =0;

	string get_type(void){return type_;};
	double get_valphen(void){return valphen_;};
	Processus& get_refphen(){return refphen_;};
	Processus& get_refetat(){return refetat_;};
	Processus& get_refctrl(){return refctrl_;};
	Processus& get_refserveur(){return refserveur_;};

	void set_valphen(double valphen){valphen_=valphen;};
	void set_refphen(Processus& ref){refphen_ =ref;};
	void set_refetat(Processus& ref){refetat_ =ref;};
	void set_refctrl(Processus& ref){refctrl_ =ref;};
	void set_refserveur(Processus& ref){refserveur_ =ref;};

private:
	string type_;
	double valphen_;
	Processus& refphen_;
	Processus& refetat_;
	Processus& refctrl_;
	Processus& refserveur_;
};

} /* namespace Domotique */

#endif /* PROCESSUS_H_ */

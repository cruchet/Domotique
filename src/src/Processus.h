/*
 * Processus.h
 *
 *  Created on: 14 nov. 2016
 *      Author: jordanmetz
 */

#ifndef PROCESSUS_H_
#define PROCESSUS_H_
#include <string>
#include <vector>

namespace Domotique {
using namespace std;

class Processus {
public:
	Processus(string nom, string type, vector<double> setting);
	virtual ~Processus();
	virtual vector<double> run(vector<double> param) = 0;
	string get_type(void){return type_;};
	vector<double> get_setting(void){return setting_;};
	void set_setting(vector<double> setting){setting_=setting;};


	enum Param_id {VALPHEN, VALCTRL, ETAT_COURANT};
private:
	string nom_;
	string type_;
	vector<double> setting_;

};

} /* namespace Domotique */

#endif /* PROCESSUS_H_ */

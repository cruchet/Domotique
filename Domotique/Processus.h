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
	vector<double> get_param(void){return param_;};
	void set_param(vector<double> param){param_=param;};
private:
	string type_;
	vector<double> param_;
};

} /* namespace Domotique */

#endif /* PROCESSUS_H_ */

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
	Processus(string nom);
	virtual ~Processus();
	virtual void run(void) = 0;
	virtual void init(vector<double> param) = 0;
private:
	string nom_;

};

} /* namespace Domotique */

#endif /* PROCESSUS_H_ */

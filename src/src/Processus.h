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
	virtual void run(int tic) = 0;
protected:
	string nom_;

};

} /* namespace Domotique */

#endif /* PROCESSUS_H_ */

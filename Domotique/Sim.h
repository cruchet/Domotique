/*
 *  Sim.h
 *
 *  Created on: 14 nov. 2016
 *      Author: Vassili
 */

#ifndef SIM_H_
#define SIM_H_

#include "Processus.h"
#include <vector>

using namespace std;

namespace Domotique {

class Sim {
public:
	Sim(unsigned int max_tic);
	virtual ~Sim();
	void run(void);

private:
	const int ntic;
	unsigned int tic;

};

} /* namespace Domotique */

#endif /* SIM_H_ */

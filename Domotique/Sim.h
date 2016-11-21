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
	int ntic;
	unsigned int tic;
	vector<Processus*> process_;
};

} /* namespace Domotique */

#endif /* SIM_H_ */

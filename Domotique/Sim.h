/*
 *  Sim.h
 *
 *  Created on: 14 nov. 2016
 *      Author: Vassili
 */

#ifndef SIM_H_
#define SIM_H_

#include <vector>
#include "Processus.h"
#include "Serveur.h"

using namespace std;

namespace Domotique {

class Sim {
public:
	Sim(unsigned int max_tic);
	virtual ~Sim();
	void run(Serveur& serveur);
	enum sim_id {PHEN, ETAT, CTRL};
private:
	unsigned int ntic_;
	unsigned int tic_;
	vector<Processus*>  process_;
};

} /* namespace Domotique */

#endif /* SIM_H_ */

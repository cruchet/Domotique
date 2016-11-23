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
	Sim(vector< vector<Processus*> > process_, int nb_zone, unsigned int max_tic);
	virtual ~Sim();
	string run(Serveur* serveur);
	enum sim_id {PHEN, ETAT, CTRL};
private:
	vector< vector<Processus*> > process_;
	int nb_zone_;
	unsigned int ntic_;
	unsigned int tic_;
};

} /* namespace Domotique */

#endif /* SIM_H_ */

/*
 *  Sim.h
 *
 *  Created on: 14 nov. 2016
 *      Author: Vassili
 */

#ifndef SIM_H_
#define SIM_H_

#include "Processus.h"
#include "Serveur.h"

using namespace std;

namespace Domotique {

class Sim {
public:
	Sim(unsigned int max_tic);
	virtual ~Sim();

	//gere la simulation et retourne le nom du fichier de sortie
	void run(void);
	void set_process (Processus* process){process_.push_back(process);};

private:
	vector<Processus*> process_;
	int nb_zone_;
	unsigned int ntic_;
	unsigned int tic_;
};

} /* namespace Domotique */

#endif /* SIM_H_ */

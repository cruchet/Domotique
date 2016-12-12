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
	Sim(void);
	virtual ~Sim();

	//gere la simulation et retourne le nom du fichier de sortie
	void run(void);
	void set_process (Processus* process){process_.push_back(process);};
	void init(unsigned int max_tic);
private:
	vector<Processus*> process_;
	unsigned int ntic_;
	unsigned int tic_;
};

} /* namespace Domotique */

#endif /* SIM_H_ */

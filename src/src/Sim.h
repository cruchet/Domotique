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
	Sim(vector< vector<Processus*> > process_, int nb_zone, unsigned int max_tic);
	virtual ~Sim();
	string run(Serveur* serveur,vector<string> nom_zone); //gere la simulation et retourne le nom du fichier de sortie
	enum Sim_id {PHEN, CTRL, ETAT};
private:
	vector< vector<Processus*> > process_;
	int nb_zone_;
	unsigned int ntic_;
	unsigned int tic_;
};

} /* namespace Domotique */

#endif /* SIM_H_ */

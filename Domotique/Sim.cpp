/*
 * Sim.cpp
 *
 *  Created on: 14 nov. 2016
 *      Author: Vassili
 */

#include <vector>
#include <string>
#include "Sim.h"
#include "Processus.h"
#include "Serveur.h"
using namespace std;

namespace Domotique {

Sim::Sim(vector< vector<Processus*> > process, int nb_zone, unsigned int max_tic):
		process_(process), nb_zone_(nb_zone), ntic_(max_tic), tic_(0){}

Sim::~Sim() {
	// TODO Auto-generated destructor stub
}

string Sim::run(Serveur* serveur) {
	vector<double> param;
	for(tic_=0; tic_<=ntic_;tic_++) {
		// execution des processus:
		for (int zone=0; zone < nb_zone_; zone++)
		{
			for(unsigned int i=0;i<process_.size(); i++){
				param = ((process_.at(zone)).at(i))->run(param);
				if (i==CTRL){
					param=serveur->run(param);
				}
			}
		}


	}
	return serveur->ecriture();
}

} /* namespace Domotique */


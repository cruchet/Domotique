/*
 * Sim.cpp
 *
 *  Created on: 14 nov. 2016
 *      Author: Vassili
 */

#include <vector>
#include "Sim.h"
#include "Processus.h"
#include "Serveur.h"
using namespace std;

namespace Domotique {

Sim::Sim(unsigned int max_tic): ntic_(max_tic), tic_(0){ process_(0);}

Sim::~Sim() {
	// TODO Auto-generated destructor stub
}

void Sim::run(Serveur& serveur) {
	vector<double> param;
	for(tic_=0; tic_<=ntic_;tic_++) {
		// execution des processus:
		for(int i=0;i<process_.size(); i++){
			(process_.at(i)).set_param(param);
			(process_.at(i)).run();
			param=(process_.at(i)).get_param();
		}


	}
	serveur.run();

}

} /* namespace Domotique */


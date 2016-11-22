/*
 * Sim.cpp
 *
 *  Created on: 14 nov. 2016
 *      Author: Vassili
 */

#include "Sim.h"
#include "Processus.h"
#include <vector>
#include "Serveur.h"
using namespace std;

namespace Domotique {

Sim::Sim(unsigned int max_tic): ntic(max_tic), tic(0){ }

Sim::~Sim() {
	// TODO Auto-generated destructor stub
}

void Sim::run(Serveur& serveur) {
	vector<double> param;
	for(tic=0; tic<=ntic;tic++) {
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


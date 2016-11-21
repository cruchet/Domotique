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
	for(tic=0; tic<=ntic;tic++) {
		// execution des processus:
		(process_.at(tic)).run();
	}
	serveur.run();

}

} /* namespace Domotique */


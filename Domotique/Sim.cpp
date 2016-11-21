/*
 * Sim.cpp
 *
 *  Created on: 14 nov. 2016
 *      Author: Vassili
 */
//DANS MASTER?
#include "Sim.h"

namespace Domotique {

Sim::Sim(): ntic(100), tic(0){ }

Sim::~Sim() {
	// TODO Auto-generated destructor stub
}

void Sim::run() {
	for(tic=0; tic<=ntic;tic++) {
		// execution des processus: (ils sont par triplet dans vecteur(vecteur(processus)) )
	}
}

} /* namespace Domotique */


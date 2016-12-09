/*
 * Sim.cpp
 *
 *  Created on: 14 nov. 2016
 *      Author: Vassili
 */

#include "Sim.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

namespace Domotique {

Sim::Sim(unsigned int max_tic): ntic_(max_tic), tic_(0){}

Sim::~Sim() {}

void Sim::run(void) {
	cout << "#Lancement de la simulation:" << endl<<endl;

	for(tic_=0; tic_<=ntic_;tic_++) {
		for(unsigned int i=0; i<process_.size(); i++){
			(process_.at(tic_))->run(tic_);
		}
	}
}

} /* namespace Domotique */


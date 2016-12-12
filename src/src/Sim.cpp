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

Sim::Sim(void): ntic_(0), tic_(0){}

Sim::~Sim() {}

void Sim::run(void) {
	cout << "\n#Lancement de la simulation" << endl<<endl;

	for(tic_=0; tic_<ntic_;tic_++) {
		for(unsigned int i=0; i<process_.size(); i++){
			(process_.at(i))->run(tic_);
		}
	}
	cout << "#Fin de la simulation" << endl;
}

void Sim::init(unsigned int max_tic){
	ntic_=max_tic;
}

} /* namespace Domotique */


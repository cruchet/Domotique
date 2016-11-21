/*
 * Phenomene.cpp
 *
 *  Created on: 14 nov. 2016
 *      Author: jordanmetz
 */

#include "Phenomene.h"
#include <cstdlib>
#include <ctime>

namespace Domotique {
using namespace std;

Phenomene::Phenomene(double valmin, double valmax):
	Processus("phen"), valmin_(valmin), valmax_(valmax) {
	// TODO Auto-generated constructor stub

}

Phenomene::~Phenomene() {
	// TODO Auto-generated destructor stub
}

void Phenomene::run(void){
	srand(time(0));
	double val= ( rand()/(double)RAND_MAX ) * (valmax_-valmin_) + valmin_;
	this->set_valphen(val);
	Processus& etat = this->get_refetat();
	etat.set_valphen(val);

}

} /* namespace Domotique */



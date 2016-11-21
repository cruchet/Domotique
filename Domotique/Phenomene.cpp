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
	Processus(), valmin_(valmin), valmax_(valmax), valphen_(0) {
	// TODO Auto-generated constructor stub

}

Phenomene::~Phenomene() {
	// TODO Auto-generated destructor stub
}

void Phenomene::run(void){
	srand(time(0));
	valphen_ = ( rand()/(double)RAND_MAX ) * (valmax_-valmin_) + valmin_;
}

} /* namespace Domotique */



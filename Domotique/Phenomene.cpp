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
	Processus(), valmin_(valmin), valmax_(valmax) {
	// TODO Auto-generated constructor stub

}

Phenomene::~Phenomene() {
	// TODO Auto-generated destructor stub
}

double Phenomene::genere(void){
	srand(time(NULL));
	double val = valmin_ + rand()/ valmax_;
	return 1;
}

} /* namespace Domotique */



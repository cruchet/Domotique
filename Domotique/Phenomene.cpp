/*
 * Phenomene.cpp
 *
 *  Created on: 14 nov. 2016
 *      Author: jordanmetz
 */

#include "Phenomene.h"
#include <cstdlib>
namespace Domotique {

Phenomene::Phenomene(double valmin, double valmax):
	valmin_(valmin), valmax_(valmax) {
	// TODO Auto-generated constructor stub

}

Phenomene::~Phenomene() {
	// TODO Auto-generated destructor stub
}

} /* namespace Domotique */

double Phenomene::genere(void){
	double val = valmin_ + rand() % valmax_;
	return 1;
}

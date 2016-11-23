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
	vector<double> param = this->get_param();

	param.at(VALPHEN)= calcul_valphen();

	this->set_param(param);
}
double Phenomene::calcul_valphen(void){
	srand(time(0));
	return ( rand()/(double)RAND_MAX ) * (valmax_-valmin_) + valmin_;
}

} /* namespace Domotique */



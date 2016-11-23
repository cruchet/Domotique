/*
 * Phenomene.cpp
 *
 *  Created on: 14 nov. 2016
 *      Author: jordanmetz
 */

#include "Phenomene.h"
#include <string>
#include <cstdlib>
#include <ctime>

namespace Domotique {
using namespace std;

Phenomene::Phenomene(string nom, string type, vector<double> phen_param):
	Processus("phen", nom),typephen_(type), phen_param_(phen_param) {
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
	if (typephen_ == "aleatoire")
	{
		srand(time(0));
		double valmin = phen_param_.at(0);
		double valmax = phen_param_.at(1);
		return ( rand()/(double)RAND_MAX ) * (valmax-valmin) + valmin;
	}
	else return 0;

}

} /* namespace Domotique */



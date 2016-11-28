/*
 * Phenomene.cpp
 *
 *  Created on: 14 nov. 2016
 *      Author: jordanmetz
 */

#include "../src/Phenomene.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

namespace Domotique {
using namespace std;

Phenomene::Phenomene(string nom, string mode, vector<double> setting):
	Processus(nom, "phen", setting),modephen_(mode) {std::srand(std::time(NULL));
	// TODO Auto-generated constructor stub

}

Phenomene::~Phenomene() {
	// TODO Auto-generated destructor stub
}

vector<double> Phenomene::run(vector<double> param){
	param.at(VALPHEN)=calcul_valphen();
	return param;
}
double Phenomene::calcul_valphen(void){
	vector<double> phen_param = this->get_setting();

	if (modephen_ == "aleatoire")
	{
		double valmin = phen_param.at(0);
		double valmax = phen_param.at(1);
		return ( rand()/(double)RAND_MAX ) * (valmax-valmin) + valmin;

	}
	else return 0;

}

} /* namespace Domotique */



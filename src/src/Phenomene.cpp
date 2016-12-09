/*
 * Phenomene.cpp
 *
 *  Created on: 14 nov. 2016
 *      Author: jordanmetz
 */

#include "Phenomene.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

namespace Domotique {
using namespace std;
using namespace math_const;
Phenomene::Phenomene(string nom): Processus(nom), p_etat_(NULL) {
	// TODO Auto-generated constructor stub

}

Phenomene::~Phenomene() {
	// TODO Auto-generated destructor stub
}
void Phenomene::init(Etat* p_etat)
{
	cout << "[Phenomene] Initilisation de "<< nom_ << endl;
	p_etat_=p_etat;
}
double Phenomene::box_mull(double val){
	double x1=(double)rand()/(double)RAND_MAX;
	double x2=(double)rand()/(double)RAND_MAX;
	double y= sqrt(-2*logl(x1))* cos((x2)*2*PI);
	double z = val + y * SIGMA;
	return z;
}

} /* namespace Domotique */



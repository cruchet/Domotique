/*
 * Phenomene_sinus.cpp
 *
 *  Created on: 5 déc. 2016
 *      Author: jordanmetz
 */

#include "Phenomene_sinus.h"
#include <iostream>
using namespace std;
namespace Domotique {

Phenomene_sinus::Phenomene_sinus(string nom): Phenomene(nom), ampl_(0), period_(0),
		sat_max_(0), sat_min_(0), offs_(0), phase_(0){
	cout<< "[Phenomene_sinus] Création de "<< nom << endl;
}

Phenomene_sinus::~Phenomene_sinus() {
	// TODO Auto-generated destructor stub
}
void Phenomene_sinus::init(Etat* p_etat, double ampl, long int period, double sat_max,
			  double sat_min, double offs = 0.0, long int phase=0)
{
	cout << "[Phenomene_sinus] Initilisation de "<< nom_ << endl;
	p_etat_=p_etat;ampl_=ampl;
	period_=period;
	sat_max_=sat_max;
	sat_min_=sat_min;offs_=offs;
	phase_=phase;
}

} /* namespace Domotique */

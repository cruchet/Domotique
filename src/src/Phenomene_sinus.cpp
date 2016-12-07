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

Phenomene_sinus::Phenomene_sinus(string nom, double ampl, long int period,
		double sat_max= std::numeric_limits<double>::infinity(),
		double sat_min = -1* std::numeric_limits<double>::infinity(),
		double offs = 0.0, long int phase=0): Phenomene(nom), ampl_(ampl), period_(period),
		sat_max_(sat_max), sat_min_(sat_min), offs_(offs), phase_(phase){
	cout<< "[Phenomene_sinus] Création de "<< nom << endl;
	assert(period >0);
}

Phenomene_sinus::~Phenomene_sinus() {
	// TODO Auto-generated destructor stub
}

} /* namespace Domotique */

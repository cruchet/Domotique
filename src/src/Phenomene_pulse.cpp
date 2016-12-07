/*
 * Phenomene_pulse.cpp
 *
 *  Created on: 5 déc. 2016
 *      Author: jordanmetz
 */

#include "Phenomene_pulse.h"
#include <iostream>

using namespace std;

namespace Domotique {

Phenomene_pulse::Phenomene_pulse(string nom, double v_low, double v_high, long int t_del,
		long int t_rise, long int pwidth, long int t_fall, long int period): Phenomene(nom),
				v_low_(v_low), v_high_(v_high), t_del_(t_del), t_rise_(t_rise),
				pwidth_(pwidth), t_fall_(t_fall), period_(period){
	cout << "[Phenomene_pulse] Création de " << nom << endl;
	assert(t_del >=0);
	assert(t_rise >=0);
	assert(pwidth >=0);
	assert(t_fall >=0);
	assert(period >0);
}

Phenomene_pulse::~Phenomene_pulse() {}
void Phenomene_pulse::run(void)
{
	// TODO Run
}

} /* namespace Domotique */

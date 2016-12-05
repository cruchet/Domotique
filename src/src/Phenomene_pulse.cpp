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

Phenomene_pulse::Phenomene_pulse(string nom): Phenomene(nom), v_low_(0), v_high_(0),
		t_del_(0), t_rise_(0), pwidth_(0), t_fall_(0), period_(0){
	cout << "[Phenomene_pulse] Création de " << nom << endl;
}

Phenomene_pulse::~Phenomene_pulse() {}

void Phenomene_pulse::init(Etat* p_etat, double v_low, double v_high, long int t_del,
							long int t_rise, long int pwidth, long int t_fall,
							long int period): p_etat_(p_etat), v_low_(0),
v_high_(0), t_del_(0), t_rise_(0), pwidth_(0), t_fall_(0), period_(0)
{
	cout << "[Phenomene_pulse] Initilisation de "<< nom_ << endl;
}

} /* namespace Domotique */

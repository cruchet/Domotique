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
void Phenomene_pulse::run(int tic)
{
	double y = 0;
	int tic_rel = (tic-t_del_)%period_;

	while(tic_rel < 0)
		tic_rel += period_;

	if (tic_rel < t_rise_) {
		if(t_rise_ > 0)
			y=v_low_ + ((v_high_-v_low_)/t_rise_) * tic_rel;
		else
			y=v_high_;
	}

	else if(tic_rel >= t_rise_ && tic_rel < (t_rise_+pwidth_))
		y=v_high_;

	else if(tic_rel >= (t_rise_+pwidth_) && tic_rel < (t_rise_+pwidth_+t_fall_)) {
		if(t_fall_ > 0)
			y=v_high_ - ((v_high_-v_low_)/t_fall_) * (tic_rel-(t_rise_ + pwidth_));
		else
			y=v_low_;
	}

	else if(tic_rel >= (t_rise_+pwidth_+t_fall_))
		y=v_low_;

	p_etat_->put_valphen(box_mull(y));
}

} /* namespace Domotique */

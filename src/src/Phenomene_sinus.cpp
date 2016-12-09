/*
 * Phenomene_sinus.cpp
 *
 *  Created on: 5 déc. 2016
 *      Author: jordanmetz
 */

#include "Phenomene_sinus.h"
#include <iostream>

using namespace std;
using namespace math_const;
namespace Domotique {

Phenomene_sinus::Phenomene_sinus(string nom, double ampl, long int period,
		double sat_max,
		double sat_min,
		double offs, long int phase): Phenomene(nom),  ampl_(ampl),
									period_(period), sat_max_(sat_max),
									sat_min_(sat_min), offs_(offs), phase_(phase){
	cout<< "[Phenomene_sinus] Création de "<< nom << endl;
	assert(period >0);
}

Phenomene_sinus::~Phenomene_sinus() {
	// TODO Auto-generated destructor stub
}
void Phenomene_sinus::run(int tic)
{
	double offs = box_mull(offs_);
	double ampl = box_mull(ampl_);
	double y = offs+ ampl*sin(2*PI*(tic+phase_)/period_);
	p_etat_->put_valphen(y);
}

} /* namespace Domotique */

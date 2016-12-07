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

} /* namespace Domotique */



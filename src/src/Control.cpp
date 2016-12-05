/*
 * Control.cpp
 *
 *  Created on: 14 nov. 2016
 *      Author: Vassili
 */

#include "Control.h"

#include <iostream>

using namespace std;

namespace Domotique {

Control::Control(string nom):
		Processus(nom), p_serveur_(NULL), p_etat_(NULL) {}

Control::~Control() {}

} /* namespace Domotique */

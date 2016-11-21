/*
 * Serveur.cpp
 *
 *  Created on: 14 nov. 2016
 *      Author: jordanmetz
 */

#include "Serveur.h"
#include <string>
namespace Domotique {

Serveur::Serveur(): Processus(), valphen_(0), valctrl_(0), etat_courant_(0) {}

Serveur::~Serveur() {}
void Serveur::run(){}

} /* namespace Domotique */

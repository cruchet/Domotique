/*
 * Control_ON_OFF.cpp
 *
 *  Created on: 5 déc. 2016
 *      Author: jordanmetz
 */

#include "Control_ON_OFF.h"
#include <iostream>

using namespace std;
namespace Domotique {

Control_ON_OFF::Control_ON_OFF(string nom): Control(nom), seuil_min_(0),
		seuil_max_(0), val_min_(0), val_max_(0){
	cout<<"[Control_ON_OFF] Création de "<< nom << endl;
}

Control_ON_OFF::~Control_ON_OFF() {}

void Control_ON_OFF::init(Serveur* p_serveur, Etat* p_etat, double seuil_min,
				double seuil_max, double val_min, double val_max):
p_serveur_(p_serveur), p_etat_(p_etat), seuil_min_(seuil_min), seuil_max_(seuil_max),
val_min_(val_min), val_max_(val_max){
	cout << "[Control_ON_OFF] Initialisation de "<< nom_ << endl;
}

} /* namespace Domotique */

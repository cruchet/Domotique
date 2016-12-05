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

void Control_ON_OFF::run(){
	//Calcul de l'état
	double etat= p_etat_->get_etat();
	double valctrl;
	if(etat>seuil_max_) valctrl=val_min_;
	else if(etat<seuil_min_) valctrl=val_max_;
	else valctrl=etat;
	//Enregistrement de valphen, etat et valctrl dans le serveur
	double valphen= p_etat_->get_phen();
	p_serveur_->save(valphen,etat,valctrl);
}

void Control_ON_OFF::init(Serveur* p_serveur, Etat* p_etat, double seuil_min,
		double seuil_max, double val_min, double val_max)
{
	cout << "[Control_ON_OFF] Initialisation de "<< nom_ << endl;
	p_serveur_=p_serveur;
	p_etat_=p_etat;
	seuil_min_=seuil_min;
	seuil_max_=seuil_max;
	val_min_=val_min;
	val_max_=val_max;
}

} /* namespace Domotique */

/*
 * Control_prop.cpp
 *
 *  Created on: 5 déc. 2016
 *      Author: jordanmetz
 */

#include "Control_prop.h"
#include <iostream>

using namespace std;
namespace Domotique {

Control_prop::Control_prop(string nom): Control(nom), val_cons_(0), gain_(0) {
	cout << "[Control_prop] Création de "<< nom<<endl;

}

Control_prop::~Control_prop() {}
void Control_prop::run(void){
	//Calcul de l'état
	double etat= p_etat_->get_etat();
	double erreur= etat -val_cons_;
	double valctrl = etat - gain_*erreur;
	//Enregistrement de valphen, etat et valctrl dans le serveur
	double valphen= p_etat_->get_phen();
	p_serveur_->save(valphen,etat,valctrl);
	//Donne à etat valctrl
	p_etat_->put_valctrl(valctrl);
}
void Control_prop::init(Serveur* p_serveur, Etat* p_etat, double val_cons, double gain)
{
	cout << "[Control_prop] Initialisation de "<< nom_ << endl;
	p_serveur_=p_serveur;
	p_etat_=p_etat;
	val_cons_=val_cons;
	gain_=gain;
}

} /* namespace Domotique */

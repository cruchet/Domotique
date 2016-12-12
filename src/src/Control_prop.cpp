/*
 * Control_prop.cpp
 *
 *  Created on: 5 déc. 2016
 *      Author: Jordan Metz & Vassili Cruchet
 */

#include "Control_prop.h"
#include <iostream>

using namespace std;
namespace Domotique {

Control_prop::Control_prop(string nom, double val_cons, double gain): Control(nom),
		val_cons_(val_cons), gain_(gain) {
	cout << "[Control_prop]\t\tCréation de "<< nom<<endl;

}

Control_prop::~Control_prop() {}
void Control_prop::run(int tic){
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

} /* namespace Domotique */

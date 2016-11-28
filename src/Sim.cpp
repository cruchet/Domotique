/*
 * Sim.cpp
 *
 *  Created on: 14 nov. 2016
 *      Author: Vassili
 */

#include "../src/Sim.h"
#include <iostream>
#include <vector>
#include <string>

#include "../src/Processus.h"
#include "../src/Serveur.h"
using namespace std;

namespace Domotique {

Sim::Sim(vector< vector<Processus*> > process, int nb_zone, unsigned int max_tic):
		process_(process), nb_zone_(nb_zone), ntic_(max_tic), tic_(0){}

Sim::~Sim() {
	// TODO Auto-generated destructor stub
}

string Sim::run(Serveur* serveur, vector<string> nom_zone) {
	cout << "Lancement de la simulation:" << endl;
	vector<double> param (3);

	for(tic_=0; tic_<=ntic_;tic_++) {
		cout << "t = " << tic_ << ":" << endl;
		// execution des processus:
		for (int zone=0; zone < nb_zone_; zone++)
		{
			for(unsigned int i=0;i<process_.at(zone).size(); i++){
				param = (process_.at(zone).at(i))->run(param);
				if (i==CTRL){
					param=serveur->run(param);
				}
			}
			cout << "Parametres de la zone: " << nom_zone.at(zone) << ":" << endl;
			for(unsigned int i=0; i<param.size(); i++) {

				switch(i) {
				case 0 :
					cout << "\tvalphen: " << param.at(i) << endl; break;
				case 1 :
					cout << "\tvalctrl: " << param.at(i) << endl; break;
				case 2 :
					cout << "\tetat courant: " << param.at(i) << endl; break;
				}
			}
		}
	}
	return serveur->ecriture(nom_zone);
}

} /* namespace Domotique */


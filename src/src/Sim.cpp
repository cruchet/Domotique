/*
 * Sim.cpp
 *
 *  Created on: 14 nov. 2016
 *      Author: Vassili
 */

#include "Sim.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

namespace Domotique {

Sim::Sim(vector< vector<Processus*> > process, int nb_zone, unsigned int max_tic):
		process_(process), nb_zone_(nb_zone), ntic_(max_tic), tic_(0){}

Sim::~Sim() {
	// TODO Auto-generated destructor stub
}

string Sim::run(Serveur* serveur, vector<string> nom_zone) {
	cout << "#Lancement de la simulation:" << endl<<endl;
	vector<vector<double> >param(nb_zone_ , vector<double> (3));
	//param.at(ETAT-COURANT) = etat. get_setting.at(3)

	for(tic_=0; tic_<=ntic_;tic_++) {
		cout << "t = " << tic_ << ":" << endl;
		// execution des processus:
		for (int zone=0; zone < nb_zone_; zone++)
		{
			for(unsigned int i=0;i<process_.at(zone).size(); i++){
				param.at(zone) = (process_.at(zone).at(i))->run(param.at(zone));
				if (i==CTRL){
					param.at(zone)=serveur->run(param.at(zone));
				}
			}
			cout << "\tParametres de la zone: " << nom_zone.at(zone) << ":" << endl;
			for(unsigned int i=0; i<(param.at(zone)).size(); i++) {

				switch(i) {
				case PHEN :
					cout << "\t\tvalphen:\t" << param.at(zone).at(i) << endl; break;
				case CTRL :
					cout << "\t\tvalctrl:\t" << param.at(zone).at(i) << endl; break;
				case ETAT :
					cout << "\t\tetat courant:\t" << param.at(zone).at(i) << endl; break;
				}
			}
		}
	}
	return serveur->ecriture(nom_zone);
}

} /* namespace Domotique */


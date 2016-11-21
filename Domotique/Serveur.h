/*
 * Serveur.h
 *
 *  Created on: 14 nov. 2016
 *      Author: jordanmetz
 */

#ifndef SERVEUR_H_
#define SERVEUR_H_
#include <vector>
#include <string>
#include "Processus.h"

namespace Domotique {
using namespace std;

class Serveur: public Processus {
public:
	Serveur();
	virtual ~Serveur();
	void save_valphen(double valphen){valphen_.push_back(valphen);};
	void save_etat_courant(double etat_courant)
	{etat_courant_.push_back(etat_courant);};

	void save_valctrl(double valctrl){valctrl_.push_back(valctrl);};

	vector<double> get_valphen(){return valphen_;};
	vector<double> get_etat_courant(){return etat_courant_;};
	vector<double> get_valctrl(){return valctrl_;};
	void run();
private:
	vector<double> valphen_;
	vector<double> etat_courant_;
	vector<double> valctrl_;
};

} /* namespace Domotique */

#endif /* SERVEUR_H_ */

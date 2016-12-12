/*
 * Serveur.h
 *
 *  Created on: 14 nov. 2016
 *      Author: jordanmetz
 */

#ifndef SERVEUR_H_
#define SERVEUR_H_

#include "Processus.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

namespace Domotique {
using namespace std;

class Serveur: public Processus {
public:
	Serveur(string nom, string nom_fichier);
	virtual ~Serveur();
	void run(int tic);
	void save(double valphen, double etat, double val_ctrl);

private:
	const string nom_fichier_;
	int tic_;
	string ligne_;
};

} /* namespace Domotique */

#endif /* SERVEUR_H_ */

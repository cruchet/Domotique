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

namespace Domotique {
using namespace std;

class Serveur: public Processus {
public:
	Serveur(string nom, string nom_fichier);
	virtual ~Serveur();
	void run(void);
	void init(vector<double> param);
	void save(double valphen, double etat, double val_ctrl);

private:
	const string nom_fichier_;
	ofstream f_dest_;
	int tic_;

};

} /* namespace Domotique */

#endif /* SERVEUR_H_ */

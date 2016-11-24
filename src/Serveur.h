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

#include "../src/Processus.h"

namespace Domotique {
using namespace std;

class Serveur: public Processus {
public:
	Serveur(string nom, vector<double> setting);
	virtual ~Serveur();
	vector<double> run(vector<double> param);
	string ecriture(void);
private:
	const string nom_fichier_;
	vector< vector <vector <double> > > data_;
	int nb_zone_;
	int zone_courante_;
	unsigned int nb_tic_;
};

} /* namespace Domotique */

#endif /* SERVEUR_H_ */

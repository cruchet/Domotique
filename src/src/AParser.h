/*
 * AParser.h
 *
 *  Created on: 28 nov. 2016
 *      Author: jordanmetz
 */

#ifndef SRC_APARSER_H_
#define SRC_APARSER_H_

#include <string>
#include <vector>
#include <list>
#include <stdio.h>

#include "Control.h"
#include "Etat.h"
#include "Phenomene.h"
#include "Processus.h"
#include "Serveur.h"
#include "Sim.h"
#include "tinyxml.h"
#include "xml_utils.h"


using namespace std;

namespace Domotique {

class AParser {
public:
	AParser(string nom_fichier);
	virtual ~AParser();

	vector<vector<Processus*> > get_paysage() {return paysage_;};
	vector<string> get_nom_zone(){return nom_zone_;};
	void run();
private:
	vector<vector<Processus*> > paysage_;
	vector<string> nom_zone_;
	string nom_fichier_;
};
extern AParser aparser;
}


#endif /* SRC_APARSER_H_ */

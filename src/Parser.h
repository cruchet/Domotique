/*
 * Parser.h
 *
 *  Created on: 28 nov. 2016
 *      Author: vassili
 */

#ifndef PARSER_H_
#define PARSER_H_

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
#include "tinyxml_epfl/tinyxml.h"
#include "tinyxml_epfl/xml_utils.h"


using namespace std;

namespace Domotique {

class Parser {
public:
	Parser(string nom_fichier);
	virtual ~Parser();

	vector<vector<Processus*> > get_paysage() {return paysage_;};
	vector<string> get_nom_zone(){return nom_zone_;};

private:
	TiXmlDocument doc_;
	vector<vector<Processus*> > paysage_;
	vector<string> nom_zone_;


};
}

#endif /* PARSER_H_ */

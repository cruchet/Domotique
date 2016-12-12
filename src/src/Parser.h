/*
 * Parser.h
 *
 *  Created on: 5 déc. 2016
 *      Author: vassili
 */

#ifndef SRC_PARSER_H_
#define SRC_PARSER_H_

#include "Sim.h"

#include <string>

using namespace Domotique;

void lecture_xml(std::string nom_fichier, unsigned int* nb_tic, Sim* simulateur);



#endif /* SRC_PARSER_H_ */

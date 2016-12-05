/*
 * Parser.h
 *
 *  Created on: 5 déc. 2016
 *      Author: vassili
 */

#ifndef SRC_PARSER_H_
#define SRC_PARSER_H_

#include "Serveur.h"
#include "Sim.h"
#include "Processus.h"
#include "Control_ON_OFF.h"
#include "Control_prop.h"
#include "Etat.h"
#include "Phenomene_sinus.h"
#include "Phenomene_pulse.h"
#include "tinyxml_epfl/xml_utils.h"
#include "tinyxml_epfl/tinyxml.h"

#include <vector>
#include <list>
#include <string>
#include <stdio.h>
#include <iostream>

void lecture_xml(string nom_fichier, unsigned int* nb_tic, Sim* simulateur);

#endif /* SRC_PARSER_H_ */

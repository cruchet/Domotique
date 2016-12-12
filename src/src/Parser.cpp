/*
 * Parser.cpp
 *
 *  Created on: 5 déc. 2016
 *      Author: vassili
 */

#include "Parser.h"

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
#include <stdio.h>
#include <iostream>


using namespace Domotique;

void lecture_xml(std::string nom_fichier, unsigned int* nb_tic, Sim* simulateur){
	vector<string> nom_zone;
	vector<double> setting;
	Serveur * serveur = new Serveur("Serveur", "data_serveur.dat");

	//-------------LECTURE DU FICHIER XML ET GESTION ERREUR -------------------
	TiXmlDocument doc_=nom_fichier;
	bool loadOkay = doc_.LoadFile();
	if ( !loadOkay ) {
		printf( "#Ouverture impossible du fichier 'paysage_.xml'. "
				"Error='%s' \n", doc_.ErrorDesc() );
		exit( 1 );
	}
	else {
		printf( "#Ouverture correcte du fichier 'paysage_.xml'.\n\n");
	}

	TiXmlElement* paysage = doc_.FirstChildElement()->FirstChild("paysage")->ToElement();

	//--------------------- EXTRACTION DES TRIPLETS: NIVEAU 1
	for(TiXmlElement* zone = paysage->FirstChild("zone")->ToElement(); zone; zone=zone->NextSiblingElement())
	{ 		//BOUCLE pour extraire l'ensemble des triplets "zone" du paysage

		// Déclaration des pointeurs et valeurs pour init().
		// Seront initialises ensuite.
		Phenomene* phen = NULL;
		Control* ctrl = NULL;
		Etat* etat = NULL;

		if (strcmp(zone->Value(),"zone")==0){
			nom_zone.push_back(zone->Attribute( "nom"));

			// EXTRACTION DU PHENOMENE: NIVEAU 2
			TiXmlElement* phenomene = zone->FirstChild("phenomene")->ToElement () ;
			string nom_phen = phenomene->Attribute( "nom");
			string mode_phen=  phenomene->Attribute( "mode");

			if(strcmp(phenomene->Attribute("mode"),"sinus")==0) {
				TiXmlElement* parametres = phenomene->FirstChild("parametres")->ToElement();

				double offset = 	get_attr_dbl(parametres,"offset", true, 0);
				double ampl = 		get_attr_dbl(parametres,"amplitude", true, 1);
				double sat_max =	get_attr_dbl(parametres,"sat_max", true, 1000);
				double sat_min =	get_attr_dbl(parametres,"sat_min", true, -1000);
				long int phase = 	get_attr_int(parametres,"phase", true, 0);
				long int period = 	get_attr_int(parametres,"period", true, 1);
				phen = new Phenomene_sinus(nom_phen, ampl, period, sat_max, sat_min, offset, phase);
				simulateur->set_process(phen);

			}
			else if(strcmp(phenomene->Attribute("mode"),"pulse")==0) {
				TiXmlElement* parametres = phenomene->FirstChild("parametres")->ToElement();

				double v_low = 		get_attr_dbl(parametres,"val_low", true, 0);
				double v_high = 	get_attr_dbl(parametres,"val_high", true, 1);
				long int t_del =	get_attr_int(parametres,"t_delai", true, 0);
				long int t_rise =	get_attr_int(parametres,"t_rise", true, 0);
				long int pwidth = 	get_attr_int(parametres,"pwidth", true, 1);
				long int t_fall = 	get_attr_int(parametres,"t_fall", true, 0);
				long int period = 	get_attr_int(parametres,"period", true, 1);
				phen = new Phenomene_pulse(nom_phen,v_low,v_high,t_del,t_rise,pwidth,t_fall,period);
				simulateur->set_process(phen);

			}


			// EXTRACTION DU CONTROLE DE LA ZONE: NIVEAU 2
			TiXmlElement* control = zone->FirstChild("control")->ToElement();
			string nom_ctrl = control->Attribute("nom");

			if(strcmp(control->Attribute("mode"),"on_off")==0) {
				TiXmlElement* parametres = control->FirstChild("parametres")->ToElement();
				double seuil_max =	get_attr_dbl(parametres,"seuil_max", true, 1);
				double seuil_min =	get_attr_dbl(parametres,"seuil_min", true, 0);
				double val_max =	get_attr_dbl(parametres,"val_max", true, 1);
				double val_min =	get_attr_dbl(parametres,"val_min", true, 0);
				ctrl = new Control_ON_OFF(nom_ctrl,seuil_min,seuil_max,val_min,val_max);
				simulateur->set_process(ctrl);
			}
			else if(strcmp(control->Attribute("mode"),"proportionnel")==0) {
				TiXmlElement* parametres = control->FirstChild("parametres")->ToElement();
				double set_point =	get_attr_dbl(parametres,"set_point", true, 0);
				double gain =		get_attr_dbl(parametres,"gain", true, 1);
				ctrl = new Control_prop(nom_ctrl,set_point, gain);
				simulateur->set_process(ctrl);
			}

			// EXTRACTION DE l'ETAT DE LA ZONE: NIVEAU 2
			TiXmlElement* state = zone->FirstChild("etat")->ToElement();
			string nom_etat = state->Attribute( "nom");

			double Iphen = 			get_attr_dbl(state,"Iphen", true, 1);
			double Ictrl = 			get_attr_dbl(state,"Ictrl", true, 1);
			double etat_initial = 	get_attr_dbl(state,"etat_initial", true, 0);

			etat = new Etat(nom_etat, Iphen, Ictrl, etat_initial);
			simulateur->set_process(etat);

			//intiations des pointeurs entre processus
			phen->init(etat);
			ctrl->init(serveur, etat);
		}

		else {cout << "Ce n'est pas une zone, il s'agit de la balise : " << zone->Value() << endl;}
		// element autre que zone
	}
	TiXmlElement* simulation = paysage->NextSiblingElement();
	*nb_tic = get_attr_int(simulation,"nb_tic", true, 1);
	simulateur->set_process(serveur);
	cout << "\n#Lecture Correcte du fichier XML" << endl;
}





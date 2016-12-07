/*
 * main.cpp
 *
 *  Created on: 21 nov. 2016
 *      Author: Vassili & Jordan
 */

#include "Sim.h"
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
#include <string>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <stdio.h>
#include <iostream>
#include <ctime>

using namespace Domotique;
void lecture_xml(string nom_fichier, unsigned int* nb_tic, Sim* simulateur);

int main(void) {
	srand(std::time(NULL));
	unsigned int nb_tic = 100;
	string nom_fichier = "paysage.xml";

	//----- Creation du simulateur et lancement de la simulation ------//
	Sim * sim = new Sim(nb_tic);
	lecture_xml(nom_fichier, &nb_tic, sim);

	sim->run();

	return 0;
}
void lecture_xml(string nom_fichier, unsigned int* nb_tic, Sim* simulateur){
	vector<string> nom_zone;
	vector<double> setting;
	Serveur * serveur = new Serveur("Serveur", "data_serveur.dat");

	//-------------LECTURE DU FICHIER XML ET GESTION ERREUR -------------------
	TiXmlDocument doc_=nom_fichier;
	bool loadOkay = doc_.LoadFile();
	if ( !loadOkay ) {
		printf( "#Lecture impossible du fichier 'paysage_.xml'. "
				"Error='%s' \n", doc_.ErrorDesc() );
		exit( 1 );
	}
	else {
		printf( "#Lecture correcte du fichier 'paysage_.xml'.\n\n");
	}

	TiXmlElement* child1 = doc_.FirstChildElement()->FirstChild("paysage")->ToElement();

	//--------------------- EXTRACTION DES TRIPLETS: NIVEAU 1
	for(TiXmlElement* child2 = child1->FirstChild("zone")->ToElement(); child2; child2=child2->NextSiblingElement())
	{ 		//BOUCLE pour extraire l'ensemble des triplets "zone" du paysage

		// Déclaration des pointeurs et valeurs pour init().
		// Seront initialises ensuite.
		Phenomene* phen = NULL;
		Control* ctrl = NULL;
		Etat* etat;

		if (strcmp(child2->Value(),"zone")==0){
			nom_zone.push_back(child2->Attribute( "nom"));

			// EXTRACTION DU PHENOMENE: NIVEAU 2
			TiXmlElement* child3 = child2->FirstChild("phenomene")->ToElement () ;
			string nom_phen = child3->Attribute( "nom");
			string mode_phen=  child3->Attribute( "mode");

			if(strcmp(child3->Attribute("mode"),"sinus")==0) {
				TiXmlElement* child4 = child3->FirstChild("parametres")->ToElement();

				double offset = 	get_attr_dbl(child4,"offset", true, 0);
				double ampl = 		get_attr_dbl(child4,"amplitude", true, 1);
				long int phase = 	get_attr_int(child4,"phase", true, 0);
				long int period = 	get_attr_int(child4,"periode", true, 1);
				phen = new Phenomene_sinus(nom_phen, offset, ampl, phase, period);
				simulateur->set_process(phen);

			}
			else if(strcmp(child3->Attribute("mode"),"pulse")==0) {
				TiXmlElement* child4 = child3->FirstChild("parametres")->ToElement();

				double v_low = 		get_attr_dbl(child4,"val_low", true, 0);
				double v_high = 	get_attr_dbl(child4,"val_high", true, 1);
				long int t_del =	get_attr_int(child4,"t_delai", true, 0);
				long int t_rise =	get_attr_int(child4,"t_rise", true, 0);
				long int pwidth = 	get_attr_int(child4,"pwidth", true, 1);
				long int t_fall = 	get_attr_int(child4,"t_fall", true, 0);
				long int period = 	get_attr_int(child4,"periode", true, 1);
				phen = new Phenomene_pulse(nom_phen,v_low,v_high,t_del,t_rise,pwidth,t_fall,period);
				simulateur->set_process(phen);

			}


			// EXTRACTION DU CONTROLE DE LA ZONE: NIVEAU 2
			TiXmlElement* child5 = child2->FirstChild("control")->ToElement();
			string nom_ctrl = child5->Attribute("nom");


			if(strcmp(child3->Attribute("mode"),"on_off")==0) {
				TiXmlElement* child7 = child5->FirstChild("parametres")->ToElement();

				double seuil_max =	get_attr_dbl(child5,"seuil_max", true, 1);
				double seuil_min =	get_attr_dbl(child5,"seuil_min", true, 0);
				double val_max =	get_attr_dbl(child5,"val_max", true, 1);
				double val_min =	get_attr_dbl(child5,"val_min", true, 0);
				ctrl = new Control_ON_OFF(nom_ctrl,seuil_max,seuil_min,val_max,val_min);
				simulateur->set_process(ctrl);
			}
			else if(strcmp(child3->Attribute("mode"),"proportionnel")==0) {
				TiXmlElement* child7 = child5->FirstChild("parametres")->ToElement();

				double set_point =	get_attr_dbl(child5,"set_point", true, 0);
				double gain =		get_attr_dbl(child5,"seuil_min", true, 1);
				ctrl = new Control_prop(nom_ctrl,set_point, gain);
				simulateur->set_process(ctrl);
			}

			// EXTRACTION DE l'ETAT DE LA ZONE: NIVEAU 2
			TiXmlElement* child6 = child2->FirstChild("etat")->ToElement();
			string nom_etat = child6->Attribute( "nom");

			double Iphen = 			get_attr_dbl(child6,"Iphen", true, 1);
			double Ictrl = 			get_attr_dbl(child6,"Ictrl", true, 1);
			double etat_initial = 	get_attr_dbl(child6,"etat_initial", true, 0);

			etat = new Etat(nom_etat, Iphen, Ictrl, etat_initial);
			simulateur->set_process(etat);

			simulateur->set_process(serveur);

			//intiations des pointeurs entre processus
			phen->init(etat);
			ctrl->init(serveur, etat);
		}

		else {cout << "Ce n'est pas une zone, il s'agit de la balise : " << child2->Value() << endl;}
		// element autre que zone
	}
	TiXmlElement* child1_2 = child1->NextSiblingElement();
	*nb_tic = get_attr_int(child1_2,"nb_tic", true, 1);
}

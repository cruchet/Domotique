/*
 * Parser.cpp
 *
 *  Created on: 5 déc. 2016
 *      Author: vassili
 */

#include "Parser.h"

using namespace Domotique;

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

	// Déclaration des pointeurs pour init.
	// Seront initialises ensuite.
	Phenomene* phen;
	Control* ctrl;
	Etat* etat;

	TiXmlElement* child1 = doc_.FirstChildElement()->FirstChild("paysage")->ToElement();

	//--------------------- EXTRACTION DES TRIPLETS: NIVEAU 1
	for(TiXmlElement* child2 = child1->FirstChild("zone")->ToElement(); child2; child2=child2->NextSiblingElement())
	{ 		//BOUCLE pour extraire l'ensemble des triplets "zone" du paysage

		// Vecteurs pour stocker les parametres et les transmettre a init().
		vector<double> param_dbl(0);
		vector<long int> param_int(0);

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
				phen = new Phenomene_sinus(nom_phen);
				simulateur->set_process(phen);

			}
			else if(strcmp(child3->Attribute("mode"),"pulse")==0) {
				TiXmlElement* child4 = child3->FirstChild("parametres")->ToElement();

				double v_low = 		get_attr_dbl(child4,"val_low", true, 0);
				double v_high = 	get_attr_dbl(child4,"val_high", true, 1);
				long int t_rise =	get_attr_int(child4,"t_rise", true, 0);
				long int pwidth = 	get_attr_int(child4,"pwidth", true, 1);
				long int t_fall = 	get_attr_int(child4,"t_fall", true, 0);
				long int period = 	get_attr_int(child4,"periode", true, 1);
				phen = new Phenomene_pulse(nom_phen);
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
				ctrl = new Control_ON_OFF(nom_ctrl);
				simulateur->set_process(ctrl);
			}
			else if(strcmp(child3->Attribute("mode"),"proportionnel")==0) {
				TiXmlElement* child7 = child5->FirstChild("parametres")->ToElement();

				double set_point =	get_attr_dbl(child5,"set_point", true, 0);
				double gain =		get_attr_dbl(child5,"seuil_min", true, 1);
				ctrl = new Control_prop(nom_ctrl);
				simulateur->set_process(ctrl);
			}

			// EXTRACTION DE l'ETAT DE LA ZONE: NIVEAU 2
			TiXmlElement* child6 = child2->FirstChild("etat")->ToElement();
			string nom_etat = child6->Attribute( "nom");

			double Iphen = 			get_attr_dbl(child6,"Iphen", true, 1);
			double Ictrl = 			get_attr_dbl(child6,"Ictrl", true, 1);
			double etat_initial = 	get_attr_dbl(child6,"etat_initial", true, 0);

			etat = new Etat(nom_etat);
			simulateur->set_process(etat);

			simulateur->set_process(serveur);
		}

		else {cout << "Ce n'est pas une zone, il s'agit de la balise : " << child2->Value() << endl;}
		// element autre que zone
	}
	TiXmlElement* child1_2 = child1->NextSiblingElement();
	*nb_tic = get_attr_int(child1_2,"nb_tic", true, 1);
}




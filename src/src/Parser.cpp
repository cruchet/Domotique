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
	Serveur * serveur = new Serveur("Serveur");

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

		if (strcmp(child2->Value(),"zone")==0){
			nom_zone.push_back(child2->Attribute( "nom"));

			// EXTRACTION DU PHENOMENE: NIVEAU 2
			vector<double> phen_param(0);
			TiXmlElement* child3 = child2->FirstChild("phenomene")->ToElement () ;
			string nom_phen = child3->Attribute( "nom");
			string mode_phen=  child3->Attribute( "mode");

			for(TiXmlElement* param = child3->FirstChild()->ToElement(); param; param=param->NextSiblingElement()) {
				double val;
			//TODO
				phen_param.push_back(val);
			}

			/*if (strcmp(child3->Attribute("mode"),"aleatoire")==0){
				TiXmlElement* child4 = child3->FirstChild("parametres")->ToElement();
				vector<double> phen_param(2);
				phen_param.at(0) = get_attr_dbl(child4,"valmin", true, 1);
				phen_param.at(1) =  get_attr_dbl(child4,"valmax", true, 10);
				Phenomene* phen = new Phenomene(nom_phen);
				simulateur->set_process(phen);
			}*/

			// EXTRACTION DU CONTROLE DE LA ZONE: NIVEAU 2
			TiXmlElement* child5 = child2->FirstChild("control")->ToElement();
			vector<double> param_ctrl(0);
			string nom_ctrl = child5->Attribute( "nom");
			string mode_ctrl=  child5->Attribute( "mode");
			if (strcmp(child5->Attribute("mode"),"saturation")==0){
				TiXmlElement* child7 = child5->FirstChild("parametres")->ToElement();
				param_ctrl.push_back (get_attr_dbl(child7,"valsat", true, 1));
			}
			Control* ctrl = new Control(nom_ctrl);
			simulateur->set_process(ctrl);

			// EXTRACTION DE l'ETAT DE LA ZONE: NIVEAU 2
			TiXmlElement* child6 = child2->FirstChild("etat")->ToElement();
			string nom_etat = child6->Attribute( "nom");
			//TODO: simulateur->set_etat_initial(get_attr_dbl(child6,"etat_initial"));

			vector<double> param_etat(2);

			param_etat.at(0)= get_attr_dbl(child6,"Iphen", true, 1);
			param_etat.at(1)= get_attr_dbl(child6,"Ictrl", true, 1);
			Etat* etat = new Etat(nom_etat);
			simulateur->set_process(etat);

			simulateur->set_process(serveur);
		}

		else {cout << "Ce n'est pas une zone, il s'agit de la balise : " << child2->Value() << endl;}
		// element autre que zone
	}
	TiXmlElement* child1_2 = child1->NextSiblingElement();
	*nb_tic = get_attr_int(child1_2,"nb_tic", true, 1);
}




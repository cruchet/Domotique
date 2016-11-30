/*
 * main.cpp
 *
 *  Created on: 21 nov. 2016
 *      Author: Vassili & Jordan
 */
#include "Serveur.h"
#include "Sim.h"
#include "Processus.h"
#include "Control.h"
#include "Etat.h"
#include "Phenomene.h"
#include "tinyxml_epfl/tinyxml.h"
#include "tinyxml_epfl/xml_utils.h"

#include <vector>
#include <list>
#include <string>
#include <stdio.h>
#include <iostream>
#include <ctime>

using namespace Domotique;

void lecture_xml(string nom_fichier,vector<vector<Processus*> >* paysage,
		vector<string>* nom_zone, vector<double>* etat_initial, unsigned int* nb_tic);

int main(void) {
	srand(std::time(NULL));
	vector<vector<Processus*> > paysage;
	vector<string> nom_zone;
	vector<double> etat_initial;
	unsigned int nb_tic;
	lecture_xml("paysage.xml", &paysage, &nom_zone, &etat_initial, &nb_tic);

	//----- Creation du simulateur et lancement de la simulation ------//
	Sim * sim = new Sim(paysage, paysage.size(), nb_tic);

	vector<double> setting;
	setting.push_back(paysage.size()); //nb_zone
	Serveur * serveur = new Serveur("Serveur", setting);
	string out_file = sim->run(serveur, nom_zone);

	return 0;
}

void lecture_xml(string nom_fichier,vector<vector<Processus*> >* paysage,
		vector<string>* nom_zone, vector<double>* etat_initial, unsigned int* nb_tic){
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
	TiXmlElement* child1 = doc_.FirstChildElement();

	//--------------------- EXTRACTION DES TRIPLETS: NIVEAU 1
	for(TiXmlElement* child2 = child1->FirstChild("zone")->ToElement(); child2; child2=child2->NextSiblingElement())
	{ 		//BOUCLE pour extraire l'ensemble des triplets "zone" du paysage

		if (strcmp(child2->Value(),"zone")==0){
			vector<Processus*> zone(0);
			nom_zone->push_back(child2->Attribute( "nom"));

			// EXTRACTION DU PHENOMENE: NIVEAU 2
			TiXmlElement* child3 = child2->FirstChild("phenomene")->ToElement () ;
			string nom_phen = child3->Attribute( "nom");
			string mode_phen=  child3->Attribute( "mode");
			if (strcmp(child3->Attribute("mode"),"aleatoire")==0){
				TiXmlElement* child4 = child3->FirstChild("parametres")->ToElement();
				vector<double> phen_param(2);
				phen_param.at(0) = get_attr_dbl(child4,"valmin", true, 1);
				phen_param.at(1) =  get_attr_dbl(child4,"valmax", true, 10);
				Phenomene* phen = new Phenomene(nom_phen, mode_phen, phen_param);
				zone.push_back(phen);
			}

			// EXTRACTION DU CONTROLE DE LA ZONE: NIVEAU 2
			TiXmlElement* child5 = child2->FirstChild("control")->ToElement();
			vector<double> param_ctrl(0);
			string nom_ctrl = child5->Attribute( "nom");
			string mode_ctrl=  child5->Attribute( "mode");
			if (strcmp(child5->Attribute("mode"),"saturation")==0){
				TiXmlElement* child7 = child5->FirstChild("parametres")->ToElement();
				param_ctrl.push_back (get_attr_dbl(child7,"valsat", true, 1));
			}
			Control* ctrl = new Control(nom_ctrl, mode_ctrl, param_ctrl);
			zone.push_back(ctrl);

			// EXTRACTION DE l'ETAT DE LA ZONE: NIVEAU 2
			TiXmlElement* child6 = child2->FirstChild("etat")->ToElement();
			string nom_etat = child6->Attribute( "nom");
			vector<double> param_etat(2);
			etat_initial->push_back (get_attr_dbl(child6,"etat_initial"));
			param_etat.at(0)= get_attr_dbl(child6,"Iphen", true, 1);
			param_etat.at(1)= get_attr_dbl(child6,"Ictrl", true, 1);
			Etat* etat = new Etat(nom_etat, param_etat);
			zone.push_back(etat);

			paysage->push_back(zone);

		}
		else {cout << "Ce n'est pas une zone, il s'agit de la balise : " << child2->Value() << endl;}
		// element autre que zone
	}
	TiXmlElement* child1_2 = child1->NextSiblingElement();
	*nb_tic = get_attr_int(child1_2,"nb_tic", true, 1);



}

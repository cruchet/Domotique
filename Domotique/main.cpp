/*
 * main.cpp
 *
 *  Created on: 21 nov. 2016
 *      Author: Vassili & Jordan
 */

#include "Processus.h"
#include "Serveur.h"
#include "Phenomene.h"
#include "Control.h"
#include "Etat.h"
#include "sim.h"
#include "tinyxml_epfl/tinyxml.h"
#include "tinyxml_epfl/xml_utils.h"
#include <vector>
#include <list>
#include <string>
#include <stdio.h>
#include <iostream>

using namespace Domotique;

int main(void) {
/****************** Creation du paysage *********************/

	vector<vector<Processus*> > paysage;
	vector<double> etat_initial;

	//-------------LECTURE DU FICHIER XML ET GESTION ERREUR -------------------
	TiXmlDocument doc( "paysage.xml" );
	bool loadOkay = doc.LoadFile();
	if ( !loadOkay ) {
		printf( "Lecture impossible du fichier 'paysage.xml'. "
				"Error='%s' \n", doc.ErrorDesc() );
		exit( 1 );
	}else{
		printf( "Lecture correcte du fichier 'paysage.xml'.\n");
	}

	TiXmlElement* child1 = doc.FirstChildElement();
	//méthode d'élément permet d'accéder au premier fils de l'arborescence qui est l'élément Paysage

	//--------------------- EXTRACTION DES TRIPLETS: NIVEAU 1
	for(TiXmlElement* child2 = child1->FirstChild("zone")->ToElement(); child2; child2=child2->NextSiblingElement())
	{ 		//BOUCLE pour extraire l'ensemble des triplets "zone" du paysage
			if (strcmp(child2->Value(),"zone")==0){
				vector<Processus*> zone(0);
				string nom_zone =child2->Attribute( "nom");
				int id_zone = get_attr_int(child2,"ID", true, 0);

				// EXTRACTION DU PHENOMENE: NIVEAU 2
				TiXmlElement* child3 = child2->FirstChild("phenomene")->ToElement () ;
				string nom_phen = child3->Attribute( "nom");
				string type_phen=  child3->Attribute( "type");
				if (strcmp(child3->Attribute("type"),"aleatoire")==0){
					TiXmlElement* child4 = child3->FirstChild("parametres")->ToElement();
					vector<double> phen_param(2);
					phen_param.at(0) = get_attr_dbl(child4,"valmin", true, 1);
					phen_param.at(1) =  get_attr_dbl(child4,"valmax", true, 10);
					Phenomene* phen = new Phenomene(nom_phen, type_phen, phen_param);
					zone.push_back(phen);
				}
				/*----------------------POUR RENDU 2:
				// EXTRACTION DES PARAMETRES DU PHENOMENE SELON SON TYPE ---------
				if (strcmp(child3->Attribute("type"),"sinus")==0){ // Détection d'un phénomène sinusoïdal
				TiXmlElement* child4 = child3->FirstChild("parametres")->ToElement();
				// EXTRACTION seule série de paramètre pour le sinu: NIVEAU 4
				cout << "offset phénomène : " << child4->Attribute( "offset") <<endl;
				// EXTRACTION paramètre offset du phenomene:NIVEAU 5
				cout << "amplitude du phénomène : " << child4->Attribute( "ampl") <<endl;
				// EXTRACTION paramètre ampl du phenomene: NIVEAU 5
				cout << "période du phénomène : " << child4->Attribute( "periode") <<endl;
				// EXTRACTION paramètre periode du phenomene: NIVEAU 5
				cout << "étendue maximale du phénomène : " << child4->Attribute( "em") <<endl;
				// EXTRACTION paramètre em du phenomene: NIVEAU 5
				cout << "zéro décalé du phénomène : " << child4->Attribute( "zerodecale") <<endl;
				// EXTRACTION paramètre zerodecale du phenomene: NIVEAU 5
				}
				else if (strcmp(child3->Attribute("type"),"trapeze")==0){ // Détection d'un phénomène trapézoïdal
					for(TiXmlElement * child4 = child3->FirstChild("parametres")->ToElement(); child4; child4=child4->NextSiblingElement())
					{ 	//BOUCLE pour extraire les séries de "parametres" du phenomene.
						//Il y en a plusieurs pour le trapeze: NIVEAU 4
						cout << "tranche du phénomène : " << child4->Attribute( "tranche") <<endl;
						// EXTRACTION paramètre tranche du phenomene: NIVEAU 5
						cout << "début de la tranche en mn : " << child4->Attribute( "debut") <<endl;
						// EXTRACTION paramètre debut du phenomene:NIVEAU 5
						cout << "fin de la tranche en minutes : " << child4->Attribute( "fin") <<endl;
						// EXTRACTION paramètre fin du phenomene: NIVEAU 5
						cout << "pente de la tranche : " << child4->Attribute( "pente") <<endl;
						// EXTRACTION paramètre pente du phenomene:NIVEAU 5
						cout << "offset de la tranche : " << child4->Attribute( "offset") <<endl;
						// EXTRACTION paramètre ooffset du phenomene: NIVEAU 5
					}
				}--------------FIN POUR RENDU 2 ---------------------------*/

				// EXTRACTION DE l'ETAT DE LA ZONE: NIVEAU 2
				TiXmlElement* child5 = child2->FirstChild("etat")->ToElement();
				string nom_etat = child5->Attribute( "nom");
				etat_initial.push_back (get_attr_dbl(child5,"etat_initial"));
				double Iphen = get_attr_dbl(child5,"Iphen", true, 1);
				double Ictrl = get_attr_dbl(child5,"Ictrl", true, 1);

				Etat* etat = new Etat(nom_etat, Iphen, Ictrl);
				zone.push_back(etat);

				// EXTRACTION DU CONTROLE DE LA ZONE: NIVEAU 2
				TiXmlElement* child6 = child2->FirstChild("controle")->ToElement();
				vector<double> param_ctrl(0);
				string nom_ctrl = child6->Attribute( "nom");
				string type=  child6->Attribute( "type");
				if (strcmp(child6->Attribute("type"),"saturation")==0){
					TiXmlElement* child7 = child6->FirstChild("parametres")->ToElement();
					param_ctrl.push_back (get_attr_dbl(child7,"valsat", true, 1));
				}
				Control* ctrl = new Control(nom_ctrl, type, param_ctrl);
				zone.push_back(ctrl);

				paysage.push_back(zone);
			}
			else cout << "Ce n'est pas une zone, il s'agit de la balise : " << child2->Value() << endl;
			// élément autre que zone
}

	return 0;
}

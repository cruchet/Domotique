/*
 * main.cpp
 *
 *  Created on: 21 nov. 2016
 *      Author: Vassili & Jordan
 */

#include <vector>
#include <list>
#include <string>
#include <stdio.h>
#include <iostream>

#include "../src/Control.h"
#include "../src/Etat.h"
#include "../src/Phenomene.h"
#include "../src/Processus.h"
#include "../src/Serveur.h"
#include "../src/Sim.h"
#include "../src/tinyxml_epfl/tinyxml.h"
#include "../src/tinyxml_epfl/xml_utils.h"

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
	//methode d'element permet d'acceder au premier fils de l'arborescence qui est l'element Paysage
	//--------------------- EXTRACTION DES TRIPLETS: NIVEAU 1
	for(TiXmlElement* child2 = child1->FirstChild("zone")->ToElement(); child2; child2=child2->NextSiblingElement())
	{ 		//BOUCLE pour extraire l'ensemble des triplets "zone" du paysage
			if (strcmp(child2->Value(),"zone")==0){
				vector<Processus*> zone(0);
				string nom_zone =child2->Attribute( "nom");
				//int id_zone = get_attr_int(child2,"ID", true, 0);

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
				/*----------------------POUR RENDU 2:
				// EXTRACTION DES PARAMETRES DU PHENOMENE SELON SON TYPE ---------
				if (strcmp(child3->Attribute("type"),"sinus")==0){ // Detection d'un phenomene sinusoidal
				TiXmlElement* child4 = child3->FirstChild("parametres")->ToElement();
				// EXTRACTION seule serie de parametre pour le sinu: NIVEAU 4
				cout << "offset phenomene : " << child4->Attribute( "offset") <<endl;
				// EXTRACTION parametre offset du phenomene:NIVEAU 5
				cout << "amplitude du phenomene : " << child4->Attribute( "ampl") <<endl;
				// EXTRACTION parametre ampl du phenomene: NIVEAU 5
				cout << "periode du phenomene : " << child4->Attribute( "periode") <<endl;
				// EXTRACTION parametre periode du phenomene: NIVEAU 5
				cout << "etendue maximale du phenomene : " << child4->Attribute( "em") <<endl;
				// EXTRACTION parametre em du phenomene: NIVEAU 5
				cout << "zero decale du phenomene : " << child4->Attribute( "zerodecale") <<endl;
				// EXTRACTION parametre zerodecale du phenomene: NIVEAU 5
				}
				else if (strcmp(child3->Attribute("type"),"trapeze")==0){ // Detection d'un phenomene trapezoïdal
					for(TiXmlElement * child4 = child3->FirstChild("parametres")->ToElement(); child4; child4=child4->NextSiblingElement())
					{ 	//BOUCLE pour extraire les series de "parametres" du phenomene.
						//Il y en a plusieurs pour le trapeze: NIVEAU 4
						cout << "tranche du phenomene : " << child4->Attribute( "tranche") <<endl;
						// EXTRACTION parametre tranche du phenomene: NIVEAU 5
						cout << "debut de la tranche en mn : " << child4->Attribute( "debut") <<endl;
						// EXTRACTION parametre debut du phenomene:NIVEAU 5
						cout << "fin de la tranche en minutes : " << child4->Attribute( "fin") <<endl;
						// EXTRACTION parametre fin du phenomene: NIVEAU 5
						cout << "pente de la tranche : " << child4->Attribute( "pente") <<endl;
						// EXTRACTION parametre pente du phenomene:NIVEAU 5
						cout << "offset de la tranche : " << child4->Attribute( "offset") <<endl;
						// EXTRACTION parametre ooffset du phenomene: NIVEAU 5
					}
				}--------------FIN POUR RENDU 2 ---------------------------*/
				// EXTRACTION DE l'ETAT DE LA ZONE: NIVEAU 2
				TiXmlElement* child5 = child2->FirstChild("etat")->ToElement();
				string nom_etat = child5->Attribute( "nom");
				etat_initial.push_back (get_attr_dbl(child5,"etat_initial"));
				vector<double> param_etat(2);
				param_etat.at(0)= get_attr_dbl(child5,"Iphen", true, 1);
				param_etat.at(0)= get_attr_dbl(child5,"Ictrl", true, 1);
				Etat* etat = new Etat(nom_etat, param_etat);
				zone.push_back(etat);
				cout << "11" << endl;
				// EXTRACTION DU CONTROLE DE LA ZONE: NIVEAU 2
				TiXmlElement* child6 = child2->FirstChild("control")->ToElement();
				cout << "12" << endl;
				vector<double> param_ctrl(0);
				string nom_ctrl = child6->Attribute( "nom");
				string mode_ctrl=  child6->Attribute( "mode");
				if (strcmp(child6->Attribute("mode"),"saturation")==0){
					TiXmlElement* child7 = child6->FirstChild("parametres")->ToElement();
					param_ctrl.push_back (get_attr_dbl(child7,"valsat", true, 1));
				}
				Control* ctrl = new Control(nom_ctrl, mode_ctrl, param_ctrl);
				zone.push_back(ctrl);

				paysage.push_back(zone);

			}
			else {cout << "Ce n'est pas une zone, il s'agit de la balise : " << child2->Value() << endl;}
			// element autre que zone
	}
	cout << "YES" << endl;
	return 0;
}

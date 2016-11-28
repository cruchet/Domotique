/*
 * Processus.cpp
 *
 *  Created on: 14 nov. 2016
 *      Author: jordanmetz
 */

#include "../src/Processus.h"

namespace Domotique {
using namespace std;
Processus::Processus(string nom, string type, vector<double> setting):
		nom_(nom), type_(type), setting_(setting) {
	// TODO Auto-generated constructor stub

}

Processus::~Processus() {
	// TODO Auto-generated destructor stub
}

} /* namespace Domotique */

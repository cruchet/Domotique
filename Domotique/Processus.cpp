/*
 * Processus.cpp
 *
 *  Created on: 14 nov. 2016
 *      Author: jordanmetz
 */

#include "Processus.h"

namespace Domotique {
using namespace std;
Processus::Processus(string type): type_(type), valphen_(0),
		refphen_(nullptr), refetat_(nullptr),
		refctrl_(nullptr), refserveur_(nullptr) {
	// TODO Auto-generated constructor stub

}

Processus::~Processus() {
	// TODO Auto-generated destructor stub
}

} /* namespace Domotique */

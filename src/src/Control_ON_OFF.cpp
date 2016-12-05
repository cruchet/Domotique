/*
 * Control_ON_OFF.cpp
 *
 *  Created on: 5 déc. 2016
 *      Author: jordanmetz
 */

#include "Control_ON_OFF.h"

namespace Domotique {

Control_ON_OFF::Control_ON_OFF(string nom): Control(nom), seuil_min_(0),
		seuil_max_(0), val_min_(0), val_max_(0){
	// TODO Auto-generated constructor stub

}

Control_ON_OFF::~Control_ON_OFF() {
	// TODO Auto-generated destructor stub
}

} /* namespace Domotique */

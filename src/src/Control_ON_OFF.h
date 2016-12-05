/*
 * Control_ON_OFF.h
 *
 *  Created on: 5 déc. 2016
 *      Author: jordanmetz
 */

#ifndef SRC_CONTROL_ON_OFF_H_
#define SRC_CONTROL_ON_OFF_H_

#include "Control.h"

namespace Domotique {

class Control_ON_OFF: public Control {
public:
	Control_ON_OFF(string nom);
	virtual ~Control_ON_OFF();
	void run(void);
	void init(Serveur* p_serveur, Etat* p_etat, double seuil_min,
				double seuil_max, double val_min, double val_max);
private:
	double seuil_min_;
	double seuil_max_;
	double val_min_;
	double val_max_;

};

} /* namespace Domotique */

#endif /* SRC_CONTROL_ON_OFF_H_ */

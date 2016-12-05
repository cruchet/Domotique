/*
 * Control_prop.h
 *
 *  Created on: 5 déc. 2016
 *      Author: jordanmetz
 */

#ifndef SRC_CONTROL_PROP_H_
#define SRC_CONTROL_PROP_H_

#include "Control.h"

namespace Domotique {

class Control_prop: public Control {
public:
	Control_prop(string nom);
	virtual ~Control_prop();
	void run(void);
	void init(Serveur* p_serveur, Etat* p_etat, double val_cons, double gain);
private:
	double val_cons_;
	double gain_;
};

} /* namespace Domotique */

#endif /* SRC_CONTROL_PROP_H_ */

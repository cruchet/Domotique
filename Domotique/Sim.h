/*
 *  Sim.h
 *
 *  Created on: 14 nov. 2016
 *      Author: Vassili
 */

#ifndef SIM_H_
#define SIM_H_

namespace Domotique {

class Sim {
public:
	Sim();
	virtual ~Sim();
	void run();

private:
	const int ntic;
	unsigned int tic;

};

} /* namespace Domotique */

#endif /* SIM_H_ */

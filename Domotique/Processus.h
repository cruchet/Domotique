/*
 * Processus.h
 *
 *  Created on: 14 nov. 2016
 *      Author: jordanmetz
 */

#ifndef PROCESSUS_H_
#define PROCESSUS_H_

namespace Domotique {

class Processus {
public:
	Processus();
	virtual ~Processus();
	virtual void run() =0;
private:


};

} /* namespace Domotique */

#endif /* PROCESSUS_H_ */

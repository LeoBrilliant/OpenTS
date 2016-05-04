/*
 * ControlCenter.h
 *
 *  Created on: 2016Äê5ÔÂ4ÈÕ
 *      Author: user
 */

#ifndef UNITTEST_CONTROLCENTERTEST_H_
#define UNITTEST_CONTROLCENTERTEST_H_

#include "../ControlCenter.h"
#include "UTBase.h"


#include <string>

class ControlCenterTest : public UTBase<IntIDType>
{
public:
	ControlCenterTest();
	~ControlCenterTest();
	virtual void TestSuite();

private:
	virtual void ConstructorTest();
};




#endif /* UNITTEST_CONTROLCENTERTEST_H_ */

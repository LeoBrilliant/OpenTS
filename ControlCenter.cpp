/*
 * ControlCenter.cpp
 *
 *  Created on: 2016Äê5ÔÂ4ÈÕ
 *      Author: user
 */


#include "ControlCenter.h"

ControlCenter::ControlCenter() : Infra(NULL)
{
}

ControlCenter::~ControlCenter() {
}

void ControlCenter::CommandLoop() {

	string command;
	Infrastructure * ip;
	Instruction * inst;
	while(true)
	{
		cin >> command;
		if(command.length() == Constants::ZERO)
			continue;

		//switch(command)
		{
		//case "INIT":
			if(command.compare("INIT") == 0) {
				ip = new Infrastructure();
				ip->InitializeInfrastructureAction();
				this->RegisterInfrastructure(ip);
				//break;
			}
		//case "INSERTINSTRUCTION":
			else if(command.compare("INSERTINSTRUCTION") == 0) {
			inst = new Order();
			ip->AcceptInstruction(*inst);
			//break;
			}
			else
				break;
		//default:
			//break;
		}
	}
}

VoidType ControlCenter::RegisterInfrastructure(Infrastructure* ip) {
	this->Infra = ip;

}

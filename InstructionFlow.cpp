/*
 * InstructionFlow.cpp
 *
 *  Created on: 2016Äê4ÔÂ27ÈÕ
 *      Author: user
 */

#include "InstructionFlow.h"
#include "DBAccess.h"
#include "MySQLDB.h"

InstructionFlow::InstructionFlow() :
	InstructionHandlers(NULL),
	BusinessHandler(DefaultHandler),
	NotifyClient(DefaultHandler),
	ResponseToClient(DefaultHandler)
{
}

InstructionFlow::~InstructionFlow() {
}

ReturnType InstructionFlow::InsertInstruction(Instruction& inst) {
	instFlow.Push(inst);
	this->SetInsertTime(inst);
	return Constants::SUCCESS;
}

inline VoidType InstructionFlow::SetInsertTime(Instruction& inst) {
	inst.SetInsertTime();
}

inline ReturnType InstructionFlow::ValidateInstruction(Instruction& inst) {
	return Constants::SUCCESS;
}

inline VoidType InstructionFlow::SetConfirmedTime(Instruction& inst) {
	inst.SetConfirmedTime();
}

ReturnType InstructionFlow::InsertInstructionHandlers(Map<StringType, OrderBook *> * handler)
{
//	pair<StringType, OrderBook> p = make_pair(instrument, handler);
//	this->InstructionHandlers.Insert(p);
	this->InstructionHandlers = handler;
	return Constants::SUCCESS;
}

ReturnType InstructionFlow::InsertAction(Instruction &inst)
{
	this->InsertInstruction(inst);

	this->DispatchInstruction(inst);
	return Constants::SUCCESS;
}
ReturnType InstructionFlow::DispatchInstruction(Instruction &inst)
{
	ReturnType ret = Constants::FAILURE;
	Order * op = NULL;
	OrderBook * obp = NULL;
	switch(inst.GetInstType())
	{
	case InstructionType::LIMITPRICEORDER:

	case InstructionType::CANCEL:

	case InstructionType::MARKETPRICEORDER:
		op = (Order *)(&inst);
		{
		MYSQL * conn_ptr = NULL;
				conn_ptr = NULL;
				conn_ptr = InitializeMySQLClient(conn_ptr);
				//assert(conn_ptr != NULL);
				conn_ptr = ConnectMySQLServer(conn_ptr);
				//assert(conn_ptr != NULL);

				if (!mysql_set_character_set(conn_ptr, "utf8"))
				{
				    printf("New client character set: %s\n",
				           mysql_character_set_name(conn_ptr));
				}

				//Order * op = GenOrder();

				char * sql_insert = GetInsertOrderSQL(op);
				op->SetVolumeLeft(op->GetVolumeLeft() + 10);
				char * sql_update = GetUpdateOrderSQL(op);
				//ProgramMessage::Debug(sql_insert);
				//ProgramMessage::Debug(sql_update);
				if(mysql_query(conn_ptr, sql_insert))
				{
					fprintf(stderr, "call mysql_query failed...%d: %s", errno, mysql_error(conn_ptr));
				}

				mysql_close(conn_ptr);

				//delete op;
				delete sql_insert;
				delete sql_update;
		}
		obp = (*(this->InstructionHandlers))[op->GetInstrumentID()];
		ret = obp->OrderAction(op);

		break;
	default:
		break;
	}
	return ret;
}

/*
 * ProgramMessage.cpp
 *
 *  Created on: 2016Äê4ÔÂ22ÈÕ
 *      Author: user
 */

#include "ProgramMessage.h"

ProgramMessage::MessageLevel ProgramMessage::LogLevel = MessageLevel::INFO;

ProgramMessage::ProgramMessage() {
}

void ProgramMessage::Info(const string& s) {
}

void ProgramMessage::Warn(const string& s) {
}

void ProgramMessage::Error(const string& s) {
}

void ProgramMessage::Fatal(const string& s) {
}

void ProgramMessage::SetMessageLevel(MessageLevel & level) {
	LogLevel = level;
}

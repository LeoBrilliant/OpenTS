/*
 * ProgramMessage.h
 *
 *  Created on: 2016Äê4ÔÂ22ÈÕ
 *      Author: user
 */

#ifndef PROGRAMMESSAGE_H_
#define PROGRAMMESSAGE_H_

#include <iostream>

using namespace std;

class ProgramMessage
{
	typedef enum {
		INFO,
		DEBUG,
		WARN,
		ERROR,
		FATAL
	} MessageLevel;
private:
	static MessageLevel LogLevel;
	ProgramMessage();

public:
	static void Info(const string &s);
	template<typename T=string>
	static void Debug(const T &s);
	static void Warn(const string &s);
	static void Error(const string &s);
	static void Fatal(const string &s);

	template<typename T=string>
	static inline void Print(const T & s);
	template<typename T=string>
	static inline void PrintLine(const T &s);
	static inline void EndOfLine();

	//static Method
	static void SetMessageLevel(MessageLevel & level);
};

//there is no data type named ProgramMessage::Debug
//typedef ProgramMessage::Debug Debug;

template<typename T>
void ProgramMessage::Debug(const T& s) {
	PrintLine(s);
}

template<typename T>
inline void ProgramMessage::Print(const T & s) {
	cout << s;
}

template<typename T>
inline void ProgramMessage::PrintLine(const T & s) {
	cout << s;
	EndOfLine();
}

inline void ProgramMessage::EndOfLine() {
	cout << endl;
}

#endif /* PROGRAMMESSAGE_H_ */

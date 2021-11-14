/*
 * logger.cpp
 *
 *  Created on: 02-Oct-2021
 *      Author: Varun
 */

#include "logger.h"

bool Logger::shouldPrintMessage(int timestamp, string message) {
	map<string,int>::iterator mp_itr;

	mp_itr = mp.find(message);
	if(mp_itr == mp.end()) {
		mp.insert({message,timestamp+10});	// next timestamp stored
		return true;
	} else {
		if(timestamp < mp_itr->second) {
			return false;
		} else {
			mp[message] = timestamp+10;
			return true;
		}
	}
}



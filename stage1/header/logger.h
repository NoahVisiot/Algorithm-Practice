/*
 * logger.h
 *
 *  Created on: 02-Oct-2021
 *      Author: Varun
 */

#ifndef LOGGER_H_
#define LOGGER_H_

#include <string>
#include <map>

using namespace std;

class Logger {
private:map<string,int> mp;
public:
    Logger() {

    }
    bool shouldPrintMessage(int , string );
};



#endif /* LOGGER_H_ */

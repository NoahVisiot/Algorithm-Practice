/*
 * search.cpp
 *
 *  Created on: 18-Feb-2021
 *      Author: varchoud
 */

#include "common.h"
#include "search.h"

int ArrayReader::get(int index)
{
	if(index>10000)
		return 2147483647;
	return array[index];
}

int Solution::search(ArrayReader& reader, int target) {
	int index=0;
	while(true) {
		if(reader.get(index) == target)
			return index;
		else if(reader.get(index) == 2147483647)
			return -1;
		index++;
	}
}

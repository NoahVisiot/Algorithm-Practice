/*
 * search.h
 *
 *  Created on: 18-Feb-2021
 *      Author: varchoud
 */

#ifndef SEARCH_H_
#define SEARCH_H_

class ArrayReader {
	  int array[10000];
 public:
    int get(int index);
    ArrayReader(void) {
    	for(int i=0;i<10000;i++)
    		array[i]=i;
    }
 };

class Solution :public ArrayReader {
public:
    int search(ArrayReader& reader, int target);
};

#endif /* SEARCH_H_ */

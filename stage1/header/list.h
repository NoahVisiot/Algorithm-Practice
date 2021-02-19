/*
 * list.h
 *
 *  Created on: Feb 13, 2021
 *      Author: varun
 */

#ifndef HEADER_LIST_H_
#define HEADER_LIST_H_

#include "common.h"

class singlyList {
private:
	int data;
	singlyList *next;
public:
	void setData(int val);
	void printNode(void);
	singlyList* getNext(void); // return the next node.
	void setNext(singlyList *nxt);
	singlyList(void) {
		data =0;
		next=NULL;
	}
};

class singlyListOps:public singlyList {

};

void printReverseList(singlyList *obj);
singlyList *createList(int arr[],int N);

#endif /* HEADER_LIST_H_ */

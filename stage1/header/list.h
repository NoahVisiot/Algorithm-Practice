/*
 * list.h
 *
 *  Created on: Feb 13, 2021
 *      Author: varun
 */

#ifndef HEADER_LIST_H_
#define HEADER_LIST_H_

#include "common.h"

class listNode {
private:
	int data;
	listNode *next;
public:
	void printList();
	listNode* getNext(void); // return the next node.
	Status_t createList(int arr[],int n,listNode *h);
};

class listOps {
public:
	void deleteNode();
	void addNode();
	void printListInReverse(listNode* h);
};

#endif /* HEADER_LIST_H_ */

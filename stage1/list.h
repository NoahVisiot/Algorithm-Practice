/*
 * list.h
 *
 *  Created on: Feb 13, 2021
 *      Author: varun
 */

#ifndef LIST_H_
#define LIST_H_

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

#endif /* LIST_H_ */

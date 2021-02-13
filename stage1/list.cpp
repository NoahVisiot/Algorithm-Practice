/*
 * list.cpp
 *
 *  Created on: Feb 13, 2021
 *      Author: varun
 */

#include <iostream>

#include "common.h"
#include "list.h"

using namespace std;

Status_t listNode::createList(int arr[],int n,listNode *h)
{
	Status_t status = STATUS_SUCCESS;

	if(h) {
		/* 1. We're creating fist node */
		if(!h->getNext()) {
			data = arr[0];
		} else {
			/* 2. We're creating intermediate node*/
		}
	} else
		status = STATUS_NULL_PTR;

	return status;
}

listNode* listNode::getNext(void)
{
	if(next)
		return next->next;
	return NULL;
}

void listNode::printList()
{
	cout << "%d" <<data;
}

void listOps::printListInReverse(listNode* head) {
    if(head == NULL)
        return;

    printListInReverse(head->getNext());
    head->printList();
}

void listOps::deleteNode()
{

}

void listOps::addNode()
{

}


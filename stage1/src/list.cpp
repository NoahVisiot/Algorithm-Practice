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

singlyList* singlyList::getNext(void)
{
	return next;
}

void singlyList::setNext(singlyList *next)
{
	this->next = next;
}

void singlyList::printNode(void)
{
	cout<<data;
}

void singlyList::setData(int data)
{
	this->data = data;
}

void printReverseList(singlyList *obj)
{
	if(obj) {
		if(obj->getNext())
			printReverseList(obj->getNext());
		obj->printNode();
	}
}

singlyList* createList(int arr[],int N)
{
	singlyList *h=NULL;
	singlyList *n=NULL;
	singlyList *t=NULL;

	if(N > 0) {
		for(int i=0;i<N;i++) {
			if(!h) {
				h = new singlyList;
				h->setData(arr[i]);
				n = h;
			} else {
				t = new singlyList;
				t->setData(arr[i]);
				n->setNext(t);
				n = t;
			}
		}
	}

	return h;
}

/*
 * list.h
 *
 *  Created on: 08-Oct-2021
 *      Author: Varun
 */

#ifndef LIST_H_
#define LIST_H_

#include <iostream>
#include <vector>

using namespace std;

class ImmutableListNode {
private:
	int val;
	ImmutableListNode *next;
public:
	ImmutableListNode() {val=0;next=NULL;}
	ImmutableListNode(int val) {this->val = val; next=NULL;}
	void printValue(ImmutableListNode *node) {cout << node->val << endl;}
	ImmutableListNode* getNext(ImmutableListNode *node) { return node?node->next:NULL;}
	ImmutableListNode *createList(vector<int> &a);
	void printListIter(ImmutableListNode *);
	void printListRec(ImmutableListNode *);
	ImmutableListNode* createXorList(vector<int> &arr);
};


#endif /* LIST_H_ */

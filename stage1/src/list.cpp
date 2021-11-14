/*
 * list.cpp
 *
 *  Created on: 08-Oct-2021
 *      Author: Varun
 */

#include "list.h"

void ImmutableListNode::printListRec(ImmutableListNode *node) {
	if(!node)
		return;

	printListRec(node->getNext(node));
	node->printValue(node);
}

ImmutableListNode* ImmutableListNode::createList(vector<int> &arr) {
	ImmutableListNode *root=NULL,*temp=NULL;
	bool flag=false;

	for(auto &a:arr) {
		if(!flag) {
			root=new ImmutableListNode(a);
			temp = root;
			flag = true;
		} else {
			temp->next = new ImmutableListNode(a);
			temp = temp->next;
		}
	}

	return root;
}

ImmutableListNode* Xor(ImmutableListNode* a, ImmutableListNode* b) {
	return reinterpret_cast<ImmutableListNode*>(
			reinterpret_cast<uintptr_t>(a)
			^reinterpret_cast<uintptr_t>(b)
			);
}

ImmutableListNode* ImmutableListNode::createXorList(vector<int> &arr) {
	ImmutableListNode *root=NULL,*curr=NULL;
	bool flag=false;
	ImmutableListNode *next=NULL,*tail=NULL;

	for(auto &a:arr) {
		if(!flag) {
			root=new ImmutableListNode(a);
			curr = root;
			flag = true;
		} else {
			next = new ImmutableListNode(a);
			curr->next = Xor(tail,next);
			tail = curr;
			curr = next;
			next = next->next;
			curr->next = Xor(tail,next);
		}
	}

	return root;
}

void ImmutableListNode::printListIter(ImmutableListNode *root) {
	ImmutableListNode *tail=NULL,*next=NULL;
	ImmutableListNode *curr=NULL;

	if(!root)
		return;

	curr=root;
	do {
		next = Xor(tail,curr->next);
		tail = curr;
		curr = next;
	}while(next);

	curr=tail;
	tail=NULL;
	do {
		printValue(curr);
		next = Xor(tail,curr->next);
		tail = curr;
		curr = next;
	}while(next!=NULL);
}


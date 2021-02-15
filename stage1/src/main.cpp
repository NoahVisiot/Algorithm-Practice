/*
 * main.cpp
 *
 *  Created on: Feb 13, 2021
 *      Author: varun
 */

#include <iostream>

#include "common.h"
#include "list.h"

using namespace std;

int main() {
	Status_t status = STATUS_SUCCESS;
	listNode lNode;
	int arr[] = {1,2,3,4};

	status = lNode.createList(arr,sizeof(arr)/sizeof(arr[0]),&lNode);
	if(STATUS_SUCCESS == status) {
		cout<<"List created\n";
	} else {
		cout<<"Error creating list\n";
	}

	return 0;
}




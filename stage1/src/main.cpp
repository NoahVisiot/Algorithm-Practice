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
	singlyList *h=NULL;
	int arr[] = {1,2,3,4};

	h = createList(arr,sizeof(arr)/sizeof(arr[0]));
	if(h) {
		cout<<"list created\n";
		printReverseList(h);
	}

	return 0;
}




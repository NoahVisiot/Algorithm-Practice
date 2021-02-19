/*
 * main.cpp
 *
 *  Created on: Feb 13, 2021
 *      Author: varun
 */

#include <iostream>

#include "common.h"
#include "list.h"
#include "search.h"

using namespace std;

int main() {
/*	singlyList *h=NULL;
	int arr[] = {1,2,3,4};

	h = createList(arr,sizeof(arr)/sizeof(arr[0]));
	if(h) {
		cout<<"list created\n";
		printReverseList(h);
	} */

	ArrayReader r;
	Solution s;
	cout<<s.search(r, 9999);

	return 0;
}




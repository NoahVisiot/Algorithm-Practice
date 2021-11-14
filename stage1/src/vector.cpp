/*
 * array.cpp
 *
 *  Created on: 03-Oct-2021
 *      Author: Varun
 */

#include "vector.h"

int Vector::subtractProductAndSum(int n) {
	int p=1,s=0;
	vector<int> a;

	while(n>0) {
		a.push_back(n%10);
		n = n/10;
	}

	for(int i=0;i<a.size();i++) {
		p*=a[i];
		s+=a[i];
	}

	return p-s;
}

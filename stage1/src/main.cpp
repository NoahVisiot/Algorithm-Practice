//============================================================================
// Name        : main.cpp
// Author      : Varun
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "solution.h"
#include "logger.h"
#include "binarytree.h"
#include "vector.h"
#include "list.h"

using namespace std;

int main() {
	Solution obj;
	//binaryTree obj;
	//vector<TreeNode*> v;
	vector<int> nums = {1,2,1,3,2,5};
	vector<int> v;

	v = obj.singleNumber(nums);
	//cout<<"size :"<<obj.singleNumber(n)<<endl;

	return 0;
}




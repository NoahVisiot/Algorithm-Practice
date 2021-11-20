/*
 * dynamicProg.cpp
 *
 *  Created on: 19-Nov-2021
 *      Author: Varun
 */

#include "dynamicProg.h"

static int maxx(vector<int> &nums){
	int max=-1;

	for(auto n:nums) {
		if(n>max)
			max=n;
	}

	return max;
}

static int Grid(int r, int c,vector<vector<int>> &v) {
	if(r==0 || c==0)	return 0;
	if(r==1 && c==1)	return 1;
	if(v[r][c])	return v[r][c]?v[r][c]:v[c][r];

	v[r][c] = Grid(r-1,c,v) + Grid(r,c-1,v);
	return v[r][c];
}

unsigned int grid(int r, int c) {
	vector<vector<int>> v(r+1,vector<int> (c+1,0));

	return Grid(r,c,v);
}

static bool CanSum(int targetSum, vector<int> &nums, vector<bool> &m) {
	if(m[targetSum]==false)	return m[targetSum];
	if(targetSum==0) return true;
	if(targetSum<0)	return false;

	for(auto n:nums) {
		int r = targetSum-n;
		if(CanSum(r,nums,m)==true)
			return true;
	}
	m[targetSum] = false;
	return false;
}

bool canSum(int targetSum, vector<int> &nums) {
	vector<bool> m(maxx(nums)+1,true);

	return CanSum(targetSum,nums,m);
}

static vector<int> HowSum(int targetSum, vector<int> &nums, vector<bool> &m) {
	if(m[targetSum]==false)	return m[targetSum];
	if(targetSum==0) return true;
	if(targetSum<0)	return false;

	for(auto n:nums) {
		int r = targetSum-n;
		if(CanSum(r,nums,m)==true)
			return {targetSum,n};
	}
	m[targetSum] = false;
	return false;
}

vector<int> howSum(vector<int> &nums,int targetSum) {
	vector<bool> m(maxx(nums)+1,true);
	vector<int> r;

	r=HowSum(targetSum,nums,m);

	return r;
}

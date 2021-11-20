/*
 * dynamicProg.h
 *
 *  Created on: 19-Nov-2021
 *      Author: Varun
 */

#ifndef HEADER_DYNAMICPROG_H_
#define HEADER_DYNAMICPROG_H_

#include <vector.h>

unsigned int grid(int r, int c);
bool canSum(int targetSum, vector<int> &);
vector<int> howSum(vector<int> &nums,int targetSum);


#endif /* HEADER_DYNAMICPROG_H_ */

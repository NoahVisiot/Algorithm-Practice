/*
 * solution.h
 *
 *  Created on: 02-Oct-2021
 *      Author: Varun
 */

#ifndef SOLUTION_H_
#define SOLUTION_H_

#include <string>
#include <map>
#include <set>
#include <vector>
#include <deque>
#include <array>
#include <iterator>
#include<stack>

using namespace std;

class Solution {
private:map<int,string> mymp;   // key, url
    	string baseKey;
public:
    Solution(){baseKey="10000";}
    int numJewelsInStonesMap(string, string);
    int numJewelsInStonesSet(string, string);
    string removeVowels(string);
    string defangIPaddr(string);
    vector<int> anagramMappings(vector<int>&, vector<int>&);
    int calculateTime(string, string);
    int uniqueMorseRepresentations(vector<string>& );
    vector<bool> kidsWithCandies(vector<int>&, int) ;
    int hammingDistance(int, int);
    vector<int> smallerNumbersThanCurrent(vector<int>&) ;
    int numIdenticalPairs(vector<int>&);
    vector<int> selfDividingNumbers(int , int );
    int islandPerimeter(vector<vector<int>>&);
    vector<string> subdomainVisits(vector<string>&);
    vector<string> findWords(vector<string>&);
    string decode(string);
    string encode(string);
    vector<int> singleNumber(vector<int>& nums);
};


#endif /* SOLUTION_H_ */

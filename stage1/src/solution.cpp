/*
 * solution.cpp
 *
 *  Created on: 02-Oct-2021
 *      Author: Varun
 */
#include "solution.h"

vector<int> Solution::singleNumber(vector<int>& nums) {
	vector<int> v;
	map<int,int> mp;

	for(int i=0;i<nums.size();i++) {
		if(mp.find(nums[i])==mp.end())
			mp.insert({nums[i],1});
		else {
			mp[nums[i]] = 2;
		}
	}

	for(auto itr=mp.begin();itr!=mp.end();itr++) {
		if(itr->second==1)
			v.push_back(itr->first);
	}

	return v;
}

int Solution::calculateTime(string keyboard, string word) {
	int t=0;
	int temp = 0;
	int lastIdx=0;

	for(char &ch:word) {
		temp = keyboard.find(ch);
		t += abs(lastIdx-temp);
		lastIdx = temp;
	}

	return t;
}

int Solution::numJewelsInStonesMap(string jewels, string stones) {
	int count=0;
	map<char,int> mp;
	map<char,int>::iterator mp_itr;

	for(auto it=jewels.begin();it!=jewels.end();it++)
		mp.insert({*it,1});

	for(auto it=stones.begin(); it!=stones.end(); it++) {
		mp_itr = mp.find(*it);
		if(mp_itr != mp.end())
			count++;
	}

	return count;
}

int Solution::numJewelsInStonesSet(string jewels, string stones) {
	int count=0;
	set<char> st;

	for(auto it=jewels.begin();it!=jewels.end();it++)
		st.insert(*it);

	for(auto it=stones.begin(); it!=stones.end(); it++) {
		if(st.find(*it) != st.end())
			count++;
	}

	return count;
}

string Solution::removeVowels(string s) {
	set<char> st = {'a','e','i','o','u'};
	string str;

	for(char &ch:s){
		if(st.find(ch) == st.end()) {
			str.push_back(ch);
		}
	}

	return str;
}

string Solution::defangIPaddr(string address) {
	string str;

	for(auto it=address.begin();it!=address.end();it++){
		if(*it == '.') {
			str.append("[.]");
		} else {
			str.push_back(*it);
		}
	}

	return str;
}

vector<int> Solution::anagramMappings(vector<int>& nums1, vector<int>& nums2) {
	map<int,int> mp;
	vector<int> v;

	for(auto i=0; i<nums2.size();i++){
		mp.insert({nums2[i],i});
	}

	for(auto itr=nums1.begin();itr!=nums1.end();itr++){
		v.push_back(mp.find(*itr)->second);
	}

	return v;
}

int Solution::uniqueMorseRepresentations(vector<string>& words) {
	vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....",
			"..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...",
			"-","..-","...-",".--","-..-","-.--","--.."};
	set<string> s;

	for(string &it:words) {
		// get the transformation
		string trans;
		for(char &ch:it) {
			trans.append(morse[ch - 'a']);
		}
		// insert transformation in set
		s.insert(trans);
	}

	return s.size();
}

vector<bool> Solution::kidsWithCandies(vector<int>& candies, int extraCandies) {
	vector<bool> result;
	int max=0;

	for(auto i:candies) {
		if(i>max)
			max=i;
	}

	for(auto itr=candies.begin();itr!=candies.end();itr++) {
		if(*itr + extraCandies >= max)
			result.push_back(true);
		else
			result.push_back(false);
	}

	return result;
}

int Solution::hammingDistance(int x, int y) {
	int hd=0;
	int r=0;
	int count=0;

	r = x^y;
	while(count<8) {
		if(r & (1<<count))
			hd++;
		count++;
	}

	return hd;
}

/*vector<int> Solution::smallerNumbersThanCurrent(vector<int>& nums) {
    vector<int> vs;
    int max=-1;

    // get maxval
    for(auto &i:nums)
        if(i>max)
            max=i;

    array<int,max> arr;
    arr.fill(-1);
    for(int i=0;i<nums.size();i++) {
    	arr[nums[i]] = 1;
    }

    for(i=0;i<arr.size();i++)
    	if(arr[i])
    		push_back()
}*/

int Solution::numIdenticalPairs(vector<int>& nums) {
	int pairs=0;
	multimap<int,int> mmp;
	set<int> s;							// {1,2,3}
	int selection=0;

	for(int i=0;i<nums.size();i++){
		mmp.insert({nums[i], i});			//  {1,2,3,1,1,3};
		s.insert(nums[i]);
	}

	for(auto i=s.begin();i!=s.end();i++){
		selection = mmp.count(*i);
		if(selection>=2)
			pairs += (selection*(selection-1))/2;
	}

	return pairs;
}

vector<int> Solution::selfDividingNumbers(int left, int right) {
	stack<int> st;
	vector<int> v;
	int num=0, r=0, flag=0;
	int n = left;

	while(n<=right) {
		num = n;
		while(num) {
			r = num%10;
			num = num/10;
			if(r)
				st.push(r);
			else
				break;
		}
		if(!r) {
			n++;
			while(!st.empty())
				st.pop();
			continue;
		}
		while(!st.empty()) {		// Returns true if the stack is empty.
			if(n%(st.top()) != 0) {
				flag = 1;
				break;
			} else {
				st.pop();
			}
		}
		if(!flag) {
			v.push_back(n);
		} else
			flag=0;
		while(!st.empty())
			st.pop();
		n++;
	}

	return v;
}

void updateGrid(vector<vector<int>>& g,int i,int j) {
	if(i==0 && j==0) {
		// do nothing
	} else if(i==0 && j) {
		if(g[i][j-1]) {
			g[i][j] -= 1;
			g[i][j-1] -= 1;
		}
	} else if(i && j==0) {
		if(g[i-1][j]) {
			g[i][j] -= 1;
			g[i-1][j] -= 1;
		}
	} else {
		if(g[i-1][j]) {
			g[i][j] -= 1;
			g[i-1][j] -= 1;
		}
		if(g[i][j-1]) {
			g[i][j] -= 1;
			g[i][j-1] -= 1;
		}
	}
}

int Solution::islandPerimeter(vector<vector<int>>& grid) {
	int p=0;
	for(int i=0;i<grid.size();i++) {
		for(int j=0;j<grid[i].size();j++) {
			if(grid[i][j]) {
				grid[i][j] = 4;
				updateGrid(grid,i,j);
			}
		}
	}
	for(int i=0;i<grid.size();i++)
		for(int j=0;j<grid[i].size();j++)
			p += grid[i][j];

	return p;
}

#include <iostream>
vector<string> Solution::subdomainVisits(vector<string>& cpdomains) {
	vector<string> str;
	map<string,int> mp;

	for(int i=0;i<cpdomains.size();i++) {
		string &s = cpdomains[i];

		int idx = s.find_first_of(' ');
		string count = s.substr(0,idx);
		int c=stoi(count);								// count obtained

		string site = s.substr(idx+1,s.size());			// google.mail.com

		while(1) {
			if(mp.find(site)!=mp.end()) {
				mp[site] += c ;
			}
			else {
				mp[site] = c;
			}

			idx = site.find('.');
			if(idx != site.npos) {
				site = site.substr(idx+1,site.size());	// mail.com
			} else
				break;
		}
	}
	for(auto itr=mp.begin();itr!=mp.end();itr++)
		str.push_back(to_string(itr->second) + " " + itr->first);

	return str;
}

vector<string> Solution::findWords(vector<string>& words) {
    vector<string> v;
    vector<string> kb = {
        "qwertyuiop",
        "asdfghjkl",
        "zxcvbnm"
    };

    for(int i=0;i<words.size();i++) {
        string s = words[i];
        bool flag = false;

        for(int j=0;j<kb.size();j++) {
        	string k = kb[j];
            for(auto &ch:s) {
                if(k.find(ch)!=string::npos || k.find(ch+32)!=string::npos) {

                } else {
                    flag=true;
                    break;
                }
            }
            if(!flag) {
                v.push_back(words[i]);
            } else {
                flag = false;
            }
        }
    }

    return v;
}

// Encodes a URL to a shortened URL.
string Solution::encode(string longUrl) {
    string s = "http://tinyurl.com/";
    int key = stoi(baseKey);

    mymp.insert({key,longUrl});
    s.append(to_string(key));

    key++;
    baseKey = to_string(key);

    return s;
}

// Decodes a shortened URL to its original URL.
string Solution::decode(string shortUrl) {
    int idx = shortUrl.find_last_of('/');
    string substr = shortUrl.substr(idx+1,shortUrl.size()-1);

    return mymp[stoi(substr)];
}

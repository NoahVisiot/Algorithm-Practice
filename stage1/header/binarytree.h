/*
 * binarytree.h
 *
 *  Created on: 02-Oct-2021
 *      Author: Varun
 */

#ifndef BINARYTREE_H_
#define BINARYTREE_H_

#include <vector>
#include <stack>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}
    Node(int _val) {
        val = _val;
    }
    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class binaryTree {
private: vector<int> v;
public:
    int maxDepth(TreeNode*);
    TreeNode* mergeTrees(TreeNode*, TreeNode*);
    vector<int> preorder(Node*);
    vector<int> postorder(Node*);
    TreeNode* sortedArrayToBST(vector<int>&);
    void printLvlOrder(TreeNode* );
    TreeNode* bstFromPreorder(vector<int>&);
    vector<TreeNode*> allPossibleFBT(int);
};

#endif /* BINARYTREE_H_ */

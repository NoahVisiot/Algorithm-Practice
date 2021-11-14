/*
 * binarytree.cpp
 *
 *  Created on: 02-Oct-2021
 *      Author: Varun
 */

#include "binarytree.h"
#include <iostream>
#include <queue>

TreeNode* getTreeNode(void)
{
	TreeNode* node;
	node = new TreeNode;
	return node;
}

static int treeMaxDepth(TreeNode* root,int depth)
{
	int dl=0,dr=0;;

	if(!root)
		return depth;

	dl = treeMaxDepth(root->left,depth+1);
	dr = treeMaxDepth(root->right,depth+1);

	return dl>dr?dl:dr;
}

int binaryTree::maxDepth(TreeNode* root)
{
	return treeMaxDepth(root,0);
}

TreeNode* binaryTree::mergeTrees(TreeNode* root1, TreeNode* root2) {
	TreeNode* node;
	if(!root1 && !root2)
		return NULL;

	node = getTreeNode();
	if(root1 && root2) {
		node->val = root1->val + root2->val;
		node->left = mergeTrees(root1->left,root2->left);
		node->right = mergeTrees(root1->right,root2->right);
	} else if(root1 && !root2) {
		node->val = root1->val;
		node->left = mergeTrees(root1->left,root2);
		node->right = mergeTrees(root1->right,root2);
	} else {
		node->val = root2->val;
		node->left = mergeTrees(root1,root2->left);
		node->right = mergeTrees(root1,root2->right);
	}

	return node;
}

static void preorderTraversal(Node* root,vector<int> &v) {
	if(!root)
		return;

	v.push_back(root->val);
	for(auto itr=root->children.begin();itr!=root->children.end();itr++)
		preorderTraversal(*itr,v);
}

vector<int> binaryTree::preorder(Node* root) {
	vector<int> v;

	if(root)
		preorderTraversal(root,v);

	return v;
}

vector<int> binaryTree::postorder(Node* root) {
	if(root) {
		for(auto itr=root->children.begin();itr!=root->children.end();itr++)
			preorderTraversal(*itr,v);
		v.push_back(root->val);
	}
	return v;
}

void binaryTree::printLvlOrder(TreeNode* root) {
	if(!root)
		return;

	queue<TreeNode*> q;
	q.push(root);
	while(!q.empty()) {
		TreeNode *t = q.front();
		q.pop();
		cout << t->val << " ";
		if(t->left)
			q.push(t->left);
		if(t->right)
			q.push(t->right);
	}
}

static TreeNode* insertInorder(vector<int>& nums,int l,int h) {
	if(l>h) {
		return NULL;
	}
	int mid=(l+h)/2;

	TreeNode *node = new TreeNode(nums[mid]);
	node->left = insertInorder(nums,l,mid-1);
	node->right = insertInorder(nums,mid+1,h);

	return node;
}

TreeNode* binaryTree::sortedArrayToBST(vector<int>& nums) {
	if(nums.size()==0)
		return NULL;

	TreeNode* root = insertInorder(nums,0,nums.size()-1);
	printLvlOrder(root);
	return root;
}

TreeNode* binaryTree::bstFromPreorder(vector<int>& preorder) {
    if(preorder.size()==0)
        return NULL;

    stack<TreeNode*> st;
    int i=0;
    TreeNode *root = new TreeNode(preorder[i++]);
    TreeNode *temp = root;
    while(i < preorder.size()) {
        if(temp->val > preorder[i]) {
            temp->left = new TreeNode(preorder[i++]);
            st.push(temp);
            temp = temp->left;
        } else {
            if(st.empty() || (st.top()->val > preorder[i])) {
                temp->right = new TreeNode(preorder[i++]);
                temp = temp->right;
            } else {
                temp = st.top();
                st.pop();
            }
        }
    }

    return root;
}

static TreeNode *cloneTree(TreeNode *root) {
    if(!root)
        return NULL;

    TreeNode *node = new TreeNode(root->val);
    node->left = cloneTree(root->left);
    node->right = cloneTree(root->right);

    return node;
}

static void FBT(vector<TreeNode*> &v, int max,int &num,TreeNode *r,TreeNode *t) {
    if(max==num) {
        v.push_back(cloneTree(r));
        return;
    }
    t->left = new TreeNode;
    t->right = new TreeNode;
    num+=2;

    FBT(v,max,num,r,t->left);
    if(num<max)
        FBT(v,max,num,r,t->right);
    if(num==max) {
        delete t->left;
        delete t->right;
        num-=2;
    }
}

vector<TreeNode*> binaryTree::allPossibleFBT(int n) {
    vector<TreeNode*> v;
    if(n==0)
        return v;
    if(n==1) {
        v.push_back(new TreeNode);
        return v;
    }

    TreeNode *r = new TreeNode;
    int num=1;
    FBT(v,n,num,r,r);
    return v;
}

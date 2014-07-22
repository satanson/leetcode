#include<cppstdlib.hpp>
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {		
    }
	void insert(TreeNode *branch,int val,list<TreeNode*>& path){
		list<TreeNode*> path;
		if(val<branch.val){
			path.push_back(branch);
			if (branch->left)insert(branch->left,val,path);
			else{
				branch->left=new TreeNode(val);
				path.push_back(branch->left);
			}
		}else (branch.val<val){
			path.push_back(branch);
			if (branch->right)insert(branch->right,val,path);
			else{
				branch->right=new TreeNode(val);
				path.push_back(branch->right);
			}
		}else{
		}
	}
    bool isBalanced(TreeNode *root) {
		list<int> depths;
		int height;
		if(root)
			return postOrder(root,height);
		else 
			return true;
    }
	bool postOrder(TreeNode *branch,int& height){
		if (!branch->left && !branch->right ) {
			height=1;
			return true;
		}
		int lheight,rheight;

		if (branch->left){
			if(!postOrder(branch->left,lheight))return false;
		}else 
			lheight=0;

		if (branch->right){
			if(!postOrder(branch->right,rheight))return false;
		}else 
			rheight=0;
		height=std::max(lheight,rheight)+1;
		return abs(rheight-lheight)<=1;
	}
	void adjust(TreeNode *branch){
		if branc
	}
};

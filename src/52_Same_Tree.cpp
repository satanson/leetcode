#include<cppstdlib.hpp>
#include<tree_serialize.hpp>
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode*p,TreeNode*q) {
		return treeEq(p,q);
    }
	bool treeEq(TreeNode *branch1,TreeNode *branch2){
		if (!branch1 && !branch2)return true;
		if (branch1 && branch2 && branch1->val==branch2->val){
			return treeEq(branch1->left,branch2->left) && treeEq(branch1->right,branch2->right);
		}else{
			return false;
		}
	}
};
int main(){
	Solution so;
	string line;
	while(getline(cin,line)){
		TreeNode *root=string2tree(line);
		cout<<boolalpha<<so.isSameTree(root->left,root->right)<<endl;
	}
}

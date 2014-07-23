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
    bool isSymmetric(TreeNode *root) {
		if(!root)return true;
		return treeMirrorEq(root->left,root->right);
    }
	bool treeMirrorEq(TreeNode *branch1,TreeNode *branch2){
		if (!branch1 && !branch2)return true;
		if (branch1 && branch2 && branch1->val==branch2->val){
			return treeMirrorEq(branch1->left,branch2->right) && treeMirrorEq(branch1->right,branch2->left);
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
		cout<<boolalpha<<so.isSymmetric(root)<<endl;
	}
}

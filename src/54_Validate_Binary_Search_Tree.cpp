#include<cppstdlib.hpp>
#include<tree_serialize.hpp>

class Solution{
public:
	bool isValidBST(TreeNode *root){
		if (!root)return true;
		TreeNode* prev=NULL;
		return inorder(root,prev);

	}
	bool inorder(TreeNode *branch,TreeNode*& prev){
		if (!branch->left && !branch->right){
			if (prev && prev->val >=branch->val)return false;	
			else {prev=branch;return true;}
		}
		if (branch->left){
			if (!inorder(branch->left,prev) || prev && prev->val>=branch->val)return false;
			else prev=branch;
		}
		prev=branch;
		if (branch->right){
			if (!inorder(branch->right,prev))return false;
		}
		return true;
	}
};
int main(){
	Solution so;
	string line;
	while(getline(cin,line)){
		TreeNode *root=string2tree(line);
		cout<<boolalpha<<so.isValidBST(root)<<endl;
	}
}

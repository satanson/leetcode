#include<tree_serialize.hpp>
#include<list_serialize.hpp>
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
    vector<int> inorderTraversal(TreeNode *root) {
		vector<int> vals;
		if (!root) return vals;
		vector<TreeNode*> stk;
		bool flip=true;
		stk.push_back(root);
		while(!stk.empty()){
			if (flip){
				TreeNode *branch=stk.back();
				if (branch->left)stk.push_back(branch->left);
				else flip=!flip;
			}else{
				TreeNode *branch=stk.back();
				stk.pop_back();
				vals.push_back(branch->val);
				if (branch->right){
					stk.push_back(branch->right);
					flip=!flip;
				}
			}
		}
		return vals;
    }
};

int main(){
	Solution so;
	string line;
	while(getline(cin,line)){
		cout<<vector2string<int>(so.inorderTraversal(string2tree(line)))<<endl;
	}
}

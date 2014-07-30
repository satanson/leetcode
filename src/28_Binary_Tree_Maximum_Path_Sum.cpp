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
    int maxPathSum(TreeNode *root) {
		if (!root)return 0;

		int max_sum=0,left_max=0,right_max=0,left_max_path=0,right_max_path=0;
		if (root->left) left_max=MaxPath(root->left,left_max_path);
		if (root->right) right_max=MaxPath(root->right,right_max_path);
		
		max_sum=root->val;
		max_sum+=(left_max_path>right_max_path)?left_max_path:right_max_path;
		if (right_max<max_sum &&right_max<max_sum)return max_sum;
		else if (right_max<left_max)return left_max;
		else return right_max;

    }
	int MaxPath(TreeNode *branch,int& max_sum){
		if (!branch->left && !branch->right){ 
			max_sum=branch->val;
			return max_sum;
		}
		int left_max=0,right_max=0,left_max_path=0,right_max_path=0;
		if (branch->left) left_max=MaxPath(branch->left,left_max_path);
		if (branch->right) right_max=MaxPath(branch->right,right_max_path);
		
		max_sum=branch->val;
		max_sum+=(left_max_path>right_max_path)?left_max_path:right_max_path;
		if (right_max<max_sum &&right_max<max_sum)return max_sum;
		else if (right_max<left_max)return left_max;
		else return right_max;
	}
};

int main(){
	Solution so;
	string line;
	while(getline(cin,line)){
		cout<<so.maxPathSum(string2tree(line))<<endl;
	}

}

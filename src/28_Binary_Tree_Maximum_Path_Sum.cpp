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
		int sum1,sum2;
		sum1=maxPath(root,sum2);
		return sum1<sum2?sum2:sum1;
    }
	int maxPath(TreeNode *branch,int& max_sum){
		if (!branch->left && !branch->right){ 
			max_sum=branch->val;
			return max_sum;
		}
		int left_max=0,right_max=0,left_max_path=0,right_max_path=0;
		if (branch->left) left_max=maxPath(branch->left,left_max_path);
		if (branch->right) right_max=maxPath(branch->right,right_max_path);
		
		max_sum=branch->val;
		max_sum+=(left_max_path>right_max_path)?left_max_path:right_max_path;
		
		int sum=branch->val;
		sum+=left_max_path>0?left_max_path:0;
		sum+=right_max_path>0?right_max_path:0;

		if (right_max<sum &&right_max<sum)return sum;
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

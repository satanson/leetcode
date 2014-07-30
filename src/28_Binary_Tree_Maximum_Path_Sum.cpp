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
	int maxPath(TreeNode *branch,int& sum){
		if (!branch->left && !branch->right){ 
			sum=branch->val;
			return sum;
		}
		int a[2]={~0};
		int b[2]={~0};

		if (branch->left) a[0]=maxPath(branch->left,b[0]);
		if (branch->right) a[1]=maxPath(branch->right,b[1]);
		
		int bb=*std::max_element(b,b+2);
		if (bb<0)sum=branch->val;
		else sum=branch->val+bb;

		int aa=0;
		if (branch->val>0){
			aa=branch->val;
			if (b[0]>0)aa+=b[0];
			if (b[1]>0)aa+=b[1];
		}else{
			aa=bb;
		}
		int a_max=*std::max_element(a,a+2);
		if (a_max>aa)return a_max;
		else return aa;
	}
};

int main(){
	Solution so;
	string line;
	while(getline(cin,line)){
		cout<<so.maxPathSum(string2tree(line))<<endl;
	}

}

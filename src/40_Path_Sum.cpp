#include<cppstdlib.hpp>
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
		vector<vector<int>> paths;
		list<int> path;
		if(root)preOrder(root,0,sum,path,paths);
		return paths.size()>0;
    }
	void preOrder(TreeNode *branch,int sum,int targetSum,list<int>& path, vector<vector<int>>& paths){
		sum+=branch->val;
		
		path.push_back(branch->val);
		
		if (!branch->left && !branch->right && targetSum==sum) {
			paths.push_back(vector<int>());
			vector<int> p(path.begin(),path.end());
			std::swap(paths.back(),p);
		}
		if (branch->left)preOrder(branch->left,sum,targetSum,path,paths);
		if (branch->right)preOrder(branch->right,sum,targetSum,path,paths);

		path.pop_back();
	}
};

int main(){

	Solution so;
	{
		TreeNode n1(5);
		TreeNode n2(4);
		TreeNode n3(8);
		n1.left=&n2;
		n1.right=&n3;
		
		TreeNode n4(11);
		n2.left=&n4;

		TreeNode n5(13);
		TreeNode n6(4);
		n3.left=&n5;
		n3.right=&n6;

		TreeNode n7(7);
		TreeNode n8(2);
		TreeNode n9(5);
		TreeNode n10(1);
		n4.left=&n7;
		n4.right=&n8;
		n6.left=&n9;
		n6.right=&n10;
		cout<<boolalpha<<so.hasPathSum(&n1,22)<<endl;
	}
}

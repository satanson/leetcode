#include<cppstdlib.hpp>
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
    int minDepth(TreeNode *root) {
		list<int> depths;
		if(root)preOrder(root,0,depths);
		return std::min_element(depths.begin(),depths.end());
    }
	void preOrder(TreeNode *branch,int depth,list<int>& depths){

		depth++;
		if (!branch->left && !branch->right ) {
			depths.push_back(depth);
		}
		if (branch->left)preOrder(branch->left,depth,depths);
		if (branch->right)preOrder(branch->right,depth,depths);
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
		cout<<so.minDepth(&n1)<<endl;
	}
}

#include<cppstdlib.hpp>
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
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

		if (branch->left)postOrder(branch->left,lheight);
		else lheight=0;
		if (branch->right)postOrder(branch->right,rheight);
		else rheight=0;
		height=std::max(lheight,rheight)+1;
		return abs(rheight-lheight)<=1;
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
		cout<<boolalpha<<so.isBalanced(&n1)<<endl;
	}
	{
		TreeNode n1(1);
		TreeNode n2(2);
		TreeNode n3(3);
		TreeNode n4(4);
		n1.left=&n2;
		n1.right=&n3;
		n3.left=&n4;
		cout<<boolalpha<<so.isBalanced(&n1)<<endl;
	}
}

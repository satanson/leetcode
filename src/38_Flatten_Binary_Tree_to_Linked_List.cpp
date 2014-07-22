#include<cppstdlib.hpp>
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
class Solution {
public:
    void flatten(TreeNode *root) {
		if (root)postOrder(root);
        
    }
	TreeNode* postOrder(TreeNode* branch){
		TreeNode* left_branch_tail=NULL;
		TreeNode* right_branch_tail=NULL;
		if (branch->right)right_branch_tail=postOrder(branch->right);
		if (branch->left)left_branch_tail=postOrder(branch->left);
		if (branch->right && branch->right){
			left_branch_tail->right=branch->right;
			branch->right=branch->left;
			return right_branch_tail;
		}else if (branch->left && !branch->right){
			branch->right=branch->left;
			return left_branch_tail;
		}else if (!branch->left && branch->right){
			return right_branch_tail;
		}else {
			return branch;
		}	
	}
};

int main(){
	TreeNode n1(1);
	TreeNode n2(2);
	TreeNode n3(3);
	TreeNode n4(4);
	TreeNode n5(5);
	TreeNode n6(6);
	n1.left=&n2;
	n2.left=&n3;
	n2.right=&n4;
	n1.right=&n5;
	n5.right=&n6;
	Solution so;
	so.flatten(&n1);
	for (TreeNode *p=&n1;p!=NULL;p=p->right){
		cout<<p->val<<" ";
	}
	cout<<endl;
}

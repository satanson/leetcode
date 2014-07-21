#include<cppstdlib.hpp>
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
	public:
		typedef list<int> LIST;
		int sumNumbers(TreeNode *root) {
			if (root==NULL)return 0;
	
			int n=0;
			LIST nums;
			preorder(root,n,nums);
			int sum=0;
			while(!nums.empty()){
				sum+=nums.front();
				nums.pop_front();
			}
			return sum;
		}
		void preorder(TreeNode *root,int n,LIST& nums){
			n*=10;
			n+=root->val;
			if (!root->left && !root->right)nums.push_back(n);
			if (root->left)preorder(root->left,n,nums);
			if (root->right)preorder(root->right,n,nums);
		}
};

int main(){
	Solution s;
	shared_ptr<TreeNode> n1(new TreeNode(1));
	shared_ptr<TreeNode> n2(new TreeNode(2));
	shared_ptr<TreeNode> n3(new TreeNode(3));
	n1->left=n2.get();
	n2->left=n3.get();
	cout<<s.sumNumbers(n1.get())<<endl;
	shared_ptr<TreeNode> n4(new TreeNode(4));
	shared_ptr<TreeNode> n5(new TreeNode(5));
	shared_ptr<TreeNode> n6(new TreeNode(6));
	n1->right=n4.get();
	n4->right=n5.get();
	n2->right=n6.get();
	cout<<s.sumNumbers(n1.get())<<endl;

	shared_ptr<TreeNode> n7(new TreeNode(7));
	n4->left=n7.get();
	cout<<s.sumNumbers(n1.get())<<endl;
}

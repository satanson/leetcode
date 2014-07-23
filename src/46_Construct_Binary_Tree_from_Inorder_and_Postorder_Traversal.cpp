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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {	
		if(inorder.size()==0)return NULL;
		int root_val=postorder.back();
		TreeNode *root=new TreeNode(root_val);
		int i=0;
		while(inorder[i]!=root_val)i++;
		vector<int> right_inorder(&inorder[i+1],&*inorder.end());
		vector<int> right_postorder(&postorder[i],&postorder.back());
		inorder.resize(i);
		postorder.resize(i);
		root->left=buildTree(inorder,postorder);
		root->right=buildTree(right_inorder,right_postorder);
		return root;
    }
};

int main(){
	string line;
	Solution so;
	while(getline(cin,line)){
		int n;
		vector<int> inorder,postorder;
		stringstream ss(line);
		while(ss>>n)inorder.push_back(n);
		getline(cin,line);
		ss.str(line);
		ss.seekg(0);
		ss.clear();
		while(ss>>n)postorder.push_back(n);
		cout<<tree2string(so.buildTree(inorder,postorder))<<endl;
	}
}

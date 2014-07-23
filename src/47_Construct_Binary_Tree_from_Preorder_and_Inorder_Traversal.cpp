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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {	
		return build(preorder,inorder,0,preorder.size(),0,inorder.size());
    }
	TreeNode *build(vector<int>& preorder,vector<int>& inorder,int preL,int preH,int inL,int inH){
		if (preL==preH)return NULL;
		int root_val=preorder[preL];
		TreeNode *root=new TreeNode(root_val);
		int i=0;
		while(inorder[i]!=root_val)i++;
		root->left=build(preorder,inorder,1+preL,1+preL+i-inL,inL,i);
		root->right=build(preorder,inorder,1+preL+i-inL,preH,1+i,inH);
		return root;
	}
};

int main(){
	string line;
	Solution so;
	while(getline(cin,line)){
		int n;
		vector<int> preorder,inorder;
		stringstream ss(line);
		while(ss>>n)preorder.push_back(n);
		getline(cin,line);
		ss.str(line);
		ss.seekg(0);
		ss.clear();
		while(ss>>n)inorder.push_back(n);
		cout<<tree2string(so.buildTree(preorder,inorder))<<endl;
	}
}

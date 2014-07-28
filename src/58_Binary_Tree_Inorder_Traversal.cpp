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
     vector<int> inorderTraversal(TreeNode *root){
                if(!root)return vector<int>();
                vector<int> path;
                inorder(root,path);
                return path;

        }
        void inorder(TreeNode *root,vector<int>& path){
                if(root->left)inorder(root->left,path);
                path.push_back(root->val);
                if(root->right)inorder(root->right,path);
        }

};
int main(){
	string line;
	Solution so;
	while(getline(cin,line)){
		vector<int> v=so.inorderTraversal(string2tree(line));
		for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
		cout<<endl<<string(10,'#')<<endl;
	}
}

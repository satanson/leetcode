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
    vector<vector<int> > levelOrder(TreeNode *root) {
		if (!root)return vector<vector<int>>();
		list<TreeNode*> q1,q2;
		vector<vector<int>> v;
		vector<int> a;
		q1.push_back(root);
		while(!q1.empty()){
			while(!q1.empty()){
				TreeNode *branch=q1.front();q1.pop_front();
				a.push_back(branch->val);
				if(branch->left)q2.push_back(branch->left);
				if(branch->right)q2.push_back(branch->right);
			}
			v.push_back(vector<int>());
			std::swap(v.back(),a);
			std::swap(q1,q2);
		}
		return v;
    }
};
int main(){
	Solution so;
	string line;
	while(getline(cin,line)){
		TreeNode *root=string2tree(line);
		vector<vector<int>> v=so.levelOrder(root);
		for (int i=0;i<v.size();i++){
			for (int j=0;j<v[i].size();j++){
				cout<<v[i][j]<<" ";
			}
			cout<<endl;
		}
	}
}

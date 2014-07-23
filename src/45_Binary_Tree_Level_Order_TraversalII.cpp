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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
		list<TreeNode*> q;
		if (!root) return vector<vector<int>>();
		q.push_back(root);
		q.push_back(NULL);
		for(list<TreeNode*>::iterator it=q.begin();it!=q.end();it++){
			TreeNode *branch=*it;
			if(!branch){
				if(std::next(it,1)!=q.end())q.push_back(NULL);
			}else{
				if(branch->right)q.push_back(branch->right);
				if(branch->left)q.push_back(branch->left);
			}
		}
		vector<vector<int>> v;
		while(!q.empty()){
			TreeNode *branch=q.back();q.pop_back();
			if (!branch)v.push_back(vector<int>());
			else v.back().push_back(branch->val);
		}
		return v;
    }
};
int main(){
	Solution so;
	string line;
	while(getline(cin,line)){
		TreeNode *root=string2tree(line);
		vector<vector<int>> v=so.levelOrderBottom(root);
		for (int i=0;i<v.size();i++){
			for (int j=0;j<v[i].size();j++){
				cout<<v[i][j]<<" ";
			}
			cout<<endl;
		}
	}
}

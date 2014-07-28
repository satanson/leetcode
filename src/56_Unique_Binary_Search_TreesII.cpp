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
    vector<TreeNode*> generateTrees(int n){
                vector<vector<vector<TreeNode*>>> d(n+2,vector<vector<TreeNode*>>(n+2));
                for (auto i=0;i<=n;i++){
                        d[i+1][i].push_back(NULL);
                        d[i][i].push_back(new TreeNode(i));
                }
                for (auto L=1;L<n;L++){
                        for (auto i=1;i+L<=n;i++){
                                int j=i+L;
                                for (auto k=i;k<=j;k++){
                                        vector<TreeNode*>& lbranchs=d[i][k-1];
                                        for (auto n=0;n<lbranchs.size();n++){
                                                vector<TreeNode*>& rbranchs=d[k+1][j];
                                                for (auto m=0;m<rbranchs.size();m++){
                                                        d[i][j].push_back(new TreeNode(k));
                                                        d[i][j].back()->left=lbranchs[n];
                                                        d[i][j].back()->right=rbranchs[m];
                                                }
                                        }
                                }
                        }
                }
                return d[1][n];
        }

};

int main(){
	Solution so;
	int n;
	while(cin>>n){
		vector<TreeNode*> roots=so.generateTrees(n);
		for (int i=0;i<roots.size();i++)cout<<tree2string(roots[i])<<endl;
		cout<<string(10,'#')<<endl;
	}
}

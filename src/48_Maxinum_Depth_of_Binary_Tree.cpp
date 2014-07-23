#include<cppstdlib.hpp>
#include<tree_serialize.hpp>
class Solution {
public:
    int maxDepth(TreeNode *root) {
		list<int> depths;
		if(root){
			preOrder(root,0,depths);
			return *std::max_element(depths.begin(),depths.end());
		}else return 0;
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
	string line;
	while(getline(cin,line)){
		TreeNode *root=string2tree(line);
		cout<<so.maxDepth(root)<<endl;
	}
}

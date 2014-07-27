#include<cppstdlib.hpp>
#include<tree_serialize.hpp>

class Solution{
public:
	void recoverTree(TreeNode *root){
		if(!root)return;
		list<list<TreeNode*>> nodes;
		inorder(root,NULL,nodes);
		if(nodes.size()==1){
			std::swap(nodes.back().front()->val,nodes.back().back()->val);
		}else{
			std::swap(nodes.front().front()->val,nodes.back().back()->val);
		}
	}
	TreeNode* inorder(TreeNode *branch,TreeNode* prev,list<list<TreeNode*>>& nodes){
		//null node
		if (!branch) return prev;

		//leaf node
		if (!branch->left && !branch->right){
			//prev exists and ge branch
			if(prev && prev->val>branch->val){
				nodes.push_back(list<TreeNode*>());
				nodes.back().push_back(prev);
				nodes.back().push_back(branch);
			}
			return branch;
		}

		TreeNode *lprev=NULL,*rprev=NULL;
		if (branch->left){
			lprev=inorder(branch->left,prev,nodes);
			if (lprev && lprev->val>branch->val){
				nodes.push_back(list<TreeNode*>());
				nodes.back().push_back(lprev);
				nodes.back().push_back(branch);
			}
		}else{
			if (prev && prev->val>branch->val){
				nodes.push_back(list<TreeNode*>());
				nodes.back().push_back(prev);
				nodes.back().push_back(branch);
			}
		}
		if (branch->right){
			rprev=inorder(branch->right,branch,nodes);
			return rprev;
		}else{
			return branch;
		}
	}
};
int main(){
	Solution so;
	string line;
	while(getline(cin,line)){
		TreeNode *root=string2tree(line);
		so.recoverTree(root);
		cout<<tree2string(root)<<endl;
	}
}

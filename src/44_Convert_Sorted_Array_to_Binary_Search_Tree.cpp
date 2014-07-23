#include<cppstdlib.hpp>
#include<tree_serialize.hpp>
class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
		if(num.size()==0)return NULL;
		int low=0,high=num.size(),mid=(low+high)/2;
		TreeNode *root=new TreeNode(num[mid]);
		insert(root,num,low,high);
		return root;
    }
	void insert(TreeNode *branch,vector<int> &num,int low,int high){
		int mid=(low+high)/2;
		if (low!=mid){
			branch->left=new TreeNode(num[(low+mid)/2]);
			insert(branch->left,num,low,mid);
		}

		if (mid+1!=high){
			branch->right=new TreeNode(num[(mid+1+high)/2]);
			insert(branch->right,num,mid+1,high);
		}
	}
};

int main(){
	string line;
	Solution so;
	while(getline(cin,line)){
		stringstream ss(line);
		vector<int> num;
		int n;
		while(ss>>n)num.push_back(n);
		TreeNode* root=so.sortedArrayToBST(num);
		cout<<tree2string(root)<<endl;
	}
}

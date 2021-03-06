#include<cppstdlib.hpp>
#include<tree_serialize.hpp>
#include<list_serialize.hpp>
class Solution {
	public:
		TreeNode *sortedListToBST(ListNode *head) {	
			vector<int> num;
			while(head){num.push_back(head->val);head=head->next;}
			return sortedArrayToBST(num);
		}
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
	Solution so;
}

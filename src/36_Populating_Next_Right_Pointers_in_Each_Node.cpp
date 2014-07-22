#include<cppstdlib.hpp>
struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
class Solution {
public:
    void connect(TreeLinkNode *root) {
		if (!root)return;
		root->next=NULL;
		TreeLinkNode *eldest,*sibling;
		eldest=root;
		while(eldest->left){
			sibling=eldest;
			while(sibling){
				sibling->left->next=sibling->right;
				if (sibling->next)sibling->right->next=sibling->next->left;
				else sibling->right->next=NULL;
				sibling=sibling->next;
			}
			eldest=eldest->left;
		}
    }
};
int main(){

}

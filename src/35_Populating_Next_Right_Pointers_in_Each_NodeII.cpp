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
			TreeLinkNode *father;
			father=root;

			while(father){
				TreeLinkNode *p=father;
				while(p && !p->left && !p->right)p=p->next;
				if (!p)break;

				father=p;
				TreeLinkNode *eldest_son;
				if (father->left)eldest_son=father->left;
				else eldest_son=father->right;

			    TreeLinkNode *elder=father;
				while(elder){

					//elder has two childs
					TreeLinkNode *child;
					if (elder->left){
						if (!elder->right){
							child=elder->left;
						}else{
							elder->left->next=elder->right;
							child=elder->right;
						}
					}else{
						child=elder->right;
					}

					TreeLinkNode *uncle=elder->next;
					while(uncle && !uncle->left && !uncle->right)uncle=uncle->next;

					if (!uncle)child->next=NULL;
					else {
						TreeLinkNode* cousin;
						if(uncle->left)cousin=uncle->left;
						else cousin=uncle->right; 
						child->next=cousin;
					}

					elder=uncle;
				}
				father=eldest_son;
			}
		}
};
int main(){

	TreeLinkNode node1(1);
	TreeLinkNode node2(2);
	TreeLinkNode node3(3);
	TreeLinkNode node4(4);
	TreeLinkNode node5(5);
	node1.left=&node2;
	node1.left->left=&node4;
	node1.right=&node3;
	node1.right->right=&node5;
	Solution so;
	so.connect(&node1);
}

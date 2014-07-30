#include<list_serialize.hpp>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
       if(!head)return NULL; 
	   ListNode *p=head,*q=NULL,*r=NULL,*pp=NULL;
	   while(p){
		   if (!p->next || p->next->val!=p->val){
			   pp=p;
			   p=p->next;
		   }else{
			   q=p->next;
			   while(q && q->val==p->val)q=q->next;
			   if (head==p)head=q;
			   if (pp)pp->next=q;
			   while(p!=q){
				   r=p;
				   p=p->next;
				   delete r;
			   }
		   }
	   }
	   return head;
    }
};

int main(){
	Solution so;
	string line;
	while(getline(cin,line)){
		cout<<list2string(so.deleteDuplicates(string2list(line)))<<endl;
	}
}

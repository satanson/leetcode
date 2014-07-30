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
	   ListNode *p=head,*q;
	   while(p){
		   if(p->next && p->val==p->next->val){
			   q=p->next;
			   p->next=p->next->next;
			   delete q;
		   }else{
			   p=p->next;
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

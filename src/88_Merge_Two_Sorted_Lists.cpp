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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
       if (!l1)return l2; 
	   if (!l2)return l1;
	   ListNode *head=new ListNode(0),*tail=head;
	   ListNode *p1=l1,*p2=l2;
	   while(p1 && p2){
		   if (p1->val<p2->val){
			  tail->next=p1; 
			  tail=p1;
			  p1=p1->next;
		   }else{
			  tail->next=p2;
			  tail=p2;
			  p2=p2->next;
		   }
	   }
	   if (p2)std::swap(p1,p2);
	   while(p1){
		   tail->next=p1;
		   tail=p1;
		   p1=p1->next;
	   }
	   p1=head->next;
	   delete head;
	   return p1;
    }
};

int main(){
	Solution so;
	string line;
	while(getline(cin,line)){
		ListNode *l1=string2list(line);
		getline(cin,line);
		ListNode *l2=string2list(line);
		cout<<list2string(so.mergeTwoLists(l1,l2))<<endl;
	}
}

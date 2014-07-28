#include<cppstdlib.hpp>
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};

ListNode* string2list(const string& s){
	stringstream ss(s);
	int val;
	ListNode *head=NULL,*tail=NULL;
	while(ss>>val){
		ListNode *t=new ListNode(val);
		if (!tail) head=tail=t;	
		else{
			tail->next=t;
			tail=t;
		}
	}
	return head;
}

string list2string(const ListNode* L){
	stringstream ss;
	while(L){
		ss<<L->val<<" ";
		L=L->next;
	}
	return ss.str();
}

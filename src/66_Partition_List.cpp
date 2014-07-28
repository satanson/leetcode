#include<list_serialize.hpp>
class Solution{
public:
	ListNode *partition(ListNode *head,int x){
		if (!head)return NULL;
		ListNode *lt_head=new ListNode(0),*lt_tail=lt_head;
		ListNode *ge_head=new ListNode(0),*ge_tail=ge_head;

		ListNode *p=head;
		while(p){
			if (p->val<x){
				lt_tail->next=p;
				lt_tail=p;
			}else{
				ge_tail->next=p;
				ge_tail=p;
			}
			p=p->next;
		}
		p=lt_head->next;
		lt_tail->next=ge_head->next;
		ge_tail->next=NULL;
		delete lt_head;
		delete ge_head;
		return p;
	}
};

int main(){
	Solution so;
	string line;
	while(getline(cin,line)){
		string sval;
		getline(cin,sval);
		stringstream ss(sval);
		int x;
		ss>>x;
		cout<<list2string(so.partition(string2list(line),x))<<endl;
	}
}

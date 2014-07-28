#include<list_serialize.hpp>
class Solution {
public:
	ListNode *reverseBetween(ListNode *head,int m,int n){
		ListNode *p=new ListNode(0);
		p->next=head;
		head=p;

		int k=0;
		while(++k<m) p=p->next;

		ListNode *q=NULL,*h=NULL,*t=NULL;
		k=0;
		q=p->next;
		while(k++<n-m+1){
			t=q->next;
			q->next=h;
			h=q;
			q=t;
		}

		p->next->next=t;
		p->next=h;
		p=head->next;
		delete head;
		return p;
	}
};
int main(){
	Solution so;
	string line;
	while(getline(cin,line)){
		string mn;
		getline(cin,mn);
		stringstream ss(mn);
		int m,n;
		ss>>m>>n;
		cout<<list2string(so.reverseBetween(string2list(line),m,n))<<endl;
	}
}

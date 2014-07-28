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

vector<int> string2vector(const string& s){
	list<int> L=string2list(s);
	return vector<int>(L.begin(),L.end());
}

string<int> vector2string(const vector<int>& v){
	list<int> L(v.begin(),v.end());
	return list2string(L);
}

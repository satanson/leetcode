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
	stringstream ss(s);
	int val;
	vector<int> v;
	while(ss>>val)v.push_back(val);
	return v;
}

string vector2string(const vector<int>& v){
	stringstream ss;
	for(int i=0;i<v.size();i++)ss<<v[i]<<" ";
	return ss.str();
}

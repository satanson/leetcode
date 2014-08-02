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
    ListNode *rotateRight(ListNode *head, int k) {
		if (!head ||!head->next)return head;
		ListNode*p=head;
		int n=1;
		while(p->next)p=p->next,++n;
		p->next=head;
		cout<<"n="<<n<<endl;
		k%=n;
		k=n-(k-1);
		cout<<"k="<<k<<endl;
		while(k>1)p=p->next,--k;
		head=p->next;
		p->next=NULL;
		return head;
    }
};

int main(){
	Solution so;
	string line;
	while(getline(cin,line)){
		ListNode *head=string2list(line);
		getline(cin,line);
		vector<int> k=string2vector<int>(line);
		cout<<list2string(so.rotateRight(head,k[0]))<<endl;
	}
}

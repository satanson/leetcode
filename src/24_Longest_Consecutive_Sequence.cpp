#include<cppstdlib.hpp>
class Solution {
public:
	typedef list<int> LIST;
	typedef unordered_map<int,LIST*> MAP;
    int longestConsecutive(vector<int> &num) {
		MAP m;
		for(int i=0;i<num.size();i++){
			int n=num[i];
			if (!m.count(n-1)&&!m.count(n+1)){
				m[n]=new LIST();
			}else if (!m.count(n-1)&&m.count(n+1)){
				m[n]=m[n+1];
			}else if (m.count(n-1)&&!m.count(n+1)){
				m[n]=m[n-1];
			}else{
				m[n-1]->splice(m[n-1]->end(),*m[n+1]);
				m[n]=m[n-1];
				m[n+1]=m[n-1];
			}
			m[n]->push_back(n);
		}
		MAP::iterator it;
		int N=0;
		set<LIST*> ptrs;
		for (it=m.begin();it!=m.end();it++){
			if(N<it->second->size())N=it->second->size();
			if(!ptrs.count(it->second))ptrs.insert(it->second);
		}
		set<LIST*>::iterator it0;
		for (it0=ptrs.begin();it0!=ptrs.end();it0++)delete *it0;
		return N;
    }
};
int main()
{
	string line;
	Solution so;
	while(getline(cin,line)){
		stringstream ss(line);
		int i;
		vector<int> nums;
		while(ss>>i)nums.push_back(i);
		cout<<so.longestConsecutive(nums)<<endl;
	}
}

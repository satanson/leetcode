#include<cppstdlib.hpp>
class Solution {
public:
	typedef list<int> LIST;
	typedef unordered_map<int,LIST*> MAP;
    int longestConsecutive(vector<int> &num) {
		MAP m;
		set<LIST*> s;
		for(int i=0;i<num.size();i++){
			int n=num[i];
			if (!m.count(n-1)&&!m.count(n+1)){
				m[n]=new LIST();
			}else if (!m.count(n-1)&&m.count(n+1)){
				s.erase(m[n+1]);
				m[n]=m[n+1];
			}else if (m.count(n-1)&&!m.count(n+1)){
				s.erase(m[n-1]);
				m[n]=m[n-1];
			}else{
				s.erase(m[n-1]);
				s.erase(m[n+1]);
				m[n-1]->splice(m[n-1]->end(),*m[n+1]);
				m[n]=m[n-1];
				m[n+1]=m[n-1];
			}
			m[n]->push_back(n);
			s.insert(m[n]);
		}
		int N=0;
		set<LIST*>::iterator it;
		for (it=s.begin();it!=s.end();it++){
			if ((*it)->size()>N)N=(*it)->size();
			delete *it;
		}
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

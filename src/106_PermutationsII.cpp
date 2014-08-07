#include<list_serialize.hpp>
class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
		unordered_map<int,int> m;
		for(int i=0;i<num.size();++i)++m[num[i]];
		list<list<int>>ps=perm(m);
		vector<vector<int>> result;
		for(auto it=ps.begin();it!=ps.end();it++){
			result.push_back(vector<int>(it->begin(),it->end()));
		}
		return result;
    }
	list<list<int>> perm(unordered_map<int,int>& m){
		list<list<int>> ps;
		bool allzero=true;
		for (auto it=m.begin();it!=m.end();++it){

			if(it->second>0){
				allzero=false;
				--it->second;
				list<list<int>> subps=perm(m);
				for(auto it0=subps.begin();it0!=subps.end();++it0)it0->push_front(it->first);
				ps.splice(ps.end(),subps);
				++it->second;
			}
		}
		if (allzero)return list<list<int>>(1,list<int>());
		return ps;
	}
};

int main(){
	Solution so;
	string line;
	while(getline(cin,line)){
		vector<int> num=string2vector<int>(line);
		vector<vector<int>> perms=so.permuteUnique(num);
		for(int i=0;i<perms.size();i++)cout<<vector2string<int>(perms[i])<<endl;
		cout<<string(10,'#')<<endl;
	}
}

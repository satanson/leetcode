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
		if(m.size()==1){
			auto it=m.begin();
			ps.push_back(list<int>(it->second,it->first));
		}
		for (auto it=m.begin();it!=m.end();++it){
			int k=it->first;
			int v=it->second;
			if(v>1){
				--it->second;
			}else{
				m.erase(it);
			}

			list<list<int>> subps=perm(m);
			for(auto it0=subps.begin();it0!=subps.end();++it0)it0->push_front(k);
			ps.splice(ps.end(),subps);

			m[k]=v;
		}
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
	}
}

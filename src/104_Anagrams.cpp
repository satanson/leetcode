#include<list_serialize.hpp>
class Solution {
public:
	vector<string> anagrams(vector<string> &strs) {
		unordered_map<string,vector<int>> m;
		vector<string> a;
		for(int i=0;i<strs.size();i++){
			string key=strs[i];
			sort(key.begin(),key.end());
			m[key].push_back(i);
		}
		for(auto it=m.begin();it!=m.end();it++){
			if(it->second.size()<2)continue;
			for(int i=0;i<it->second.size();i++)a.push_back(strs[it->second[i]]);
		}
		return a;
	}
};

int main(){
	Solution so;
	string line;
	while(getline(cin,line)){
		vector<string> words=string2vector<string>(line);
		cout<<vector2string<string>(so.anagrams(words)," ")<<endl;
	}
}

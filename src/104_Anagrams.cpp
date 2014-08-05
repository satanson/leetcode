#include<list_serialize.hpp>
class Solution {
public:
	vector<string> anagrams(vector<string> &strs) {
		vector<vector<int>> group;
		vector<string> flatgroup;
		if (strs.size()==0)return flatgroup;

		group.push_back(vector<int>(1,0));
		for (int i=1;i<strs.size();i++){
			int j=0;
			for (j=0;j<group.size();j++){
				if (isAnagram(strs[i],strs[group[j][0]])){
					group[j].push_back(i);
					break;
				}
			}
			if (j==group.size()){
				group.push_back(vector<int>(1,i));
			}	
		}
		for (int i=0;i<group.size();i++){
			if (group[i].size()==1)continue;
			
			for(int j=0;j<group[i].size();j++)
				flatgroup.push_back(strs[group[i][j]]);
		}
		return flatgroup;
	}
	bool isAnagram(const string& lhs,const string& rhs){
		if (lhs.size()!=rhs.size()) return false;
		unordered_map<char,int> m1,m2;
		for(int i=0;i<lhs.size();++i)++m1[lhs[i]];
		for(int i=0;i<rhs.size();++i)++m2[rhs[i]];
		for(auto it=m1.begin();it!=m1.end();it++){
			if (m2.count(it->first)==0||m2[it->first]!=it->second)return false;
		}
		return true;
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

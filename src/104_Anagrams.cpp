#include<list_serialize.hpp>
class Solution {
public:
	vector<string> anagrams(vector<string> &strs) {
		vector<vector<int>> group;
		vector<string> flatgroup;
		if (strs.size()==0)return flatgroup;
		vector<unordered_map<char,int>> m(strs.size());
		for(int i=0;i<strs.size();i++){
			for(int j=0;j<strs[i].size();j++)++m[i][strs[i][j]];
		}
		group.push_back(vector<int>(1,0));
		for (int i=1;i<strs.size();i++){
			int j=0;
			for (j=0;j<group.size();j++){
				if (strs[i].size()==strs[group[j][0]].size() && isAnagram(m[i],m[group[j][0]])){
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
	bool isAnagram(unordered_map<char,int> m1,unordered_map<char,int> m2){
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

#include<cppstdlib.hpp>
class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
		list<list<int>> q1,q2;
		vector<string> v;
		v.reserve(dict.size()+2);
		v.push_back(start);
		v.push_back(end);
		dict.insert(end);

		q1.push_back(list<int>());q1.back().push_back(0);
		while(!q1.empty() &&!dict.empty()){
			while(!q1.empty()){
				list<int> path;std::swap(q1.back(),path);q1.pop_back();
				string& s1=v[path.back()];
				for (int i=0;i<s1.size();i++){
					char c0=s1[i];
					for (char c='a';c<='z';c++){
						if (c==c0)continue;
						s1[i]=c;
						if (s1==end)return path.size()+1;

						if (dict.count(s1)>0){
							v.push_back(s1);
							q2.push_back(path);q2.back().push_back(v.size()-1);
							dict.erase(s1);
						}
					}
					s1[i]=c0;
				}
			}
			std::swap(q1,q2);
		}
		return 0;
	}
};

int main(){
	Solution so;
	string start,end,words;
	while(getline(cin,start)){
		getline(cin,end);
		getline(cin,words);
		stringstream ss(words);
		string word;
		unordered_set<string> dict;
		while(ss>>word)dict.insert(word);
		cout<<so.ladderLength(start,end,dict)<<endl;
	}
}

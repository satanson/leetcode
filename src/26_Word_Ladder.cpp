#include<cppstdlib.hpp>
class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
		list<list<string>> q1,q2;
		//dict.insert(end);
		q1.push_back(list<string>());q1.back().push_back(start);
		while(!q1.empty()){
			while(!q1.empty()){
				list<string> path;std::swap(q1.back(),path);q1.pop_back();
				string s1=path.back();
				for (int i=0;i<s1.size();i++){
					char c0=s1[i];
					for (char c='a';c<='z';c++){
						if (c==c0)continue;
						s1[i]=c;
						if (s1==end)return path.size()+1;

						if (dict.count(s1)>0){
							q2.push_back(path);q2.back().push_back(s1);
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

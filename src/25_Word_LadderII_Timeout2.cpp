#include<cppstdlib.hpp>
class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
		vector<string> t;
		unordered_map<string,int> m;
		t.reserve(dict.size()+2);
		t.push_back(start);
		t.push_back(end);
		for (auto e=dict.begin();e!=dict.end();e++){
			string w=*e;
			t.push_back(w);
			m[w]=t.size()-1;
		}

		list<list<int>> q1,q2,q;
		list<string> junk;

		vector<vector<string>> ladders;
		q1.push_back(list<int>());q1.back().push_back(0);
		dict.insert(end);
		while(!q1.empty() ){
			while(!q1.empty()){

				list<int> path;std::swap(q1.back(),path);q1.pop_back();
				string& s=t[path.back()];
				for (int i=0;i<s.size();i++){
					string s1=s;
					for (char c='a';c<='z';c++){
						s1[i]=c;
						if (c==s[i])continue;
						if (s1==end){
							if(ladders.empty()||ladders.back().size()==path.size()+1){
								q.push_back(path);q.back().push_back(1);
							}else continue;
						}

						if (dict.count(s1)>0){
							q2.push_back(path);q2.back().push_back(m[s1]);
							junk.push_back(s1);
						}
					}
				}
			}
			while(!junk.empty()){dict.erase(junk.back());junk.pop_back();}
			std::swap(q1,q2);
			if (!q.empty()) break;
		}
		while(!q.empty()){
			list<int> path;std::swap(path,q.back());q.pop_back();
			ladders.push_back(vector<string>());
			while(!path.empty()){ladders.back().push_back(t[path.front()]);path.pop_front();}
		}
		return ladders;
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
		vector<vector<string>> v=so.findLadders(start,end,dict);
		for (int  i=0;i<v.size();i++){
			for (int j=0;j<v[i].size();j++)cout<<v[i][j]<<" ";
			cout<<endl;
		}
	}
}

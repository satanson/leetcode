#include<cppstdlib.hpp>
class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {

		unordered_map<string,list<string>> trace;
		list<string> q1,q2;

		dict.insert(start);
		dict.insert(end);

		q1.push_back(start);

		while(!q1.empty()){
			while(!q1.empty()){
				string s;std::swap(q1.back(),s);q1.pop_back();
				dict.erase(s);
				for (int i=0;i<s.size();i++){
					string s1=s;
					for (char c='a';c<='z';c++){
						s1[i]=c;
						if (c==s[i])continue;
						if (dict.count(s1)>0){
							trace[s1].push_back(s);
							q2.push_back(s1);
						}
					}
				}
			}
			std::swap(q1,q2);
			if(trace.count(end)>1)break;
		}
		vector<vector<string>> ladders;
		if (trace[end].empty())return ladders;
		vector<string> path;
		buildPath(trace,end,path,ladders);
		return ladders;
	}
	void buildPath(unordered_map<string,list<string>>& trace, string& word, vector<string>& path,
			vector<vector<string>>& ladders){
		if (trace[word].size()==0){
			path.push_back(word);
			ladders.push_back(vector<string>(path.rbegin(),path.rend()));
			path.pop_back();
			return;
		}else{
			path.push_back(word);
			for (auto it=trace[word].begin();it!=trace[word].end();it++)
				buildPath(trace,*it,path,ladders);
			path.pop_back();
		}
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

#include<cppstdlib.hpp>
class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
		vector<string> v;
		v.resize(dict.size()+2);
		v.push_back(start);
		v.push_back(end);
		for (auto it=dict.begin();it!=dict.end();it++){
			v.push_back(*it);
		}
		
		vector<list<int>> graph(v.size());
		for ( int i=0;i<v.size();i++){
			for (int j=i+1;j<v.size();j++){
				if(joinable(v[i],v[j])){graph[i].push_back(j);graph[j].push_back(i);}
			}
		}
		list<list<int>> q1,q2;
		q1.push_back(list<int>());
		q1.back().push_back(0);
		while(!q1.empty()){
			while(!q1.empty()){
				list<int> path;
				std::swap(q1.back(),path);
				q1.pop_back();
				int v1=path.back();
				list<int>& v1_neighbors=graph[v1];
				while(!v1_neighbors.empty()){
					int v2=v1_neighbors.back();v1_neighbors.pop_back();
					if (v2==1)return path.size()+1;
					else {q2.push_back(path);q2.back().push_back(v2);}
				}
			}
			std::swap(q1,q2);
		}
		return 0;
    }
	bool joinable(const string& a,const string& b){
		if(a.size()!=b.size())return false;
		int n=0;
		for(int i=0;i<a.size();i++)if(a[i]!=b[i])n++;
		return n==1;
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

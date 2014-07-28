#include<cppstdlib.hpp>
#include<list_serialize.hpp>

class Solution{
public:
	vector<vector<int>> subsetsWithDup(vector<int>& s){
		map<int,int> m;
		for(int i=0;i<s.size();i++)m[s[i]]++;
		vector<pair<int,int>> a(m.begin(),m.end());
		sort(a.begin(),a.end());

		vector<vector<int>> v1,v2;
		v1.push_back(vector<int>());
		for (int i=0;i<a.size();i++){
			int e=a[i].first;
			int n=a[i].second;
			while(!v1.empty()){
				vector<int> v;
				std::swap(v1.back(),v);
				v1.pop_back();

				v2.push_back(v);
				for (int j=0;j<n;j++){
					v.push_back(e);
					v2.push_back(v);
				}
			}
			std::swap(v1,v2);
		}
		return v1;
	}
};

int main(){
	Solution so;
	string line;
	while(getline(cin,line)){
		vector<int> s=string2vector(line);
		vector<vector<int>> v=so.subsetsWithDup(s);
		cout<<string(5,'#')<<v.size()<<string('5','#')<<endl;
		for (int i=0;i<v.size();i++)cout<<vector2string(v[i])<<endl;
		cout<<string(10,'#')<<endl;
	}
}

#include<cppstdlib.hpp>
#include<list_serialize.hpp>
class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
		int N=S.size();
		int N2=1<<N;
		vector<vector<int>> sets(N2);
		for (int i=0;i<N;i++){
			int bit_i=1<<i;
			for (int j=0;j<sets.size();j++){
				if (bit_i&j) sets[j].push_back(S[i]);
			}
		}
		return sets;
    }
};

int main(){
	Solution so;
	string line;
	while(getline(cin,line)){
		vector<int> S=string2vector(line);
		vector<vector<int>> sets=so.subsets(S);
		for (int i=0;i<sets.size();i++){
			cout<<"[";
			for (int j=0;j<sets[i].size();j++)cout<<sets[i][j]<<" ";
			cout<<"]"<<endl;
		}
	}
}

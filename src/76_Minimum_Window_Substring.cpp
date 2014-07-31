#include<cppstdlib.hpp>
class Solution {
public:
    string minWindow(string S, string T){
		int M=S.size(),N=T.size();
		unordered_map<char,int> m;
		for(int i=0;i<N;i++)m[T[i]]=i;
		vector<int> p(N,-1);
		int i=0,j=M;

		for (int k=0;k<M;k++){
			if(m.count(S[k])==0)continue;
			p[m[S[k]]]=k;
			int i0=*std::min_element(p.begin(),p.end());
			int j0=*std::max_element(p.begin(),p.end());
			if (i0==-1 || j0==-1)continue;
			if (j-i>j0-i0) j=j0,i=i0;
		}
		
		return j==M?"":S.substr(i,j+1-i);
    }
};
int main(){
	Solution so;
	string S,T;
	while(getline(cin,S)){
		getline(cin,T);
		cout<<so.minWindow(S,T)<<endl;
	}
}

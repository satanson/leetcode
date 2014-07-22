#include<cppstdlib.hpp>
class Solution {
public:
	//OPT(n,m)=0,n<m
	//OPT(n,0)=1,
	//OPT(n,m)=OPT(n-1,m)+OPT(n-1,m-1), 0<m<=n && S[n-1]==T[m-1];
	//OPT(n,m)=OPT(n-1,m),0<m<=n && S[n-1]!=T[m-1]
    int numDistinct(string S, string T) {
        int N=S.size()+1;
		int M=T.size()+1;
		vector<vector<int>> o(N,vector<int>(M,0));
		int n=0,m=0;
		for(n=0;n<N;n++)o[n][0]=1;
		for(m=0;m<M;m++)
			for(n=0;n<m;n++)o[n][m]=0;
		for(m=1;m<M;m++)
			for(n=m;n<N;n++){
				if (S[n-1]==T[m-1])o[n][m]=o[n-1][m]+o[n-1][m-1];
				else o[n][m]=o[n-1][m];
			}
		return o[N-1][M-1];
    }
};

int main(){
	Solution so;
	string S,T;
	while(getline(cin,S)){
		getline(cin,T);
		cout<<so.numDistinct(S,T)<<endl;
	}
}

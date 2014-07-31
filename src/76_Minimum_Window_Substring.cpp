#include<cppstdlib.hpp>
class Solution {
public:
    string minWindow(string S, string T){
		int M=S.size(),N=T.size();
		if (!M*N) return "";
		std::fill(inf,inf+sizeof(inf),0);
		std::fill(sup,sup+sizeof(sup),0);
		int i=0,j=0;
		for (i=0;i<N;++i)++inf[T[i]];
		int count=0;
		for (i=0;i<M;i++){
			if (sup[S[i]]<inf[S[i]])++count;
			++sup[S[i]];
			if (count==N)break;
		}
		for (j=0;j<M;j++){
			if(sup[S[i]]>inf[S[i]])--sup[S[i]];
			else break;
		}
		return i==M?"":S.substr(j,i+1-j);
    }
private:
	int inf[256];
	int sup[256];
};
int main(){
	Solution so;
	string S,T;
	while(getline(cin,S)){
		getline(cin,T);
		cout<<so.minWindow(S,T)<<endl;
	}
}

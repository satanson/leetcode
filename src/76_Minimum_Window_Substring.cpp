#include<cppstdlib.hpp>
class Solution {
public:
    string minWindow(string S, string T){
		int M=S.size(),N=T.size();
		if (!M*N) return "";

		std::fill(inf,inf+256,0);
		std::fill(sup,sup+256,0);
		int i=0,j=0,j0=0;
		int size=INT_MAX;
		for (i=0;i<N;++i)++inf[T[i]];
		int count=0;
		for (i=0;i<M;i++){
			if (sup[S[i]]<inf[S[i]])++count;
			++sup[S[i]];

			if (count==N){
				while(true){
					if(sup[S[j]]>inf[S[j]]){
						--sup[S[j]];
						++j;
					}else
						break;
				}
				if(size>i+1-j){
					size=i+1-j;
					j0=j;
				}
			}
		}
		return size==INT_MAX?"":S.substr(j0,size);
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

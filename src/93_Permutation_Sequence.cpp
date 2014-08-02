#include<cppstdlib.hpp>
#include<list_serialize.hpp>
class Solution {
public:
    string getPermutation(int n, int k) {
		vector<int> invseq(n,0);
		for( int i=1;i<k;++i){
			int j=n-1;
			while(j>=0 && invseq[j]==n-1-j)--j;
			if (j==-1)invseq=vector<int>(n,0);
			else{
				++invseq[j];
				while(++j<n)invseq[j]=0;
			}
		}
		string seq(n,0),perm(n,0);
		//cout<<vector2string<int>(invseq)<<endl;
		for (int i=0;i<n;++i)seq[i]='1'+i;
		for (int i=0;i<n;++i){
			perm[i]=seq[invseq[i]];
			seq.erase(invseq[i],1);
		}
		return perm;
    }
};

int main(){
	Solution so;
	string line;
	while(getline(cin,line)){
		vector<int> nk=string2vector<int>(line);
		cout<<so.getPermutation(nk[0],nk[1])<<endl;
	}
}

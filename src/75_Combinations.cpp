#include<list_serialize.hpp>
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
		vector<vector<int>> s;
		if (n<k) return s;
		long long N=factorial(n)/factorial(k)/factorial(n-k);
		s.reserve(N);
		s.push_back(vector<int>(k));
		for(int i=0;i<k;i++)s[0][i]=i+1;
		for (int i=1;i<N;i++){
			s.push_back(vector<int>(k));

			//j+1<=s[i][j]<<n-k+(j+1)
			int j=0;
			for (j=k-1;j>=0 && s[i-1][j]==n-k+(j+1);j--);
			if (j==-1) break;

			for (int j0=0;j0<j;j0++)s[i][j0]=s[i-1][j0];

			s[i][j]=s[i-1][j]+1;
			
			for (int j0=j+1;j0<k;j0++)s[i][j0]=s[i][j]+j0-j;
		}
		return s;
    }
	long long factorial(long long n){
		long long m=1;
		while(n>0){m*=n;--n;}
		return m;
	}
};
int main(){
	Solution so;
	string line;
	while(getline(cin,line)){
		vector<int> S=string2vector<int>(line);
		vector<vector<int>> sets=so.combine(S[0],S[1]);
		for (int i=0;i<sets.size();i++){
			cout<<"[";
			for (int j=0;j<sets[i].size();j++)cout<<sets[i][j]<<" ";
			cout<<"]"<<endl;
		}
	}
}

#include<cppstdlib.hpp>
class Solution{
public:
	bool isScramble(string s1,string s2){
		if (s1.size()!=s2.size())return false;
		string s1_dup=s1,s2_dup=s2;
		sort(s1_dup.begin(),s1_dup.end());
		sort(s2_dup.begin(),s2_dup.end());
		if (s1_dup!=s2_dup)return false;

		int N=s1.size();
		vector<vector<vector<bool>>> d(N+1,vector<vector<bool>>(N,vector<bool>(N)));
		for (int i=0;i<N;i++){
			for (int j=0;j<N;j++){
				if (s1[i]==s2[j])d[1][i][j]=true;
				else d[1][i][j]=false;
			}
		}

		for (int l=2;l<=N;l++){
			for ( int i=0;i+l<=N;i++){
				for (int j=0;j+l<=N;j++){
					for (int k=1;k<l;k++){
						d[l][i][j] =d[l][i][j] || d[k][i][j]&&d[l-k][i+k][j+k]||d[k][i][j+l-k] && d[l-k][i+k][j];
					}
				}
			}
		}
		return d[N][0][0];
	}
};

int main(){
	Solution so;
	string s1,s2;
	while(getline(cin,s1)){
		getline(cin,s2);
		cout<<boolalpha<<so.isScramble(s1,s2)<<endl;
	}
}

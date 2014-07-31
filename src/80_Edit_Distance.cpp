#include<list_serialize.hpp>
class Solution {
	public:
		int minDistance(string word1, string word2) {
			if(word1.size()==0)return word2.size();
			if(word2.size()==0)return word1.size();
			int M=word1.size(),N=word2.size();
			vector<vector<int>> dist(M+1,vector<int>(N+1));
			int i=0,j=0;
			for (i=0;i<=M;i++)dist[i][0]=i;
			for (j=0;j<=N;j++)dist[0][j]=j;

			for (i=1;i<=M;i++){
				for (j=1;j<=N;j++){
					if (word1[i-1]!=word2[j-1]){
						int d=0;
						if (dist[i-1][j-1] < dist[i-1][j] && dist[i-1][j-1] < dist[i][j-1]){
							d=dist[i-1][j-1];
						}else if (dist[i-1][j]<dist[i][j-1]){
							d=dist[i-1][j];
						}else {
							d=dist[i][j-1];
						}
						dist[i][j]=d+1;
					}else{
						dist[i][j]=dist[i-1][j-1];
					}
				}
			}
			return dist[M][N];
		}
};

int main(){
	string word1,word2;
	Solution so;
	while(getline(cin,word1)){
		getline(cin,word2);
		cout<<so.minDistance(word1,word2)<<endl;
	}
}

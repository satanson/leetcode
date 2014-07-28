#include<cppstdlib.hpp>
class Solution {
public:
     int numTrees(int n){
                vector<vector<int>> d(n+2,vector<int>(n+2));
                for (auto i=0;i<=n;i++){
                        d[i+1][i]=1;
                        d[i][i]=1;
                }
                for (auto L=1;L<n;L++){
                        for (auto i=1;i+L<=n;i++){
                                int j=i+L;
                                d[i][j]=0;
                                for (auto k=i;k<=j;k++){
                                        d[i][j]+=d[i][k-1]*d[k+1][j];
                                }
                        }
                }
                return d[1][n];
        }

};
int main(){
	Solution so;
	int n;
	while(cin>>n){
		cout<<so.numTrees(n)<<endl;
	}
}

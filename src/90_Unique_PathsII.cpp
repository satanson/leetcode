#include<list_serialize.hpp>
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
		if(obstacleGrid.size()==0||obstacleGrid[0].size()==0)return 0;

		int M=obstacleGrid.size(),N=obstacleGrid[0].size();
		vector<vector<int>> roads(M,vector<int>(N,0));
		roads[0][0]=obstacleGrid[0][0]==1?0:1;
		for (int i=1;i<M;i++){
			if (obstacleGrid[i][0]==0){
				roads[i][0]=obstacleGrid[i-1][0]==1?0:roads[i-1][0];
			}else{
				roads[i][0]=0;
			}
		}
		for (int j=1;j<N;j++){
			if (obstacleGrid[0][j]==0){
				roads[0][j]=obstacleGrid[0][j-1]==1?0:roads[0][j-1];
			}else{
				roads[0][j]=0;
			}
		}
		for (int i=1;i<M;i++){
			for (int j=1;j<N;j++){
				if (obstacleGrid[i][j]==0){
					roads[i][j]+=obstacleGrid[i-1][j]==1?0:roads[i-1][j];
					roads[i][j]+=obstacleGrid[i][j-1]==1?0:roads[i][j-1];
				}else{
					roads[i][j]=0;
				}
			}
		}
		return roads[M-1][N-1];
    }
};
int main(){
	Solution so;
	vector<vector<int>> grids;
	string line;
	while(getline(cin,line)){
		grids.push_back(string2vector<int>(line));
	}
	cout<<so.uniquePathsWithObstacles(grids)<<endl;
}

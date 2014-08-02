#include<list_serialize.hpp>
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
       if (grid.size()==0 ||grid[0].size()==0) return 0; 
	   int M=grid.size(),N=grid[0].size();
	   for (int i=1;i<M;i++)grid[i][0]+=grid[i-1][0];
	   for (int j=1;j<N;j++)grid[0][j]+=grid[0][j-1];
	   
	   for (int i=1;i<M;i++){
		   for (int j=1;j<N;j++){
			   grid[i][j]+=grid[i-1][j]<grid[i][j-1] ? grid[i-1][j]:grid[i][j-1];
		   }
	   }
	   return grid[M-1][N-1];
    }
};

int main(){
	Solution so;
	string line;
	vector<vector<int>> grid;
	while(getline(cin,line)){
		grid.push_back(string2vector<int>(line));
	}
	cout<<so.minPathSum(grid)<<endl;
}

#include<list_serialize.hpp>
#include<cppstdlib.hpp>
class Solution {
public:
    int uniquePaths(int m, int n) {
		vector<vector<int>> grid(m,vector<int>(n,1));
		for (int i=1;i<m;i++){
			for (int j=1;j<n;j++){
				grid[i][j]=grid[i-1][j]+grid[i][j-1];
			}
		}
		return grid[m-1][n-1];
    }
};

int main(){
	Solution so;
	string line;
	while(getline(cin,line)){
		vector<int> mn=string2vector<int>(line);
		cout<<so.uniquePaths(mn[0],mn[1])<<endl;
	}
}

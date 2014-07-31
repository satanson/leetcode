#include<list_serialize.hpp>
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {    
		if (matrix.size()==0 ||matrix[0].size()==0)return;
		int M=matrix.size(),N=matrix[0].size();
		int i=0,j=0;
		int row0=1,col0=1;
		for (i=0;i<M;i++)if(matrix[i][0]==0)row0=0;
		for (i=0;i<N;i++)if(matrix[0][i]==0)col0=0;

		for (i=0;i<M;i++){
			for (j=0;j<N;j++){
				if (matrix[i][j]==0)matrix[i][0]=0,matrix[0][j]=0;
			}
		}
		for (i=1;i<M;i++){
			for (j=1;j<N;j++){
				if (matrix[i][0]==0 || matrix[0][j]==0) matrix[i][j]=0;
			}
		}
		if (row0==0)
			for (i=0;i<M;i++) matrix[i][0]=0;
		if (col0==0)
			for (i=0;i<N;i++) matrix[0][i]=0;
    }
};
int main(){
	Solution so;
	string line;
	vector<vector<int>> matrix;
	while(getline(cin,line)){
		matrix.push_back(string2vector(line));
	}
	so.setZeroes(matrix);
	cout<<string(matrix.size(),'#')<<endl;
	for (int i=0;i<matrix.size();i++){
		for (int j=0;j<matrix[i].size();j++){
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<string(matrix.size(),'#')<<endl;
}

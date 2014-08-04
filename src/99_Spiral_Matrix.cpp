#include<list_serialize.hpp>
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int> > &matrix) {
		vector<int> seq;
		if (matrix.size()==0 || matrix[0].size()==0) return seq;
		int M=matrix.size(),N=matrix[0].size();
		seq.reserve(M*N);
		bool flip=true;
		int start=0;
		int tr_r=0,tr_c=0,bl_r=M-1,bl_c=N-2;
		for (int i=M;i>0;--i){
			if(flip)
				walk_topright(matrix,i,i+N-M,tr_r++,tr_c++,seq);
			else
				walk_bottomleft(matrix,i,i+N-M,bl_r--,bl_c--,seq);
			flip=!flip;
		}
		return seq;
	}
	void walk_topright(vector<vector<int>>& matrix,int m,int n,int r,int c,vector<int>& seq){
		for(int i=0;i<m-1;i++)seq.push_back(matrix[r][c+i]);
		for(int i=0;i<n;i++)seq.push_back(matrix[r+i][c+m-1]);
	}

	void walk_bottomleft(vector<vector<int>>& matrix,int m,int n,int r,int c,vector<int>& seq){
		for (int i=0;i<m-1;i++)seq.push_back(matrix[r][c-i]);
		for (int i=0;i<n;i++)seq.push_back(matrix[r-i][c-(m-1)]);
	}
};

int main(){
	Solution so;
	vector<vector<int>> matrix;
	string line;
	while(getline(cin,line))matrix.push_back(string2vector<int>(line));
	cout<<vector2string<int>(so.spiralOrder(matrix))<<endl;
}

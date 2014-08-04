#include<list_serialize.hpp>
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int> > &matrix) {
		int N=matrix.size();
		vector<int> seq;
		seq.reserve(N*N);
		bool flip=true;
		int start=0;
		int tr_r=0,tr_c=0,bl_r=N-1,bl_c=N-2;
		for (int i=N;i>0;--i){
			if(flip)
				walk_topright(matrix,i,tr_r++,tr_c++,seq);
			else
				walk_bottomleft(matrix,i,bl_r--,bl_c--,seq);
			flip=!flip;
		}
		return seq;
	}
	void walk_topright(vector<vector<int>>& matrix,int n,int r,int c,vector<int>& seq){
		for(int i=0;i<n-1;i++)seq.push_back(matrix[r][c+i]);
		for(int i=0;i<n;i++)seq.push_back(matrix[r+i][c+n-1]);
	}

	void walk_bottomleft(vector<vector<int>>& matrix,int n,int r,int c,vector<int>& seq){
		for (int i=0;i<n-1;i++)seq.push_back(matrix[r][c-i]);
		for (int i=0;i<n;i++)seq.push_back(matrix[r-i][c-(n-1)]);
	}
};

int main(){
	Solution so;
	vector<vector<int>> matrix;
	string line;
	while(getline(cin,line))matrix.push_back(string2vector<int>(line));
	cout<<vector2string<int>(so.spiralOrder(matrix))<<endl;
}

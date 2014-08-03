#include<list_serialize.hpp>
class Solution {
public:
	vector<vector<int> > generateMatrix(int n) {
		vector<vector<int>> matrix(n,vector<int>(n));
		bool flip=true;
		int start=1;
		int tr_r=0,tr_c=0,bl_r=n-1,bl_c=n-2;
		for (int i=n;i>0;--i){
			if(flip){
				walk_topright(matrix,i,tr_r++,tr_c++,start);
			}else{
				walk_bottomleft(matrix,i,bl_r--,bl_c--,start);
			}
			start+=2*i-1;
			flip=!flip;
		}
		return matrix;
	}
	void walk_topright(vector<vector<int>>& matrix,int n,int r,int c,int start){
		for(int i=0;i<n-1;i++)matrix[r][c+i]=start++;
		for(int i=0;i<n;i++)matrix[r+i][c+n-1]=start++;
	}

	void walk_bottomleft(vector<vector<int>>& matrix,int n,int r,int c,int start){
		for (int i=0;i<n-1;i++)matrix[r][c-i]=start++;
		for (int i=0;i<n;i++)matrix[r-i][c-(n-1)]=start++;
	}
};

int main(){
	Solution so;
	string line;
	while(getline(cin,line)){
		vector<int> n=string2vector<int>(line);
		vector<vector<int>> smatrix=so.generateMatrix(n[0]);
		cout<<string(10,'#')<<endl;
		for(int i=0;i<smatrix.size();i++)cout<<vector2string<int>(smatrix[i],"\t")<<endl;
		cout<<string(10,'#')<<endl;
	}
}

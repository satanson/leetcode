#include<list_serialize.hpp>
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
		if (matrix.size()==0 || matrix[0].size()==0) return false;

		return binsearch(matrix,target,0,matrix.size()*matrix[0].size());
        
    }
	bool binsearch(vector<vector<int>> &matrix,int target, int l ,int h){
		int M=matrix.size(),N=matrix[0].size();
		int lx=l/N,ly=l%N;
		int hx=h/N,hy=h%N;
		if (h-l==0) return false;
		if (h-l==1) return matrix[lx][ly]==target;
		int m=(l+h)/2;
		int mx=m/N,my=m%N;
		if (matrix[mx][my]==target)
			return true;
		else if (matrix[mx][my]<target)
			return binsearch(matrix,target,l,m);
		else 
			return binsearch(matrix,target,m+1,h);
	}
};

int main(){
	Solution so;
	string line;
	vector<int> targets;
	vector<vector<int>> matrix;
	getline(cin,line);
	targets=string2vector(line);
	while(getline(cin,line)){
		matrix.push_back(string2vector(line));
	}
	for (int i=0;i<targets.size();i++){
		cout<<boolalpha<<so.searchMatrix(matrix,targets[i])<<endl;
	}
}

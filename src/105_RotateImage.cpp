#include<list_serialize.hpp>
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
		if(matrix.size()<2)return;
		int N=matrix.size();
		for (int i=N-1;i>0;i-=2){
			int b=(N-i)/2,e=N-b-1;
			for (int c=b;c<e;c++){
				int r=b;
				int tmp=matrix[r][c];
				for (int k=0;k<4;k++){
					int r1=c,c1=N-1-r;
					std::swap(tmp,matrix[r1][c1]);
					r=r1,c=c1;
				}
			}
		}
    }
};

int main(){
	Solution so;
	string line;
	vector<vector<int>> matrix;
	while(getline(cin,line))matrix.push_back(string2vector<int>(line));
	so.rotate(matrix);
	cout<<string(10,'#')<<endl;
	for(int i=0;i<matrix.size();i++)cout<<vector2string<int>(matrix[i],"\t")<<endl;
	cout<<string(10,'#')<<endl;
}

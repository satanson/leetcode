#include<cppstdlib.hpp>
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
		vector<vector<int>> tri(numRows,vector<int>());
		tri[0].push_back(1);
		for (int i=1;i<tri.size();i++){
			vector<int> row(i+1);
			std::swap(tri[i],row);
			tri[i][0]=1;
			for (int j=1;j<tri[i].size()-1;j++){
				tri[i][j]=tri[i-1][j-1]+tri[i-1][j];
			}
			tri[i][tri[i].size()-1]=1;
		}
		return tri;
    }
};

void print (vector<vector<int>>& tri){
	cout<<string(20,'#')<<endl;
	for(int i=0;i<tri.size();i++){
		for(int j=0;j<tri[i].size();j++){
			cout<<tri[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<string(20,'#')<<endl;
}
int main(){
	int n;
	cin>>n;
	Solution so;
	vector<vector<int>> tri=so.generate(n);
	print(tri);
}

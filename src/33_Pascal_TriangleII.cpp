#include<cppstdlib.hpp>
class Solution {
public:
    vector<int> getRow(int rowIndex) {
		vector<vector<int>> tri(rowIndex+1,vector<int>());
		if (tri.size()==0)return vector<int>();
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
		return tri[tri.size()-1];
    }
};

void print (vector<int>& row){
	cout<<string(20,'#')<<endl;
	for(int i=0;i<row.size();i++){
		cout<<row[i]<<"\t";
	}
	cout<<endl<<string(20,'#')<<endl;
}
int main(){
	int n;
	cin>>n;
	Solution so;
	vector<int> row=so.getRow(n);
	print(row);
}

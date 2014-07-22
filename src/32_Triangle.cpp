#include<cppstdlib.hpp>
class Solution {
public:
	int X(int i,int j){return i*(i+1)/2+j;}
    int minimumTotal(vector<vector<int> > &triangle) {
       if(triangle.size()==0)return 0;
	   if(triangle.size()==1)return triangle[0][0];

	   int I=triangle.size();
	   vector<int> paths(I*(I+1)/2);
	   paths[X(0,0)]=triangle[0][0];
	   
	   for (int i=1;i<triangle.size();i++){
		   paths[X(i,0)]=triangle[i][0]+paths[X(i-1,0)];
		   for (int j=1;j<triangle[i].size()-1;j++){
			   if (paths[X(i-1,j-1)]<paths[X(i-1,j)])
				   paths[X(i,j)]=triangle[i][j]+paths[X(i-1,j-1)];
			   else
				   paths[X(i,j)]=triangle[i][j]+paths[X(i-1,j)];
		   } 
		   paths[X(i,triangle[i].size()-1)]=
			   triangle[i][triangle[i].size()-1]
			   +paths[X(i-1,triangle[i-1].size()-1)];
	   }
	   int n=triangle.size()-1;
	   //cout<<string(10,'#')<<endl;
	   //for(int i=0;i<paths.size();i++)cout<<paths[i]<<" ";
	   //cout<<endl<<string(10,'#')<<endl;
	   return *std::min_element(&paths[X(n,0)],&paths[X(n+1,0)]);
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
	string line;
	vector<vector<int>> tri;	
	while(getline(cin,line)){
		stringstream ss(line);
		tri.push_back(vector<int>());
		int a;
		while(ss>>a)tri.back().push_back(a);
	}
	print(tri);
	Solution so;
	cout<<so.minimumTotal(tri)<<endl;
}

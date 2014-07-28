#include<cppstdlib.hpp>
class Solution{
public:
	int maximalRectangle(vector<vector<char>> &matrix){
		if (matrix.size()==0||matrix[0].size()==0)return 0;
		return maxArea(matrix,0,0,matrix.size(),matrix[0].size());
	}
	int maxArea(vector<vector<char>> &matrix,int left,int top,int right,int bottom){
		int width=right-left;
		int height=bottom-top;
		if (width<=0 || height<=0) return 0;
		if (width==1 && height==1 && matrix[left][top]=='1')return 1;
		int x=0,y=0;
		for ( x=left;x<right;x++){
			for (y=top;y<bottom;y++){
				if (matrix[x][y]=='0')goto LOOP;
			}
		}
LOOP:
		if (x==right && y==bottom){
			cout<<"("<<left<<","<<top<<");"
				<<"("<<right<<","<<bottom<<")"<<endl;
			return width*height;
		} else{
			int area=0;
			int subarea=maxArea(matrix,left,top,x-1,y-1);
			if (area<subarea)area=subarea;
			subarea=maxArea(matrix,left,y+1,x-1,bottom);
			if (area<subarea)area=subarea;
			subarea=maxArea(matrix,x+1,top,right,y-1);
			if (area<subarea)area=subarea;
			subarea=maxArea(matrix,x+1,y+1,right,bottom);
			if (area<subarea)area=subarea;
			return area;
		}
	}

};

int main(){
	vector<vector<char>> matrix;
	Solution so;
	string line;
	while(getline(cin,line)){
		matrix.push_back(vector<char>(line.begin(),line.end()));
	}
	cout<<"area="<<so.maximalRectangle(matrix)<<endl;
}

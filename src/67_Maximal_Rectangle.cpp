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
			return width*height;
		} else{
			int area=0;
			//left
			int subarea=maxArea(matrix,left,top,x,bottom);
			if (area<subarea)area=subarea;
			//right
			subarea=maxArea(matrix,x+1,top,right,bottom);
			if (area<subarea)area=subarea;
			//top
			subarea=maxArea(matrix,left,top,right,y);
			if (area<subarea)area=subarea;
			//bottom
			subarea=maxArea(matrix,left,y+1,right,bottom);
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

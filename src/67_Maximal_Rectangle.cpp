#include<cppstdlib.hpp>
class Solution{
public:
	int maximalRectangle(vector<vector<char>> &matrix){
		if (matrix.size()==0||matrix[0].size()==0)return 0;
		int W=matrix.size();
		int H=matrix[0].size();

		vector<vector<vector<vector<bool>>>> d(
				W,vector<vector<vector<bool>>>(
					H,vector<vector<bool>>(
						W+1,vector<bool>(H+1))));

		int area=0;
		for (int left=0;left<W;left++){
			for (int top=0;top<H;top++){
				if (matrix[left][top]=='1'){
					d[left][top][1][1]=true;
					area=1;
				} else d[left][top][1][1]=false;
			}
		}

		for (int w=2;w<=W;w++){
			for (int x=0;x+w<=W;x++){
				for (int y=0;y<H;y++){
					if (d[x][y][1][1] && d[x+1][y][w-1][1]){
						d[x][y][w][1]=true;
						if (area<w)area=w;
					} else d[x][y][w][1]=false;
				}
			}
		}
		for (int h=2;h<=H;h++){
			for (int x=0;x<W;x++){
				for (int y=0;y+h<=H;y++){
					if (d[x][y][1][1] && d[x][y+1][1][h-1]){
						d[x][y][1][h]=true;
						if (area<h)area=h;
					} else d[x][y][1][h]=false;
				}
			}
		}

		for (int w=2;w<=W;w++){
			for (int h=2;h<=H;h++){
				for (int x=0;x+w<=W;x++){
					for (int y=0;y+h<=H;y++){
						if (d[x][y][1][1]&&
								d[x+1][y][w-1][h]&&
								d[x][y+1][w][h-1]&&
								d[x+1][y+1][w-1][h-1]){

							d[x][y][w][h]=true;
							int area0=w*h;
							if (area<area0)area=area0;
						}else d[x][y][w][h]=false;
					}
				}
			}
		}
		return area;
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

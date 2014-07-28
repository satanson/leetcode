#include<cppstdlib.hpp>
class Solution{
public:

    typedef unordered_map<int64_t,unordered_map<int64_t,int>> CACHE;
	int64_t HL(int h,int l){
		int64_t y=h;
		y<<=32;
		y+=l;
		return y;
	}
	bool cached(CACHE& cache,int l,int r,int t,int b){
		int64_t key=HL(l,r),subkey=HL(t,b);
		if (cache.count(key)==0|| cache[key].count(subkey)==0)return false;
		return true;
	}
	int getCache(CACHE& cache,int l,int r,int t,int b){
		int64_t key=HL(l,r),subkey=HL(t,b);
		return cache[key][subkey];
	}
	void setCache(CACHE& cache,int l,int r,int t,int b,int area){
		int64_t key=HL(l,r),subkey=HL(t,b);
		cache[key][subkey]=area;
	}

	int maximalRectangle(vector<vector<char>> &matrix){
		if (matrix.size()==0||matrix[0].size()==0)return 0;
		unordered_map<int64_t,unordered_map<int64_t,int>> cache;
		return maxArea(matrix,0,matrix.size(),0,matrix[0].size(),cache);
	}
	int maxArea(vector<vector<char>> &matrix,int left,int right,int top,int bottom,CACHE& cache){
		int width=right-left;
		int height=bottom-top;
		if (width<=0 || height<=0) return 0;
		if (width==1 && height==1 && matrix[left][top]=='1')return 1;
		bool xflip=true,yflip=true;

		int x=(left+right)/2,y=(top+bottom)/2;
		int xcount=1,ycount=1;
		while(left<=x && x<right){
			while(top<=y && y<bottom){ 
				if (matrix[x][y]=='0')goto LOOP;
				if (yflip)y-=ycount;else y+=ycount;
				++ycount;
				yflip=!yflip;
			}
			if (xflip) x-=xcount; else x+=xcount;
			++xcount;
			xflip=!xflip;
		}

		x=right;y=bottom;
LOOP:
		if (x==right && y==bottom){
			return width*height;
		} else{
			int area=0;
			//left
			int subarea=0;
			if (area<(x-left)*(bottom-top)){
				if (cached(cache,left,x,top,bottom)){
					subarea=getCache(cache,left,x,top,bottom);
				}else{
					subarea=maxArea(matrix,left,x,top,bottom,cache);
					setCache(cache,left,x,top,bottom,subarea);
				}
				if (area<subarea)area=subarea;
			}
			//right
			if (area<(right-x-1)*(bottom-top)){
				if (cached(cache,x+1,right,top,bottom)){
					subarea=getCache(cache,x+1,right,top,bottom);
				}else{
					subarea=maxArea(matrix,x+1,right,top,bottom,cache);
					setCache(cache,x+1,right,top,bottom,subarea);
				}
				if (area<subarea)area=subarea;
			}
			//top
			if (area<(right-left)*(y-top)){
				if (cached(cache,left,right,top,y)){
					subarea=getCache(cache,left,right,top,y);
				}else{
					subarea=maxArea(matrix,left,right,top,y,cache);
					setCache(cache,left,right,top,y,subarea);
				}
				if (area<subarea)area=subarea;
			}
			//bottom
			if (area<(right-left)*(bottom-y-1)){
				if (cached(cache,left,right,y+1,bottom)){
					subarea=getCache(cache,left,right,y+1,bottom);
				}else{
					subarea=maxArea(matrix,left,right,y+1,bottom,cache);
					setCache(cache,left,right,y+1,bottom,subarea);
				}
				if (area<subarea)area=subarea;
			}
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

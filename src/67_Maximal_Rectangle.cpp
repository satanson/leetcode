#include<cppstdlib.hpp>
class Solution{
public:
	struct Hx{int H,x; Hx(int a,int b):H(a),x(b){}};

	int largestRectangleArea(vector<int> &height){
		vector<Hx> stk_internal;
		stk_internal.reserve(height.size()+1);
		stack<Hx,vector<Hx>> stk(stk_internal);
		stk.push(Hx(0,-1));
		int maxArea=0;
		int N=height.size();
		for(int i=0;i<=N;i++){
			int h= i<N?height[i]:0;

			//a dummy Hx on bottom of stack
			while(stk.size()>1 && stk.top().H>=h){
				Hx p=stk.top();stk.pop();
				int area=p.H*(i-stk.top().x-1);
				if (area>maxArea)maxArea=area;
			}
			stk.push(Hx(h,i));
		}
		return maxArea;
	}
	int maximalRectangle(vector<vector<char>>& matrix){
		if (matrix.size()==0 || matrix[0].size()==0)return 0;
		int M=matrix.size(),N=matrix[0].size();
		vector<int> va(N);
		
		for (int i=0;i<N;i++)if(matrix[0][i]=='1')va[i]=1;else va[i]=0;

		int maxArea=largestRectangleArea(va);
		for (int i=1;i<M;i++){
			for (int j=0;j<matrix[i].size();j++)if (matrix[i][j]=='1')va[j]+=1;else va[j]=0;

			int area=largestRectangleArea(va);
			if (area>maxArea)maxArea=area;
		}
		return maxArea;
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

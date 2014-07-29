#include<cppstdlib.hpp>
#include<list_serialize.hpp>
class Solution {
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
};

int main(){
	Solution so;
	string line;
	while(getline(cin,line)){
		vector<int> v=string2vector(line);
		cout<<so.largestRectangleArea(v)<<endl;
	}
}

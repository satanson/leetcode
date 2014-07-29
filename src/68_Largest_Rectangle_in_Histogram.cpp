#include<cppstdlib.hpp>
#include<list_serialize.hpp>
class Solution {
public:
	int largestRectangleArea(vector<int> &height){
		vector<int> stack;
		stack.reserve(height.size());
		int maxArea=0;
		for(int i=0;i<height.size();i++){
			while (!stack.empty() && height[stack.back()]>=height[i]){
					int j=stack.back();stack.pop_back();
					int width=0;
					if (stack.empty())width=i;
					else width=i-stack.back()-1;
					int area=height[j]*width;
					if (area>maxArea)maxArea=area;
			}
			stack.push_back(i);
		}
		while(!stack.empty()){
			int j=stack.back();stack.pop_back();
			int width=0;
			if (stack.empty())width=height.size();
			else width=height.size()-stack.back()-1;
			int area=height[j]*width;
			if (area>maxArea)maxArea=area;
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

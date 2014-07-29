#include<cppstdlib.hpp>
#include<list_serialize.hpp>
class Solution {
public:
	typedef pair<int,int> PAIR;
	int largestRectangleArea(vector<int> &height){
		vector<PAIR> stack;
		stack.reserve(height.size()+1);
		stack.push_back(PAIR(0,-1));
		int maxArea=0;
		for(int i=0;i<=height.size();i++){
			int h=height[i];
			if (i==height.size())h=0;

			while(stack.size()>1 && stack.back().first>=h){
				PAIR p=stack.back();stack.pop_back();
				int area=h*(i-stack.back().second-1);
				if (area>maxArea)maxArea=area;
			}
			stack.push_back(PAIR(h,i));
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

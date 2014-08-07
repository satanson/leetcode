#include<list_serialize.hpp>
class Solution {
public:
	int jump(int A[], int n){
		return jumpall(A,n,0,0,INT_MAX);
	}
	int jumpall(int A[],int n,int i,int jumps,int minjumps){
		if (i>=n-1){
			return std::min(jumps,minjumps);
		}

		++jumps;
		if (jumps>minjumps)return minjumps;
		for (int step=A[i];step>0;--step){
			int j=i+step;
			if (j>=n-1) minjumps=std::min(jumps,minjumps);
			else if (!A[j])continue;
			else {
				minjumps=std::min(jumpall(A,n,j,jumps,minjumps),minjumps);
			}
		}
		return minjumps;
	}
};

int main(){
	Solution so;
	string line;
	while(getline(cin,line)){
		vector<int> A=string2vector<int>(line);
		cout<<so.jump(&A[0],A.size())<<endl;
	}
}

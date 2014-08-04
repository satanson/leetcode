#include<list_serialize.hpp>
class Solution {
public:
	bool canJump(int A[], int n) {
		vector<int> unreachable(n);
		return jump(A,n,0,unreachable);
	}
	bool jump(int A[],int n,int i,vector<int>& unreachable){
		if (i>=n-1) return true;
		for (int step=A[i];step>0;--step){
			int j=i+step;
			if (j>=n-1)return true;
			else if (unreachable[j]|| !A[j])continue;
			else {
				if (jump(A,n,j,unreachable))return true;
			}
		}
		unreachable[i]=1;
		return false;
	}
};
int main(){
	Solution so;
	string line;
	while(getline(cin,line)){
		vector<int> A=string2vector<int>(line);
		cout<<boolalpha<<so.canJump(&A[0],A.size())<<endl;
	}
}

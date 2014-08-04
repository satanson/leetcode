#include<list_serialize.hpp>
class Solution {
public:
	bool canJump(int A[], int n) {
		int k=0;
		for(int i=0;i<=k;i++){
			if(k<n-1 && i==k && A[i]==0) return false;
			else if (i+A[i]<=k && k!=n-1)continue;
			else if (k<i+A[i] && i+A[i]<n-1)k=i+A[i];
			else if (i+A[i]>=n-1)return true;
			else continue;
		}
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

#include<list_serialize.hpp>
class Solution {
public:
	int maxSubArray(int A[], int n) {
		if (!n)return 0;
		int S=A[0],L=A[0];
		for (int i=1;i<n;i++){
			if (L<=0)
				L=A[i];
			else
				L+=A[i];
			S=std::max(S,L);
		}
		return S;
	}
};

int main(){
	Solution so;
	string line;
	while(getline(cin,line)){
		vector<int> A=string2vector<int>(line);
		cout<<so.maxSubArray(&A[0],A.size())<<endl;
	}
}

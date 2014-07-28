#include<cppstdlib.hpp>
class Solution{
public:
	void merge (int A[],int m,int B[],int n){
		vector<int> C(m+n);
		int i=0,j=0,k=0;
		while(i<m && j<n){
			if(A[i]<B[j])C[k++]=A[i++];
			else C[k++]=B[j++];
		}
		while(i<m)C[k++]=A[i++];
		while(j<n)C[k++]=B[j++];
		std::copy(C.begin(),C.end(),A);
	}
};
int main(){
	int A[100]={0};
	int B[100]={0};
	Solution so;
	int m=0,n=0;
	string line;
	while(getline(cin,line)){
		stringstream ss(line);
		int val;
		while(ss>>val)A[m++]=val;
		getline(cin,line);
		ss.str(line);
		ss.clear();
		while(ss>>val)B[n++]=val;

		so.merge(A,m,B,n);
		for (int i=0;i<m+n;i++)cout<<A[i]<<" ";
		cout<<endl<<string(10,'#')<<endl;
		m=0;
		n=0;
	}
}

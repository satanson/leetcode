#include<list_serialize.hpp>
class Solution {
public:
    int search(int A[], int n, int target) {
    	int pivot=findpivot(A,n,0,n); 
		if (pivot==-1){
			return binsearch(A,target,0,n);
		}else{
			int rc=binsearch(A,target,0,pivot);
			if (rc!=-1)return rc;
			else return binsearch(A,target,pivot,n);
		}
    }
	int findpivot(int A[],int n,int l,int h){
		if(h-l==1){
			//if(l==0 && A[l]>A[l+1])return l;
			//else if (l==n-1 && A[l]<A[l-1]) return l;
			//else if (l!=0 && l!=n-1 && (A[l-1] >A[l] || A[l]>A[l+1]))return l;
			//else return -1;
			if (l>0 && A[l-1]>A[l])return l;
			if (l<n-1 && A[l]>A[l+1]) return l+1;
			return -1;
		}
		int m=(l+h)/2;
		int rc=findpivot(A,n,l,m);
		if (rc!=-1)return rc;
		else return findpivot(A,n,m,h);
	}
	int binsearch(int A[],int x,int l,int h){
		if (h-l==1){
			return A[l]==x?l:-1;
		}
		int m=(h+l)/2;
		int rc=binsearch(A,x,l,m);
		if (rc!=-1)return rc;
		else return binsearch(A,x,m,h);
	}
};

int main(){
	Solution so;
	string line;
	while(getline(cin,line)){
		vector<int> A=string2vector(line);
		getline(cin,line);
		vector<int> xs=string2vector(line);
		for (int i=0;i<xs.size();i++){
			int j=so.search(&A[0],A.size(),xs[i]);
			cout<<j<<":"<<(j==-1?0:A[j])<<endl;
		}
	}
}

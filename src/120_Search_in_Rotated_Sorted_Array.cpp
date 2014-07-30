#include<list_serialize.hpp>
class Solution {
public:
    int search(int A[], int n, int target) {
    	int pivot=findpivot(A,n,0,n); 
		if (pivot==-1){
			return binsearch(A,target,0,n);
		}else{
			if (A[pivot]==target)return pivot;
			int rc=binsearch(A,target,0,pivot);
			if (rc!=-1)return rc;
			else return binsearch(A,target,pivot+1,n);
		}
    }
	int findpivot(int A[],int n,int l,int h){
		if (h-l==0) return -1;
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
		if (m>0 && A[m-1]>A[m]) return m;
		if (m<n-1 && A[m]>A[m+1]) return m+1;

		int rc=findpivot(A,n,l,m);
		if (rc!=-1)return rc;
		else return findpivot(A,n,m+1,h);
	}
	int binsearch(int A[],int x,int l,int h){
		if (h-l==0)return -1;
		if (h-l==1){
			return A[l]==x?l:-1;
		}
		int m=(h+l)/2;
		if (x==A[m]) return m;
		if (x<A[m])return binsearch(A,x,l,m);
		else return binsearch(A,x,m+1,h);
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

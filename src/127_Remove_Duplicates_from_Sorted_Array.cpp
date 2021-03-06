#include<list_serialize.hpp>
class Solution {
public:
    int removeDuplicates(int A[], int n) {
	   if (!n) return 0;
       int k=0,cnt=1; 
	   for (int i=1;i<n;++i){
		   if (A[i]!=A[k]){A[++k]=A[i];cnt=1;continue;}
		   if (A[i]==A[k]){
			   ++cnt;
			   if (cnt<=1) A[++k]=A[i];
		   }
	   }
	   return k+1;
    }
};

int main(){
	Solution so;
	string line;
	while(getline(cin,line)){
		vector<int> v=string2vector<int>(line);
		v.resize(so.removeDuplicates(&v[0],v.size()));
		cout<<vector2string<int>(v)<<endl;
	}
}

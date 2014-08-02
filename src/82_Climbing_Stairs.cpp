#include<cppstdlib.hpp>
class Solution {
public:
    int climbStairs(int n) {
		if (n==0 || n==1) return 1;
		int fib[2]={1,1};
		for (int i=2;i<=n;++i){
			int tmp=fib[1];
			fib[1]+=fib[0];
			fib[0]=tmp;
		}
		return fib[1];
    }
};
int main(){
	Solution so;
	int n=0;
	while(cin>>n){
		cout<<so.climbStairs(n)<<endl;
	}
}

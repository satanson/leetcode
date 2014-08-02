#include<cppstdlib.hpp>
class Solution {
public:
    int sqrt(int x) {
		double xn=1ll<<32,xn_1=0;
		do{
			xn_1=xn;
			xn=xn_1-(xn_1*xn_1-x)/(2*xn_1);
		}while((xn_1-xn)>1e-10);
		return (int)xn_1;
    }
};

int main(){
	Solution so;
	int n=0;
	while(cin>>n){
		cout<<so.sqrt(n)<<endl;
	}
}

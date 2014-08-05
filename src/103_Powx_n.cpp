#include<list_serialize.hpp>
class Solution {
public:
    double pow(double x, int n) {
		bool negative=false;
		if (n<0){
			negative=true;
			n*=-1;
		}
		double pow2[33]={1,x};
		double result=1;
		if (n&1) result=x;
		n>>=1;
		for(int i=2;i<33;i++){
			pow2[i]=pow2[i-1]*pow2[i-1];
			if (n&1)result*=pow2[i];
			n>>=1;
		}
		return negative?1/result:result;
    }
};

int main(){
	Solution so;
	string line;
	while(getline(cin,line)){
		vector<double> v=string2vector<double>(line);
		cout<<(int)so.pow(v[0],(int)v[1])<<endl;
	}
}

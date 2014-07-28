#include<cppstdlib.hpp>
class Solution{
public:
	int numDecodings(string s){
		if (s.size()==0)return 1;
		vector<int> a(s.size()+1);
		a[0]=1;a[1]=1;
		for (int i=2;i<a.size();i++){
			if(s[i-2]>'2' || s[i-2]=='2' && s[i-1]>'6'){
				a[i]=a[i-1];
			}else{
				a[i]=a[i-1]+a[i-2];
			}
		}
		return a[s.size()];
	}
};

int main(){
	Solution so;
	string line;
	while(getline(cin,line)){
		cout<<so.numDecodings(line)<<endl;
	}
}

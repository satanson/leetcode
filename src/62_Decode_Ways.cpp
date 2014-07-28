#include<cppstdlib.hpp>
class Solution{
public:
	int numDecodings(string s){
		if(s.size()==0)return 0;
		vector<int> a(s.size()+1);
		a[0]=1;
		if (s[0]=='0')a[1]=0;
		else a[1]=1;

		for (int i=2;i<a.size();i++){
			if(s[i-2]=='1' || s[i-2]=='2' && s[i-1]<='6'){
				a[i]+=a[i-2];
			}
			if (s[i-1]!='0'){
				a[i]+=a[i-1];
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

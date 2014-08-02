#include<cppstdlib.hpp>
class Solution {
public:
    string addBinary(string a, string b) {
		string rc;
		int carry=0;
		int i=a.size()-1,j=b.size()-1;
		while(i>=0 && j>=0){
			if(a[i]=='0' && b[j]=='0' && carry==0)rc.append(1,'0'),carry=0;
			else if(a[i]=='0' && b[j]=='1' && carry==0)rc.append(1,'1'),carry=0;
			else if(a[i]=='1' && b[j]=='0' && carry==0)rc.append(1,'1'),carry=0;
			else if(a[i]=='1' && b[j]=='1' && carry==0)rc.append(1,'0'),carry=1;
			else if(a[i]=='0' && b[j]=='0' && carry==1)rc.append(1,'1'),carry=0;
			else if(a[i]=='0' && b[j]=='1' && carry==1)rc.append(1,'0'),carry=1;
			else if(a[i]=='1' && b[j]=='0' && carry==1)rc.append(1,'0'),carry=1;
			else if(a[i]=='1' && b[j]=='1' && carry==1)rc.append(1,'1'),carry=1;
			else {}
			--i,--j;
		}
		if (i<0)std::swap(a,b),i=j;

		while(i>=0){
			if (a[i]=='0' && carry==0)rc.append(1,'0'),carry=0;
			else if (a[i]=='0' && carry==1)rc.append(1,'1'),carry=0;
			else if (a[i]=='1' && carry==0)rc.append(1,'1'),carry=0;
			else if (a[i]=='1' && carry==1)rc.append(1,'0'),carry=1;
			else {}
			--i;
		}
		if (carry)rc.append(1,'1');
		return string(rc.rbegin(),rc.rend());
    }
};

int main(){
	Solution so;
	string a,b;
	while(getline(cin,a)){
		getline(cin,b);
		cout<<so.addBinary(a,b)<<endl;
	}
}

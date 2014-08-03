#include<cppstdlib.hpp>
class Solution {
public:
    int lengthOfLastWord(const char *s) {
		const char* p=s+strlen(s)-1;
		int e=strlen(s);
		while(p>=s && isspace(*p)){--e;--p;}
		int b=e;
		while(p>=s && !isspace(*p)){--b;--p;}
		return e-b;
    }
};

int main(){
	Solution so;
	string line;
	while(getline(cin,line)){
		cout<<so.lengthOfLastWord(line.c_str())<<endl;
	}
}

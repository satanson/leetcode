#include<cppstdlib.hpp>
class Solution {
public:
    bool isPalindrome(string s) {
       if (s.size()<2) return true; 
	   int L=0,R=s.size()-1;
	   while(L<s.size() && R>=0 && L<R){
		   while(L<s.size() && !isalnum(s[L]))L++;
		   while(R>=0 && !isalnum(s[R]))R--;
		   //if (tolower(s[L++])!=tolower(s[R--]))return false;
		   if (L<s.size()&& R>=0 && L<R && tolower(s[L++])!=tolower(s[R--]))return false;
	   }
	   return true;
    }
};
int main(){
	string line;
	Solution so;
	while(getline(cin,line)){
		cout<<boolalpha<<so.isPalindrome(line)<<endl;
	}
}

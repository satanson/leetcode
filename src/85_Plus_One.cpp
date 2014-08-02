#include<list_serialize.hpp>
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
		if (digits.empty())return digits;
		int i=digits.size()-1;
		while(i>=0 && digits[i]==1)i--;
		for (int j=i+1;j<digits.size();j++)digits[j]=0;
		if (i>=0) digits[i]=1;
		return digits;
        
    }
};
int main(){
	Solution so;
	string line;
	while(getline(cin,line)){
		vector<int> digits=string2vector<int>(line);
		for (int i=0;i<(1<<digits.size());i++)
			cout<<vector2string<int>(so.plusOne(digits),"")<<endl;
	}
}

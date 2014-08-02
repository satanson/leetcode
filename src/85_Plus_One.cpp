#include<list_serialize.hpp>
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
		if (digits.empty())return digits;
		vector<int> digits2;
		int i=digits.size()-1;
		while(i>=0 && digits[i]==9)i--;

		if (i==-1){
			digits2.reserve(digits.size()+1);
			digits2.push_back(1);
		} else {
			digits2.reserve(digits.size());
			digits2.resize(i);
			std::copy(&digits[0],&digits[i],digits2.begin());
		   	digits2.push_back(digits[i]+1);
		}
		for (int j=i+1;j<digits.size();j++)digits2.push_back(0);
		return digits2;
        
    }
};
int main(){
	Solution so;
	string line;
	while(getline(cin,line)){
		vector<int> digits=string2vector<int>(line);
		for (int i=0;i<1000;++i){
			digits=so.plusOne(digits);
			cout<<vector2string<int>(digits,"")<<endl;
		}
	}
}

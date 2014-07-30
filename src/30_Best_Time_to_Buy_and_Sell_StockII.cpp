#include<cppstdlib.hpp>
#include<list_serialize.hpp>
class Solution {
public:
    int maxProfit(vector<int> &prices) {
		if (prices.size()<2)return 0;
		int crest,trough,profit=0;
		int i=0;
		while(i<prices.size()){
			while(i+1<prices.size() && prices[i]>=prices[i+1])i++;
			if (i+1==prices.size())return profit;
			else trough=prices[i];

			while(i+1<prices.size() && prices[i]<=prices[i+1])i++;
			crest=prices[i];

			profit+=crest-trough;
		}
		return crest;
    }
};
int main(){
	Solution so;
	string line;
	while(getline(cin,line)){
		vector<int> v=string2vector(line);
		cout<<so.maxProfit(v)<<endl;
	}
}



#include<cppstdlib.hpp>
#include<list_serialize.hpp>
class Solution {
public:
    int maxProfit(vector<int> &prices) {
		if (prices.size()<2)return 0;
		vector<int> till(prices.size()),since(prices.size());
		till.front()=0;
		int min_price=prices.front();
		for (int i=1;i<till.size();i++){
			int profit=prices[i]-min_price;
			till[i]=profit>till[i-1]?profit:till[i-1];
			if(prices[i]<min_price)min_price=prices[i];
		}
		since.back()=0;
		int max_price=prices.back();
		for (int i=since.size()-2;i>=0;i--){
			int profit=max_price-prices[i];
			since[i]=profit>since[i+1]?profit:since[i+1];
			if (prices[i]>max_price)max_price=prices[i];
		}

		int max_profit=0;
		for (int i=0;i<prices.size();i++){
			int profit=till[i]+since[i];
			if (profit>max_profit)max_profit=profit;
		}
		return max_profit;
    }
};
int main(){
	Solution so;
	string line;
	while(getline(cin,line)){
		vector<int> v=string2vector<int>(line);
		cout<<so.maxProfit(v)<<endl;
	}
}


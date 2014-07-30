#include<list_serialize.hpp>
class Solution {
public:
    int maxProfit(vector<int> &prices) {
		if(prices.size()<2)return 0;
		int pmax,pmin;
		return dq_maxProfit(prices,0,prices.size(),pmax,pmin);
    }
	int dq_maxProfit(vector<int>&prices,int l,int r,int& pmax,int& pmin){
		if (r-l==2){
			if (prices[l]<prices[l+1]){
				pmin=prices[l];
				pmax=prices[l+1];
			} else{
				pmin=prices[l+1];
				pmax=prices[l];
			}
			return prices[l+1]-prices[l];
		}
		if (r-l==3){
			pmax=*std::max_element(&prices[l],&prices[r]);
			pmin=*std::min_element(&prices[l],&prices[r]);
			int p[3]={prices[l+1]-prices[l],prices[l+2]-prices[l],prices[l+2]-prices[l+1]};
			return *std::max_element(p,p+3);
		}
		int m=(r+l)/2,lpmax,lpmin,rpmax,rpmin;
		int lmaxprofit=dq_maxProfit(prices,l,m,lpmax,lpmin);
		int rmaxprofit=dq_maxProfit(prices,m,r,rpmax,rpmin);
		pmax=lpmax>rpmax?lpmax:rpmax;
		pmin=lpmin<rpmin?lpmin:rpmin;
		int maxprofit=rpmax-lpmin;
		if (maxprofit>lmaxprofit && maxprofit>rmaxprofit)return maxprofit;
		else return lmaxprofit>rmaxprofit?lmaxprofit:rmaxprofit;
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

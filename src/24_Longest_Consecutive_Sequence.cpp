#include<cppstdlib.hpp>
class Solution {
public:
    int longestConsecutive(vector<int> &num){
		unordered_set<int> s;
		for(int i=0;i<num.size();i++)s.insert(num[i]);
		int max=0;
		for(int i=0;i<num.size();i++){
			int n=num[i];
			int count=1;
			if(s.count(n)){
				int prev=n-1;
				s.erase(n);
				while(s.count(prev)){
					count++;
					s.erase(prev);
					prev--;
				}
				int next=n+1;
				while(s.count(next)){
					count++;
					s.erase(next);
					next++;
				}
			}
			max=count>max?count:max;
		}
		return max;
	}
};
int main()
{
	string line;
	Solution so;
	while(getline(cin,line)){
		stringstream ss(line);
		int i;
		vector<int> nums;
		while(ss>>i)nums.push_back(i);
		cout<<so.longestConsecutive(nums)<<endl;
	}
}

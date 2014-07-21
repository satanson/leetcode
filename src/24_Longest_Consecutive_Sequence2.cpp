#include<cppstdlib.hpp>
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
		if (num.size()<2)return num.size();
		list<int> best,candidate;
		candidate.push_back(num[0]);
		for(int i=1;i<num.size();i++){
			if (candidate.size()==0){
				candidate.push_back(num[i]);
			}else if (candidate.back()+1==num[i]){
				candidate.push_back(num[i]);
			}else if (candidate.size()>=best.size()){
				std::swap(candidate,best);
				candidate.clear();
				candidate.push_back(num[i]);
			}else{
				candidate.clear();
				candidate.push_back(num[i]);
			}
		}
		return best.size();
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

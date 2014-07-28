#include<cppstdlib.hpp>
class Solution{
public:
	vector<int> greyCode(int n){
		if (n<1)return vector<int>();
		vector<int> v;
		v.push_back(0);
		v.push_back(1);
		for (int i=1;i<n;i++){
			int m=1<<i;
			for( int j=m-1;j>=0;j--){
				v.push_back(m+v[j]);
			}
		}
		return v;
	}
};

int main(){
	Solution so;
	int n;
	while(cin>>n){
		vector<int> v=so.greyCode(n);
		for (int i=0;i<v.size();i++)cout<<v[i]<<endl;
		cout<<string(10,'#')<<endl;
	}
}

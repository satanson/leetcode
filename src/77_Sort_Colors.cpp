#include<cppstdlib.hpp>
#include<list_serialize.hpp>
class Solution {
public:
    void sortColors(int A[], int n) {
		int colors[3]={0};
		int i=0;
		for (i=0;i<n;i++)colors[A[i]]++;
		int k=0;
		int *p=A;
		for (i=0;i<3;i++){
			std::fill(p,p+colors[i],i);
			p+=colors[i];
		}
    }
};
int main(){
	Solution so;
	string line;
	while(getline(cin,line)){
		vector<int> array=string2vector<int>(line);
		so.sortColors(&array[0],array.size());
		cout<<vector2string<int>(array)<<endl;
	}
}

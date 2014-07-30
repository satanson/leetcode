#include<cppstdlib.hpp>
void print(vector<string> v){
	cout<<"[";
	if (v.size()!=0)cout<<v[0];
	for (int i=1;i<v.size();i++) cout<<","<<v[i];
	cout<<"}"<<endl;
}
int main(){
	vector<string> v0;
	v0.push_back("hello");
	v0.push_back("world");
	v0.push_back("ranpanf");
	print(v0);
	vector<string> v1(v0.rbegin(),v0.rend());
	print(v1);
}

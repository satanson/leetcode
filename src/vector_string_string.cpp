#include<cppstdlib.hpp>
#include<list_serialize.hpp>
int main(){
	string line;
	while(getline(cin,line)){
		cout<<vector2string<string>(string2vector<string>(line),"\n")<<endl;
	}
}

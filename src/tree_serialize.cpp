#include<cppstdlib.hpp>
#include<tree_serialize.hpp>

int main(){
	string line;
	while(getline(cin,line)){
		cout<<tree2string(string2tree(line))<<endl;
	}
	return 0;
}


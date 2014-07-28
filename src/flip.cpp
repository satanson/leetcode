#include<cppstdlib.hpp>
int main(){
	string line;
	while(getline(cin,line)){
		stringstream ss(line);
		int i=0,j=0;
		ss>>i>>j;
		bool flip=true;
		int count=1;
		int x=(i+j)/2;
		while(i<=x && x<j){
			cout<<x<<" ";
			if(flip) x-=count;else x+=count;
			++count;
			flip=!flip;
		}
		cout<<endl;
	}
}

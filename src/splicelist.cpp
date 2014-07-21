#include<cppstdlib.hpp>
class A{
public:
	int a;
	A(int aa):a(aa){cout<<"construct "<<a<<endl;}
	~A(){cout<<"destruct "<<a<<endl;}
};
int main(){
	list<A> L1,L2;
	L1.push_back(0);
	L1.push_back(1);
	L1.push_back(2);
	L2.push_back(3);
	L2.push_back(4);
	L2.push_back(5);
	L2.push_back(6);
	cout<<"#########################"<<endl;
	cout<<"L1:"<<L1.size()<<endl;
	cout<<"L2:"<<L2.size()<<endl;
	cout<<"before splice"<<endl;
	L1.splice(L1.end(),L2);
	cout<<"L1:"<<L1.size()<<endl;
	cout<<"L2:"<<L2.size()<<endl;
	cout<<"#########################"<<endl;
}

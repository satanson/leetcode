#include<cppstdlib.hpp>
int main(){
	vector<int> L={3,45,2342,2};
	cout<<std::min_element(&L[0],&L[L.size()]);
}

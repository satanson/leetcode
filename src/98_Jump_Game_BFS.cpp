#include<list_serialize.hpp>
class Solution {
public:
	bool canJump(int A[], int n) {
		list<int> q1,q2;
		unordered_set<int> mark;
		q1.push_back(0);
		mark.insert(0);
		while(!q1.empty()){
			while(!q1.empty()){
				int pos=q1.front();q1.pop_front();
				for(int i=1;i<=A[pos];i++){
					int pos2=pos+i;
					if(mark.count(pos2)!=0){
						continue;
					}else if (pos2>=n-1){
						return true;
					}else if (A[pos2]!=0){	
						q2.push_back(pos2);
						mark.insert(pos2);
					}else{
						//pos2<n && A[pos2]==0 && mark.count(pos2)==0
					}
				}
			}
			std::swap(q1,q2);
		}
		return false;
	}
};
int main(){
	Solution so;
	string line;
	while(getline(cin,line)){
		vector<int> A=string2vector<int>(line);
		cout<<boolalpha<<so.canJump(&A[0],A.size())<<endl;
	}
}

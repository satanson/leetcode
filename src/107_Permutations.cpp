#include<list_serialize.hpp>
class Solution {
public:
        vector<vector<int>> permute(vector<int> &num) {
                int N=num.size();
                vector<int> invseq(N,0);
                vector<vector<int>> seqs;
                list<int> L(num.begin(),num.end());
                while(true){
                        seqs.push_back(perm(invseq,L));
                        int j=num.size()-1;
                        while(j>=0 && invseq[j]==N-1-j)--j;
                        if (j==-1)break;
                        else{
                                ++invseq[j];
                                while(++j<N)invseq[j]=0;
                        }
                }
                return seqs;
        }
        vector<int> perm(vector<int> seq,list<int> L){
                vector<int> p;
                p.reserve(seq.size());
                for(int i=0;i<seq.size();i++){
                        int j=seq[i];
                        auto it=L.begin();
                        while(j>0){++it;--j;}
                        p.push_back(*it);
                        L.erase(it);
                }
                return p;
        }

};
int main(){
	Solution so;
	string line;
	while(getline(cin,line)){
		vector<int> num=string2vector<int>(line);
		vector<vector<int>> perms=so.permute(num);
		for(int i=0;i<perms.size();i++)cout<<vector2string<int>(perms[i])<<endl;
	}
}

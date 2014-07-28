#include<cppstdlib.hpp>
class Solution {
public:
       vector<string> restoreIpAddresses(string s){
                int N=s.size();
                list<list<uint8_t>> q1,q2,q;
                q1.push_back(list<uint8_t>());
                q1.back().push_back(0);
                while(!q1.empty()){
                        while(!q1.empty()){
                                list<uint8_t> path;
                                std::swap(q1.back(),path);
                                q1.pop_back();
                                uint8_t i=path.back();
                                if (path.size()==5){
                                        if (i==N){
                                                q.push_back(list<uint8_t>());
                                                std::swap(q.back(),path);
                                        }
                                        continue;
                                }
                                for(int j=i+1;j<=i+3 && j<=N;j++){
                                        if(j==i+3 && s.substr(i,j-i)>"255")continue;
                                        if(j>=i+2 && s[i]=='0') continue;
                                        q2.push_back(path);
                                        q2.back().push_back(j);
                                }
                        }
                        std::swap(q1,q2);
                }
                vector<string> v;
                while(!q.empty()){
                        //list<uint8_t>&path=q.back();
                        list<uint8_t> path;
                        std::swap(q.back(),path);
                        q.pop_back();
                        int i=path.front();path.pop_front();
                        int j=path.front();path.pop_front();
                        v.push_back(s.substr(i,j-i));
                        while(!path.empty()){
                                i=j;
                                j=path.front();path.pop_front();
                                v.back()+=".";
                                v.back()+=s.substr(i,j-i);
                        }
                }
                return v;
        }

};

int main(){
	Solution so;
	string line;
	while(getline(cin,line)){
		vector<string> v=so.restoreIpAddresses(line);
		for (int i=0;i<v.size();i++)cout<<v[i]<<endl;
		cout<<string(10,'#')<<endl;
	}
}

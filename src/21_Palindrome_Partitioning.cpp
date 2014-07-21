#include<cppstdlib.hpp>
class Solution{
public:
        vector<vector<string>> partition(string s){
                size_t N=s.size()+1;
                vector<vector<bool>> d(N,vector<bool>(N,false));
                for (int i=0;i<N-1;i++){
                        d[i][i]=true;
                        d[i][i+1]=true;
//cout<<"###d["<<i<<","<<i<<"]="<<d[i][i]<<endl;
//cout<<"###d["<<i<<","<<i+1<<"]="<<d[i][i+1]<<endl;
                }
                for (int L=2;L<N;L++){
                        for (int i=0;i+L<N;i++){
                                int j=i+L;
                                if(s[i]==s[j-1] && d[i+1][j-1]==true)d[i][j]=true;
                                else d[i][j]=false;
//cout<<"###d["<<i<<","<<j<<"]="<<d[i][j]<<endl;
                        }
                }
                list<list<int>> partialpaths,partialpaths2;
                list<list<int>> fullpaths;
                partialpaths.push_back(list<int>());
                partialpaths.back().push_back(0);

                while(!partialpaths.empty()){
                        while(!partialpaths.empty()){
                                list<int> path;
                                std::swap(path,partialpaths.back());
                                partialpaths.pop_back();
                                int a=path.back();
                                if (a==N-1){
                                        fullpaths.push_back(path);
                                }else{
                                        for (int b=a+1;b<N;b++){
                                                if (d[a][b]){
                                                        //cout<<"d["<<a<<","<<b<<"]="<<d[a][b]<<endl;
                                                        partialpaths2.push_back(path);
                                                        partialpaths2.back().push_back(b);
                                                }
                                        }
                                }
                        }
                        std::swap(partialpaths,partialpaths2);
                }
                vector<vector<string>> vs;
                while(!fullpaths.empty()){
                        list<int> path;
                        std::swap(path,fullpaths.front());
                        fullpaths.pop_front();
                        int a=path.front();
                        path.pop_front();
                        vs.push_back(vector<string>());
                        while(!path.empty()){
                                int b=path.front();
                                path.pop_front();
                                vs.back().push_back(s.substr(a,b-a));
                                a=b;
                        }
                }
                return vs;
        }
};

int main(int argc,char**argv)
{
        string s;
        while(getline(cin,s)){
                cout<<s<<endl;
                Solution solve;
                vector<vector<string>> vs=solve.partition(s);
                for (int i=0;i<vs.size();i++){
                        vector<string>& tokens=vs[i];
                        cout<<"[ ";
                        for( int j=0;j<tokens.size();j++){
                                cout<<tokens[j]<<",";
                        }
                        cout<<" ]"<<endl;
                }
        }
        return 0;
}

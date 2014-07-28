#include<cppstdlib.hpp>
class Solution {
public:
    bool isInterleave(string s1,string s2,string s3){
                int N1=s1.size(),N2=s2.size(),N3=s3.size();
                if (N1+N2!=N3)return false;
                vector<vector<bool>> d(N1+1,vector<bool>(N2+1,false));
                int n1=1,n2=1;
                while(n1<=N1 && s1[n1-1]==s3[n1-1])d[n1++][0]=true;
                while(n2<=N2 && s2[n2-1]==s3[n2-1])d[0][n2++]=true;
                d[0][0]=true;
                for (n1=1;n1<=N1;n1++){
                        for (n2=1;n2<=N2;n2++){
                                if (s1[n1-1]!=s2[n2-1]){
                                        if (s1[n1-1]==s3[n1+n2-1])d[n1][n2]=d[n1-1][n2];
                                        else if (s2[n2-1]==s3[n1+n2-1])d[n1][n2]=d[n1][n2-1];
                                        else d[n1][n2]=false;
                                }else{
                                        if (s1[n1-1]==s3[n1+n2-1])d[n1][n2]=d[n1-1][n2]||d[n1][n2-1];
                                        else d[n1][n2]=false;
                                }
                        }
                }
                return d[N1][N2];
        }

};
int main(){
	Solution so;
	string s1,s2,s;
	while(getline(cin,s1)){
		getline(cin,s2);
		getline(cin,s);
		cout<<boolalpha<<so.isInterleave(s1,s2,s)<<endl;
	}
}

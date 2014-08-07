#include<cppstdlib.hpp>
class Solution {
public:
    char *strStr(char *haystack, char *needle) {
		if(!needle)return NULL;
		if(strlen(needle)==1){
			char *p=haystack;
			while(*p!=0 && *p!=*needle)++p;
			return *p!=0?p:NULL;
		}
		int M=strlen(haystack),N=strlen(needle);
		vector<int> kmp_table(N);
		create_kmp_table(&kmp_table[0],N,needle);
		
		int p=0,i=0;
		while(p+i<M){
			if(needle[i]==haystack[p+i]){
				if (i==N-1)
					return haystack+p;
				else
					++i;
			}else if (kmp_table[i]>-1){
				p=p+i-kmp_table[i];
				i=kmp_table[i];
			}else{
				p=p+1;
				i=0;
			}
		}
		return NULL;
    }
	void create_kmp_table(int kmp_table[],int n,char *needle){
		kmp_table[0]=-1;
		kmp_table[1]=0;
		int pos=2,cand=0;
		while(pos<n){
			if(needle[pos-1]==needle[cand]){
				++cand;
				kmp_table[pos]=cand;
				++pos;
			}else if (cand>0){
				cand=kmp_table[cand];
			}else {
				kmp_table[pos]=0;
				++pos;
			}
		}
	}
};

int main(){
	Solution so;
	string haystack,needle;
	while(getline(cin,haystack)){
		getline(cin,needle);
		cout<<string(10,'#')<<endl;
		char *p=(so.strStr((char*)haystack.c_str(),(char*)needle.c_str()));
		cout<<string(p)<<endl;
		cout<<string(10,'#')<<endl;
	}
}

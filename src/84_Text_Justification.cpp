#include<cppstdlib.hpp>
#include<list_serialize.hpp>
class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
		vector<string> justified;
		if (words.empty())return justified;
		string line(L,' ');
		int len=0,wc=0,bol=0,eol=0;
		for (eol=0;eol<words.size();++eol){
			if (len==0){
			//first words of the line	
				len+=words[eol].size();
				wc=1;
			}else{
			//rest words of the line
				if (len+1+words[eol].size()<=L){
					++wc;
					len+=1+words[eol].size();
				}else{
					int spaces=L-(len-wc+1);
					int sp=0,n=0;
					if (wc>1){
						sp=spaces/(wc-1);
						n=spaces%(wc-1);
					}
					std::copy(words[bol].begin(),words[bol].end(),&line[0]);
					
					int k=words[bol].size();
					for (int i=bol+1;i<=bol+n;i++){
						std::copy(words[i].begin(),words[i].end(),&line[k+sp+1]);
						k+=sp+1+words[i].size();
					}
					for (int i=bol+n+1;i<eol;i++){
						std::copy(words[i].begin(),words[i].end(),&line[k+sp]);
						k+=sp+words[i].size();
					}
					justified.push_back(line);
					std::fill(line.begin(),line.end(),' ');
					bol=eol;
					wc=1;
					len=words[eol].size();
				}

			}
		}
		std::copy(words[bol].begin(),words[bol].end(),&line[0]);
		int k=words[bol].size();
		for (int i=bol+1;i<eol;i++){
			std::copy(words[i].begin(),words[i].end(),&line[k+1]);
			k+=1+words[i].size();
		}
		justified.push_back(line);
		return justified;
    }
};

int main(){
	Solution so;
	string line;
	while(getline(cin,line)){
		vector<string> words=string2vector<string>(line);
		getline(cin,line);
		vector<int> L=string2vector<int>(line);
		for (int i=0;i<L.size();i++)
			cout<<vector2string<string>(so.fullJustify(words,L[i]),"\n")<<endl;
	}
}

#include<cppstdlib.hpp>
class Solution {
public:
    string simplifyPath(string path){
		if(path.size()==0)return "";
		list<string> pcomps;
		size_t b=0,e=string::npos;
		path+='/';
		while((e=path.find('/',b))!=string::npos){
			if (e==0){
				/* /=>/ */
				pcomps.push_back("/");
			}else if (b<e){
				string comp=path.substr(b,e-b);
				if (comp=="."){
					/* /a/b/./=>/a/b */
				} else if (comp==".."){
					if (pcomps.empty()){
						/* ../=> ../ */
						pcomps.push_back("..");
					} else if (pcomps.back()!="/" && pcomps.back()!=".."){
						/* /a/b/../=>/a/ */
						pcomps.pop_back();
						if (pcomps.empty())pcomps.push_back("/");
					} else {
						/* /../=>/ */
					}
				} else {
					pcomps.push_back(comp);
				}
			}else {
				/* b==e  duplicate / */
			}
			if (e+1==path.size()){
				/* last / */
				break;
			}else{
				b=e+1;
			}
		}
		if (e==string::npos) pcomps.push_back(path.substr(b));
		string simplepath;
		string prefix="";
		if (!pcomps.empty() && pcomps.front()=="/"){prefix="/";pcomps.pop_front();}
		while(!pcomps.empty()){
			simplepath+=pcomps.front()+'/';
			pcomps.pop_front();
		}
		simplepath=prefix+simplepath;
		if (simplepath!="/" && simplepath[simplepath.size()-1]=='/')simplepath.resize(simplepath.size()-1);
		return simplepath;
	}
};

int main(){
	Solution so;
	string path;
	while(getline(cin,path)){
		cout<<so.simplifyPath(path)<<endl;
	}
}

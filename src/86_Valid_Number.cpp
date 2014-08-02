#include<cppstdlib.hpp>
#include<list_serialize.hpp>
class Solution {
public:
    bool isNumber(const char *s) {
		if (s&&isspace(*s))s++;
		if (!s)return false;
		string a(s);
		while(isspace(*a.rbegin()))a.resize(a.size()-1);
		s=a.c_str();
		const char *p=s;
		//if (*p=='0'){
		//	++p;
		//	if (!*p)
		//		return true;
		//	else if (*p=='x'){
		//		return handle_hex(++p);
		//	}else if ('1'<=*p && *p<='7'){
		//		return handle_oct(++p);
		//	}else if (*p=='.'){
		//		return handle_float(++p);
		//	}else{
		//		return handle_dec(p);
		//	}
		//}else if ( '1'<=*p && *p<='9'){
		if (*p=='-' || *p=='+') ++p;
		if ( '0'<=*p && *p<='9'){
			return handle_dec(++p);
		}else if (*p=='.'){
			++p;
			if (!*p)return false;
			else return handle_float(p);
		}else{
			return false;
		}
    }
	const char* eat_octdigit(const char *p){
		while(*p && '0'<=*p && *p<='7')++p;
		return p;
	}
	const char* eat_decdigit(const char *p){
		while(*p && isdigit(*p))++p;
		return p;
	}
	const char* eat_hexdigit(const char *p){
		while(*p && isxdigit(*p))++p;
		return p;
	}
	bool handle_dec(const char *p){
		p=eat_decdigit(p);
		if (!*p)return true;
		else if (*p=='.')return handle_float(++p);
		else if (*p=='e' || *p=='E')return handle_sicentific(++p);
		else return false;
	}
	bool handle_int(const char *p){
		return !*eat_decdigit(p);
	}
	bool handle_sicentific(const char* p){
		if (!*p)return false;
		return handle_int(p);
	}
	bool handle_float(const char *p){
		if(!*p)return true;
		else if (isdigit(*p)){
			if (*p=='e' || *p=='E')return handle_sicentific(++p);
			else return handle_int(++p);
		} else 
			return false;
	}
	bool handle_hex(const char *p){
		return !*eat_hexdigit(p);
	}
	bool handle_oct(const char *p){
		return !*eat_octdigit(p);
	}
};

int main(){
	Solution so;
	string line;
	while(getline(cin,line)){
		vector<string> numbers=string2vector<string>(line);
		for (int i=0;i<numbers.size();i++){
			cout<<boolalpha<<so.isNumber(numbers[i].c_str())<<endl;
		}
	}
}

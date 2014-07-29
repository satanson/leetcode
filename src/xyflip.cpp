#include<cppstdlib.hpp>
int main(){

	string line;
	while(getline(cin,line)){
		stringstream ss(line);
		int left=0,right=0,top=0,bottom=0;
		ss>>left>>right>>top>>bottom;
		bool xflip=true,yflip=true;
		int x=(left+right)/2,y=(top+bottom)/2;
		int xcount=1,ycount=1;
		while(left<=x && x<right){
			yflip=true;
			y=(top+bottom)/2;
			ycount=1;
			while(top<=y && y<bottom){ 
				cout<<"x="<<x<<","<<"y="<<y<<endl;
				if (yflip)y-=ycount;else y+=ycount;
				++ycount;
				yflip=!yflip;
			}
			if (xflip) x-=xcount; else x+=xcount;
			++xcount;
			xflip=!xflip;
		}
	}
}

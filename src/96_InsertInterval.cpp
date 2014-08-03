#include<list_serialize.hpp>
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
		vector<Interval> v; 
		int b=0;
		while(b<intervals.size() && intervals[b].end<newInterval.start)++b;
		int e=intervals.size()-1;
		while(e>=0 && intervals[e].start>newInterval.end)--e;

		cout<<"b="<<b<<endl;
		cout<<"e="<<e<<endl;
		for(int i=0;i<b;i++)v.push_back(intervals[i]);
		
		int start=0,end=0;
		if (b<intervals.size())
			start=std::min(intervals[b].start,newInterval.start);
		else 
			start=newInterval.start;

		if (e>=0)
			end=std::max(intervals[e].end,newInterval.end);
		else
			end=newInterval.end;
		v.push_back(Interval(start,end));

		for(int i=e+1;i<intervals.size();i++)v.push_back(intervals[i]);
		return v;
	}
};
int main(){
	Solution so;
	string line;
	while(getline(cin,line)){
		vector<Interval> intervals=string2vector<Interval>(line);
		getline(cin,line);
		vector<Interval> newIntervals=string2vector<Interval>(line);
		cout<<vector2string<Interval>(so.insert(intervals,newIntervals[0]),"\n")<<endl;
	}
}

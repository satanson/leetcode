#include<list_serialize.hpp>
class Solution {
public:
	struct NQueue{
		NQueue(int n):N(n),board(n,vector<int>(n)),solves(0){}
		
		void solve(){
			for(int i=0;i<N;i++)stroll(0,i);
		}
		void stroll(int r,int c){
			if(r==N-1)++solves;
			else{
				mark(r,c,1);
				for(int i=0;i<N;i++){
					if(!board[r+1][i])stroll(r+1,i);
				}
				mark(r,c,0);
			}
		}

		void mark(int r,int c,bool flag){
			int k=flag?1:-1;
			//row
			for (int i=r+1;i!=r;i=(i+1)%N)board[i][c]+=k;
			//col
			for (int i=c+1;i!=c;i=(i+1)%N)board[r][i]+=k;
			//slash
			for (int i=0;i<board.size();i++){
				int j=i+c-r;
				if(i==r)
					continue;
				else if(0<=j && j<board.size())
					board[i][j]+=k;
			}
			//bachslash
			for (int i=0;i<board.size();i++){
				int j=r+c-i;
				if(i==r)
					continue;
				else if (0<=j && j<board.size())
					board[i][j]+=k;
			}
		}

		int N;
		vector<vector<int>> board;
		vector<int> stk;	
		int solves;
	};
	int  totalNQueens(int n) {
		NQueue nqueue_problem(n);
		nqueue_problem.solve();
		return nqueue_problem.solves;
	}
};

int main(){
	Solution so;
	string line;
	while(getline(cin,line)){
		vector<int> N=string2vector<int>(line);
		cout<<so.totalNQueens(N[0])<<endl;
	}
}

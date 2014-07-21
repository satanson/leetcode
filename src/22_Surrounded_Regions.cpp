#include<cppstdlib.hpp>
typedef vector<vector<char>> BOARD;
typedef pair<int,int> XY;
class Solution {

public:
    void solve(BOARD &board) {
		if (board.size()==0)return;
		wanderEast(board);
		wanderSouth(board);
		wanderWest(board);
		wanderNorth(board);
		for (int i=0;i<board.size();i++)
			for(int j=0;j<board[i].size();j++){
				char& cell=board[i][j];
				switch(cell){
					case 'X':
						break;
					case 'O':
						cell='X';
						break;
					case 'o':
						cell='O';
						break;
					default:
						cerr<<"never reach here";
						break;
				}
			}
    }
	void wanderEast(BOARD &board){
		int rows=board.size();
		int col=board[0].size()-1;
		for (int row=0;row<rows;row++)
			if(board[row][col]=='O')traverse(board,row,col);
	}
	void wanderSouth(BOARD &board){
		int row=board.size()-1;
		int cols=board[0].size();
		for (int col=0;col<cols;col++)
			if(board[row][col]=='O')traverse(board,row,col);
	}
	void wanderWest(BOARD &board){
		int rows=board.size();
		int col=0;
		for (int row=0;row<rows;row++)
			if(board[row][col]=='O')traverse(board,row,col);
	}
	void wanderNorth(BOARD &board){
		int row=0;
		int cols=board[0].size();
		for (int col=0;col<cols;col++)
			if(board[row][col]=='O')traverse(board,row,col);
	}
	void traverse(BOARD &board,int row,int col){
		int rows=board.size();
		int cols=board[0].size();
		list<XY> q;
		set<XY> marks;
		q.push_back(XY(row,col));
		marks.insert(XY(row,col));
		while(!q.empty()){
			XY xy=q.front();
			q.pop_front();
			board[xy.first][xy.second]='o';
			//east 
			col=xy.second+1;
			if (col<cols && board[xy.first][col]=='O' && !marks.count(XY(xy.first,col))){
				q.push_back(XY(xy.first,col));
				marks.insert(XY(xy.first,col));
			}
			//south
			row=xy.first+1;
			if (row<rows && board[row][xy.second]=='O'&& !marks.count(XY(row,xy.second))){
				q.push_back(XY(row,xy.second));
				marks.insert(XY(row,xy.second));
			}
			//west
			col=xy.second-1;
			if (col>=0 && board[xy.first][col]=='O' && !marks.count(XY(xy.first,col))){
				q.push_back(XY(xy.first,col));
				marks.insert(XY(xy.first,col));
			}
			//north
			row=xy.first-1;
			if (row>=0 && board[row][xy.second]=='O' && !marks.count(XY(row,xy.second))){
				q.push_back(XY(row,xy.second));
				marks.insert(XY(row,xy.second));
			}
		}
	}
};
void print(BOARD& board){
	cout<<"################################"<<endl;
	for(int i=0;i<board.size();i++){
		for(int j=0;j<board[i].size();j++){
			cout<<board[i][j];
		}
		cout<<endl;
	}
	cout<<"################################"<<endl;
}
int main(int argc,char**argv){
	string line;
	BOARD board;
	while(getline(cin,line)){
		board.push_back(vector<char>(line.begin(),line.end()));	
	}
	print(board);
	Solution s;
	s.solve(board);
	print(board);

}

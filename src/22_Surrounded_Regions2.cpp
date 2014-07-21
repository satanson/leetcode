#include<cppstdlib.hpp>
typedef vector<vector<char>> BOARD;
typedef pair<int,int> XY;
class Solution {
public:
       
       void solve(vector<vector<char>> &board) {
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
        void wanderEast(vector<vector<char>> &board){
                int rows=board.size();
                int col=board[0].size()-1;
                for (int row=0;row<rows;row++)
                        if(board[row][col]=='O')traverse(board,row,col);
        }
        void wanderSouth(vector<vector<char>> &board){
                int row=board.size()-1;
                int cols=board[0].size();
                for (int col=0;col<cols;col++)
                        if(board[row][col]=='O')traverse(board,row,col);
        }
        void wanderWest(vector<vector<char>> &board){
                int rows=board.size();
                int col=0;
                for (int row=0;row<rows;row++)
                        if(board[row][col]=='O')traverse(board,row,col);
        }
        void wanderNorth(vector<vector<char>> &board){
                int row=0;
                int cols=board[0].size();
                for (int col=0;col<cols;col++)
                        if(board[row][col]=='O')traverse(board,row,col);
        }
        void traverse(vector<vector<char>> &board,int row,int col){
                int rows=board.size();
                int cols=board[0].size();
                list<pair<int,int>> q;
                q.push_back(pair<int,int>(row,col));
                board[row][col]='o';
                while(!q.empty()){
                        pair<int,int> xy=q.front();
                        q.pop_front();
                        //east
                        col=xy.second+1;
                        if (col<cols && board[xy.first][col]=='O'){
                                q.push_back(pair<int,int>(xy.first,col));
                                board[xy.first][col]='o';
                        }
                        //south
                        row=xy.first+1;
                        if (row<rows && board[row][xy.second]=='O'){
                                q.push_back(pair<int,int>(row,xy.second));
                                board[row][xy.second]='o';
                        }
                        //west
                        col=xy.second-1;
                        if (col>=0 && board[xy.first][col]=='O'){
                                q.push_back(pair<int,int>(xy.first,col));
                                board[xy.first][col]='o';
                        }
                        //north
                        row=xy.first-1;
                        if (row>=0 && board[row][xy.second]=='O'){
                                q.push_back(pair<int,int>(row,xy.second));
                                board[row][xy.second]='o';
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

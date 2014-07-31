#include<cppstdlib.hpp>
class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
		if (board.size()==0||board[0].size()==0)return false;
		if (word.size()==0)return true;
		unordered_set<int> mark;
		int M=board.size(),N=board[0].size();
		for (int i=0;i<M;i++){
			for (int j=0;j<N;j++){
				if(board[i][j]!=word[0])continue;
				mark.clear();
				if (search(board,i,j,word,0,mark)) return true;
			}
		}
		return false;
	
    }
	bool search(vector<vector<char>>&board, int i,int j, string& word, int k, unordered_set<int>& mark){
		int M=board.size(),N=board[0].size();
		if (k==word.size()-1){
			return board[i][j]==word[k] && mark.count(i*N+j)==0 ? true:false;
		}

		mark.insert(i*N+j);
		//walk top
		if (i-1>=0){
			if (walk_through(board,i-1,j,word,k+1,mark))return true;
		}
		//walk bottom
		if (i+1<M){
			if (walk_through(board,i+1,j,word,k+1,mark))return true;
		}
		//walk left
		if (j-1>=0){
			if (walk_through(board,i,j-1,word,k+1,mark))return true;
		}
		//walk right
		if (j+1<N){
			if (walk_through(board,i,j+1,word,k+1,mark))return true;
		}
		mark.erase(i*N+j);
		return false;
	}
	bool walk_through(vector<vector<char>>&board,int i,int j,string& word,int k,unordered_set<int>& mark){
		int M=board.size(),N=board[0].size();
		if (board[i][j]!=word[k])return false;
		if (mark.count(i*N+j)!=0)return false;
		if (!search(board,i,j,word,k,mark))return false;
		return true;
	}
};

int main(){
	Solution so;
	string line,word;
	vector<vector<char>> board;
	getline(cin,word);
	while(getline(cin,line)){
		board.push_back(vector<char>(line.begin(),line.end()));
	}
	cout<<boolalpha<<so.exist(board,word)<<endl;
}

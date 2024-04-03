class Solution {
public:
    bool func(int row, int col, vector<vector<char>>& board,string &word, vector<vector<int>> &visited, int n, int m,int i){
        if(i == word.size()) {
            return true;
        }
        
        if(row+1 < n && visited[row+1][col] == 0 && i < word.size() && board[row+1][col] == word[i]){
            visited[row+1][col] = 1;
            bool falg = func(row+1,col,board,word,visited,n,m,i+1);
            if(falg == true){
                return true;
            }
            visited[row+1][col] = 0;
        }

        if(row-1 >=0 && visited[row-1][col] == 0 && i < word.size() && board[row-1][col] == word[i]){
            visited[row-1][col] = 1;
            bool falg = func(row-1,col,board,word,visited,n,m,i+1);
            if(falg == true){
                return true;
            }
            visited[row-1][col] = 0;
        }

        if(col+1 < m && visited[row][col+1] == 0 && i < word.size() &&  board[row][col+1] == word[i]){
            visited[row][col+1] = 1;
            bool falg = func(row,col+1,board,word,visited,n,m,i+1);
            if(falg == true){
                return true;
            }
            visited[row][col+1] = 0;
        }

        if(col-1 >=0 && visited[row][col-1] == 0 && i < word.size() && board[row][col-1] == word[i]){
            visited[row][col-1] = 1;
            bool falg = func(row,col-1,board,word,visited,n,m,i+1);
            if(falg == true){
                return true;
            }
            visited[row][col-1] = 0;
        }

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        if(n*m < word.size()){
            return false;
        }
        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == word[0]){
                    vis[i][j] = 1;
                    if(func(i,j,board,word,vis,n,m,1) == true){
                        return true;
                    }
                    vis[i][j]=0;
                }
            }
        }

        return false;
    }
};
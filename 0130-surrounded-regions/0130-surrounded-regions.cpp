class Solution {
public:
    int m,n;
    void dfs(vector<vector<char>>& board , int r,int c){
        if(r<0||r>=m||c<0||c>=n||board[r][c]!='O'){
            return;
        }
        board[r][c]='#';

        dfs(board,r+1,c);
        dfs(board,r-1,c);
        dfs(board,r,c+1);
        dfs(board,r,c-1);
    }

    void solve(vector<vector<char>>& board) {
        m=board.size();
        n = board[0].size();
        for(int i=0;i<m;i++){
            dfs(board,i,0);
            dfs(board,i,n-1);    
        }
        for(int j=0;j<n;j++){
            dfs(board,0,j);
            dfs(board,m-1,j);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                } 
                else if(board[i][j]=='#'){
                    board[i][j]='O';
                }
            }
        }
    }
};
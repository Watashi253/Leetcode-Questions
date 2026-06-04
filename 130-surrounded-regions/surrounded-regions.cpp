class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>> vis(m, vector<int>(n,0));

        queue<pair<int, int>> q;
          for(int j=0;j<n;j++){
            if(!vis[0][j] && board[0][j]=='O'){
                vis[0][j]=1;
                q.push({0,j});
            }
            if(!vis[m-1][j] && board[m-1][j]=='O'){
                vis[m-1][j]=1;
                q.push({m-1,j});
            }
        }

        //traverse on first col & last col

        for(int i=0;i<m;i++){
            if(!vis[i][0] && board[i][0]=='O'){
                vis[i][0]=1;
                q.push({i,0});
            }
            if(!vis[i][n-1] && board[i][n-1]=='O'){
                vis[i][n-1]=1;
                q.push({i,n-1});
            }
        }

        vector<int> dr={-1,0,1,0};
        vector<int> dc={0,1,0,-1};

        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int nrow=row+dr[i];
                int ncol=col+dc[i];
                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n &&
                !vis[nrow][ncol] && board[nrow][ncol]=='O'){
                    q.push({nrow, ncol});
                    vis[nrow][ncol]=1;
                }
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!vis[i][j] &&  board[i][j]=='O'){
                    vis[i][j]=1;
                    board[i][j]='X';
                }
            }
        }
    }
};
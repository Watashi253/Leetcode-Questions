class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];
        if(oldColor == color)
        return image;

        int n=image.size();
        int m=image[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        queue <pair<int, int>> q;
        q.push({sr, sc});
        vis[sr][sc] = color;
        vector<int> dr={-1,0,1,0};
        vector<int> dc={0,1,0,-1};

        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            oldColor=image[row][col];
            vis[row][col]=color;

            for(int i=0; i<4; i++){
                int r=row+dr[i];
                int c=col+dc[i];

                if(r>=0 && r<n && c>=0 && c<m &&
                !vis[r][c] && image[r][c]==oldColor){
                    vis[r][c]=oldColor;
                    q.push({r,c});
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j]!=color){
                    vis[i][j]=image[i][j];
                }
            }
        }

        return vis;
    }
};
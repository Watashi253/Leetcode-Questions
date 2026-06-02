class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];
        if(oldColor == color)
        return image;

        int n=image.size();
        int m=image[0].size();

        queue <pair<int, int>> q;
        q.push({sr, sc});
        vector<int> dr={-1,0,1,0};
        vector<int> dc={0,1,0,-1};
        image[sr][sc]=color;


        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int r=row+dr[i];
                int c=col+dc[i];

                if(r>=0 && r<n && c>=0 && c<m &&
                image[r][c]==oldColor){
                    image[r][c]=color;
                    q.push({r,c});
                }
            }
        }

        return image;
    }
};
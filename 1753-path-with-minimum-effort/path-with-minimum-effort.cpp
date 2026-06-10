class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> dis(m, vector<int>(n,1e9));

        pq.push({0, {0,0}});
        dis[0][0]=0; 

        vector<int> dr={-1, 0, 1, 0};
        vector<int> dc={0,1,0,-1};

        while(!pq.empty()){
            auto it=pq.top();
            int diff=it.first;
            int row=it.second.first;
            int col=it.second.second;
            pq.pop();
            if(row==m-1 && col==n-1) return diff;

            for(int i=0; i<4; i++){
                int nr=row+dr[i];
                int nc=col+dc[i];

                if(nr>=0 && nr<m && nc>=0 && nc<n){
                    int h=max(abs(heights[nr][nc]-heights[row][col]),diff);
                    if(h<dis[nr][nc]){
                        dis[nr][nc]=h;
                        pq.push({h,{nr,nc}});
                    }
                }
            }
        }
        return -1;
    }
};
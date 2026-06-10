class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);

        for(int i=0; i<times.size(); i++){
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
        }

        vector<int> dis(n+1,1e9);
        queue<pair<int, int>> q;
        q.push({0,k});
        dis[k]=0;

        while(!q.empty()){
            auto it=q.front();
            int t=it.first;
            int node=it.second;
            q.pop();

            for(auto x:adj[node]){
                int num=x.first;
                int time=x.second;

                if(time+t <dis[num]){
                    dis[num]=t+time;
                    q.push({dis[num],num});
                }
            }
        }
        int ans=-1e9;
        for(int i=1; i<=n; i++){
            if(dis[i]==1e9) return -1;
            else ans=max(ans,dis[i]);
        }
        return ans;
    }
};
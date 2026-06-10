class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0; i<flights.size(); i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }

        priority_queue<pair<pair<int,int>, int>, vector<pair<pair<int,int>, int>>,
        greater<pair<pair<int,int>, int>>> pq;
        pq.push({{0,0},src});

        vector<int> dist(adj.size(),1e9);
        dist[src]=0;

        while(!pq.empty()){
            auto it=pq.top();
            int stop=it.first.first;
            int cost=it.first.second;
            int node=it.second;
            pq.pop();

            if(stop==k+1) break;

            for(auto x: adj[node]){
                int num=x.first;
                int p=x.second;

                if(p+cost<dist[num]){
                    dist[num]=p+cost;
                    pq.push({{stop+1,dist[num]},num});
                }
            }
        }

        return dist[dst]==1e9?-1:dist[dst];
    }
};
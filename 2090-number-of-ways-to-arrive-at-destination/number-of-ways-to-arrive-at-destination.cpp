class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        int MOD = 1e9 + 7;

        for (auto it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            pq;

        pq.push({0, 0});
        vector<long long> dis(n, LLONG_MAX);
        vector<int> ways(n);
        dis[0] = 0;
        ways[0] = 1;

        while (!pq.empty()) {
            auto it = pq.top();
            long long time = it.first;
            int node = it.second;
            pq.pop();

            if (time > dis[node])
                continue;

            for (auto x : adj[node]) {
                int num = x.first;
                long long t = x.second;

                if (t + time < dis[num]) {
                    dis[num] = t + time;
                    ways[num] = ways[node];
                    pq.push({t + time, num});
                } else if (t + time == dis[num]) {
                    ways[num] = (ways[num] + ways[node]) % MOD;
                }
            }
        }
        return ways[n - 1];
    }
};
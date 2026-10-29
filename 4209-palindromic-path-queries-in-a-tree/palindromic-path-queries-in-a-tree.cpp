#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
    vector<int> parent;
    vector<int> depth;
    vector<int> heavy;
    vector<int> head;
    vector<int> pos;
    vector<int> tree;
    int curr_pos;

    // DFS to compute subtree sizes and identify heavy edges
    int dfs1(int v, int p, int d, const vector<vector<int>>& adj) {
        parent[v] = p;
        depth[v] = d;
        int size = 1;
        int max_sub = 0;
        for (int u : adj[v]) {
            if (u != p) {
                int sub_size = dfs1(u, v, d + 1, adj);
                size += sub_size;
                if (sub_size > max_sub) {
                    max_sub = sub_size;
                    heavy[v] = u;
                }
            }
        }
        return size;
    }

    // DFS to build Heavy-Light chains and map them to segment tree positions
    void dfs2(int v, int p, int h, const vector<vector<int>>& adj) {
        head[v] = h;
        pos[v] = curr_pos++;
        if (heavy[v] != -1) {
            dfs2(heavy[v], v, h, adj);
        }
        for (int u : adj[v]) {
            if (u != p && u != heavy[v]) {
                dfs2(u, v, u, adj);
            }
        }
    }

    // Point update on the Iterative Segment Tree
    void update(int p, int value, int n) {
        p += n;
        tree[p] = value;
        p /= 2;
        while (p > 0) {
            tree[p] = tree[2 * p] ^ tree[2 * p + 1];
            p /= 2;
        }
    }

    // Range XOR query on the Iterative Segment Tree
    int query(int l, int r, int n) {
        l += n;
        r += n;
        int res = 0;
        while (l < r) {
            if (l % 2 == 1) res ^= tree[l++];
            if (r % 2 == 1) res ^= tree[--r];
            l /= 2;
            r /= 2;
        }
        return res;
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // Initialize HLD structures
        parent.assign(n, -1);
        depth.assign(n, 0);
        heavy.assign(n, -1);
        head.assign(n, -1);
        pos.assign(n, 0);
        tree.assign(2 * n, 0);
        curr_pos = 0;

        dfs1(0, -1, 0, adj);
        dfs2(0, -1, 0, adj);

        // Build segment tree array using the HLD mapped positions
        for (int i = 0; i < n; ++i) {
            tree[n + pos[i]] = 1 << (s[i] - 'a');
        }
        for (int i = n - 1; i > 0; --i) {
            tree[i] = tree[2 * i] ^ tree[2 * i + 1];
        }

        vector<bool> ans;
        for (const string& q : queries) {
            istringstream iss(q);
            string type;
            iss >> type;
            if (type == "update") {
                int u;
                char c;
                iss >> u >> c;
                update(pos[u], 1 << (c - 'a'), n);
            } else {
                int u, v;
                iss >> u >> v;
                int res = 0;
                
                // Climb up the chains to find the LCA and aggregate the XOR sum
                while (head[u] != head[v]) {
                    if (depth[head[u]] > depth[head[v]]) swap(u, v);
                    res ^= query(pos[head[v]], pos[v] + 1, n);
                    v = parent[head[v]];
                }
                if (depth[u] > depth[v]) swap(u, v);
                res ^= query(pos[u], pos[v] + 1, n);
                
                // A palindrome is possible if at most 1 bit is set
                ans.push_back((res & (res - 1)) == 0);
            }
        }
        
        return ans;
    }
};
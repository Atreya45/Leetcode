class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<pair<int, int>>> adj(n);

        for (int i = 0; i < n - 1; ++i) {
            adj[i].emplace_back(i + 1, 1);
        }

        vector<int> ans;
        
        for (auto& q : queries) {
            int u = q[0], v = q[1];
            adj[u].emplace_back(v, 1); 
            
            ans.push_back(dijkstra(0, n - 1, n, adj));
        }

        return ans;
    }

private:
    int dijkstra(int src, int target, int n, vector<vector<pair<int, int>>>& adj) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        pq.emplace(0, src);

        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (u == target) return d; 

            if (d > dist[u]) continue;

            for (auto& [v, w] : adj[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.emplace(dist[v], v);
                }
            }
        }

        return dist[target];
    }
};
class DisjointSet {

public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    bool isValid(int newr, int newc, int n) {
        return newr >= 0 && newr < n && newc >= 0 && newc < n;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);

        for (int row = 0; row < n; row++) {
            for (int column = 0; column < n; column++) {
                if (grid[row][column]) {
                    int dx[] = {-1, 1, 0, 0};
                    int dy[] = {0, 0, 1, -1};
                    for (int k = 0; k < 4; k++) {
                        int nx = row + dx[k];
                        int ny = column + dy[k];
                        if (isValid(nx, ny, n) && grid[nx][ny]) {
                            int node = row * n + column;
                            int adjNode = nx * n + ny;
                            ds.unionBySize(node, adjNode);
                        }
                    }
                }
            }
        }
        int mx = 0;
        for (int row = 0; row < n; row++) {
            for (int column = 0; column < n; column++) {
                if (!grid[row][column]) {
                    int dx[] = {-1, 1, 0, 0};
                    int dy[] = {0, 0, 1, -1};
                    set<int> component;
                    for (int k = 0; k < 4; k++) {
                        int nx = row + dx[k];
                        int ny = column + dy[k];
                        if (isValid(nx, ny, n) && grid[nx][ny]) {
                            component.insert(ds.findUPar(nx * n + ny));
                        }
                    }
                    int TotalSize = 0;
                    for (auto it : component) {
                        TotalSize += ds.size[it];
                    }
                    mx = max(mx, TotalSize + 1);
                }
            }
        }
        if (mx == 0) {
            mx = n * n;
        }

        return mx;
    }
};
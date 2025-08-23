// class Solution {
// public:
//     vector<int> parent, size;
//     void make_set(int v) {
//         parent[v] = v;
//         size[v] = 1;
//     }
//     int findPar(int v) {
//         if (parent[v] == v) {
//             return v;
//         }
//         return parent[v] = findPar(parent[v]);
//     }
//     void Union(int a, int b) {
//         a = findPar(a);
//         b = findPar(b);
//         if (a != b) {
//             if (size[a] < size[b]) {
//                 swap(a, b);
//             }
//             parent[b] = a;
//             size[a] += size[b];
//         }
//     }
//     int removeStones(vector<vector<int>>& stones) {
//         int n = stones.size();
//         parent.resize(n);
//         size.resize(n);
//         for (int i = 0; i < n; i++) {
//             make_set(i);
//         }
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < i; j++) {
//                 if (stones[i][0] == stones[j][0] ||
//                     stones[i][1] == stones[j][1]) {
//                     if (findPar(i) != findPar(j)) {
//                         Union(i, j);
//                     }
//                 }
//             }
//         }
//         int cnt = 0;
//         for (int i = 0; i < n; i++) {
//             if (parent[i] == i) {
//                 cnt++;
//             }
//         }
//         return n - cnt;
//     }
// };
class Solution {
public:
    vector<int> par, sz;
    
    int findPar(int v) {
        if (par[v] == v) return v;
        return par[v] = findPar(par[v]);
    }
    
    void Union(int a, int b) {
        a = findPar(a);
        b = findPar(b);
        if (a != b) {
            if (sz[a] < sz[b]) swap(a, b);
            par[b] = a;
            sz[a] += sz[b];
        }
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxRow = 0, maxCol = 0;
        for (auto &s : stones) {
            maxRow = max(maxRow, s[0]);
            maxCol = max(maxCol, s[1]);
        }
        
        int N = maxRow + maxCol + 2;  
        par.resize(N);
        sz.resize(N, 1);
        for (int i = 0; i < N; i++) par[i] = i;
        
        unordered_set<int> st;
        for (auto &s : stones) {
            int r = s[0];
            int c = s[1] + maxRow + 1;  
            Union(r, c);
            st.insert(r);
            st.insert(c);
        }
        
        int comp = 0;
        for (auto &x : st) {
            if (findPar(x) == x) comp++;
        }
        
        return n - comp;
    }
};

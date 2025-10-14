class DSU {
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find_set(int v) {
        if (v == parent[v]) {
            return v;
        }
        return parent[v] = find_set(parent[v]);
    }
    void union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (rank[a] < rank[b]) {
                swap(a, b);
            }
            parent[b] = a;
            if (rank[a] == rank[b]) {
                rank[a]++;
            }
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        DSU ds(n);
        unordered_map<string,int>emailToId;
        unordered_map<string,string>emailToName;
        for(int i=0;i<n;i++){
            int m=accounts[i].size();
            for(int j=1;j<m;j++){
                string email=accounts[i][j];
                emailToName[email]=accounts[i][0];
                if(emailToId.find(email)!=emailToId.end()){
                    ds.union_sets(i,emailToId[email]);
                }
                else{
                    emailToId[email]=i;
                }
            }
        }
        unordered_map<int,vector<string>>groups;
        for(auto it:emailToId){
            groups[ds.find_set(it.second)].push_back(it.first);
        }
        vector<vector<string>>ans;
        for(auto it:groups){
            auto emails=it.second;
            sort(emails.begin(),emails.end());
            vector<string>account;
            account.push_back(emailToName[emails[0]]);
            for(auto e:emails){
                account.push_back(e);
            }
            ans.push_back(account);
        }
        return ans;
    }
};
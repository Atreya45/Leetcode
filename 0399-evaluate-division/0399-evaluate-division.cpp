class Solution {
public:
    void dfs(unordered_map<string,vector<pair<string,double>>>&adj,string src,string dest,unordered_set<string>&visited,double product,double &value){
        if(visited.find(src)!=visited.end()){
            return;
        }
        visited.insert(src);
        if(src==dest){
            value=product;
            return;
        }
        for(auto&p:adj[src]){
            dfs(adj,p.first,dest,visited,product*(p.second),value);
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n=equations.size();
        unordered_map<string,vector<pair<string,double>>>adj;
        for(int i=0;i<n;i++){
            adj[equations[i][0]].push_back({equations[i][1],values[i]});
            adj[equations[i][1]].push_back({equations[i][0],1.0/values[i]});
        }
        vector<double>ans;
        for(auto& q:queries){
            string src=q[0];
            string dest=q[1];
            double value=-1.0;
            double product=1.0;
            if(adj.find(src)!=adj.end()){
                unordered_set<string>visited;
                dfs(adj,src,dest,visited,product,value);
            }
            ans.push_back(value);
        }
        return ans;
    }
};
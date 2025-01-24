class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> indegree(n, 0);
        vector<int> ans;
        vector<int> adj[n];
        queue<int> q;
        int i = 0;
        for (auto it1 : graph) {
            for (auto it2 : it1) {
                adj[it2].push_back(i);
                indegree[i]++;
            }
            i++;
        }
        for (int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
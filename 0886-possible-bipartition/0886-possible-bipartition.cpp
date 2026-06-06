class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int>colored(n+1,-1);
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<dislikes.size();i++){
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        for(int i=1;i<=n;i++){
            if(colored[i]==-1){
                colored[i]=1;
                queue<int>q;
                q.push(i);
                while(!q.empty()){
                    int node=q.front();q.pop();
                    for(int child:adj[node]){
                        if(colored[node]==colored[child]){
                            return false;
                        }
                        if(colored[child]==-1){
                            q.push(child);
                            colored[child]=1-colored[node];
                        }
                    }
                }
            }
        }
        return true;
    }
};
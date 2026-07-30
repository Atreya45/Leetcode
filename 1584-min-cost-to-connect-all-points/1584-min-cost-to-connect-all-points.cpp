class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        vector<bool>vis(n+1,false);
        q.push({0,0});
        int ans=0;
        while(!q.empty()){
            auto [cost,node]=q.top();
            q.pop();
            if(vis[node])continue;
            vis[node]=true;
            ans+=cost;
            for(int i=0;i<n;i++){
                if(!vis[i]){
                    int dist =abs(points[node][0] - points[i][0]) +abs(points[node][1] - points[i][1]);
                    q.push({dist, i});
                }
            }
        }
        return ans;
    }
};
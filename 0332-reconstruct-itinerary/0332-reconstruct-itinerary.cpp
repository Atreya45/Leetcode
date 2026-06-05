class Solution {
public:
    unordered_map<string,priority_queue<string,vector<string>,greater<string>>>mapping;
    vector<string>ans;
    void dfs(string s){
        while(!mapping[s].empty()){
            string element=mapping[s].top();mapping[s].pop();
            dfs(element);
        }
        ans.push_back(s);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int n=tickets.size();
        // for(int i=0;i<n;i++){
        //     mapping[tickets[i][0]].push(tickets[i][1]);
        // }
        // vector<string>ans;
        // ans.push_back("JFK");
        // string after=mapping["JFK"].top();mapping["JFK"].pop();
        // ans.push_back(after);

        // while((mapping[after]).size()>0){
        //     after=mapping[after].top();mapping[after].pop();
        //     ans.push_back(after);

        // }
        // return ans;
        for(int i=0;i<n;i++){
            mapping[tickets[i][0]].push(tickets[i][1]);
        }
        dfs("JFK");
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
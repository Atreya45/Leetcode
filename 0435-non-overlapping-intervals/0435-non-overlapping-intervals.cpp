class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans=0;
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),
        [](const vector<int>&a,const vector<int>&b){
            return a[1]<b[1];
        });
        int ps=intervals[0][0];
        int pe=intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0]<pe){
                ans++;
                continue;
            }
            ps=intervals[i][0];
            pe=intervals[i][1];
        }
        return ans;
    }
};
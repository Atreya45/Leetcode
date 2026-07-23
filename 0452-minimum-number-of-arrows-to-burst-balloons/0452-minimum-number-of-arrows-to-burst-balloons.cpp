class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        sort(points.begin(),points.end());
        int prevStart=points[0][0];
        int prevEnd=points[0][1];
        int ans=1;
        for(int i=1;i<n;i++){
            if(points[i][0]<=prevEnd){
                prevEnd=min(points[i][1],prevEnd);
            }
            else{
                prevStart=points[i][0];
                prevEnd=points[i][1];
                ans++;
            }
        }
        //[[0, 6], [0, 9], [2, 8], [2, 9], [3, 8], [3, 9], [3, 9], [6, 8], [7, 12], [9, 10]].
        return ans;
    }
};
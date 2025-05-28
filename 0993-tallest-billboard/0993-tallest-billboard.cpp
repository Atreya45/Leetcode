//watch this video:  https://www.youtube.com/watch?v=Zyzs3AuqPRw
class Solution {
    int dp[21][10001];
    int tallestBillboardHelper(vector<int>& rods,int n,int index,int diff){
        if(index==n){
            return diff==0?0:INT_MIN;
        }
        if(dp[index][diff+5000]!=-1){
            return dp[index][diff+5000];
        }
        int skip=tallestBillboardHelper(rods,n,index+1,diff);
        int takeS1=rods[index]+tallestBillboardHelper(rods,n,index+1,diff+rods[index]);
        int takeS2=rods[index]+tallestBillboardHelper(rods,n,index+1,diff-rods[index]);
        return dp[index][diff+5000]=max({skip,takeS1,takeS2});
    }
public:
    int tallestBillboard(vector<int>& rods) {
        int n=rods.size();
        memset(dp,-1,sizeof(dp));
        return tallestBillboardHelper(rods,n,0,0)/2;
    }
};
class Solution {
public:
    int findSmallestValueIndex(vector<int>&ans){
        int ii=0;
        int mini=ans[0];
        for(int i=1;i<ans.size();i++){
            if(ans[i]<mini){
                mini = ans[i];
                ii=i;
            }
        }
        return ii;
    }
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        vector<int>ans=nums;
        for(int i=0;i<k;i++){
            int index=findSmallestValueIndex(ans);
            ans[index]=ans[index]*multiplier;
        }
        return ans;
    }
};
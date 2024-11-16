class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans;
        bool flag=0;
        for(int i=0;i<=n-k;i++){
            flag=0;
            for(int j=i;j<=i+k-2;j++){
                if(nums[j]>=nums[j+1]||nums[j+1]!=nums[j]+1){
                    flag=1;
                }
            }
            if(flag){
                ans.push_back(-1);
            }
            else{
                ans.push_back(nums[i+k-1]);
            }
        }
        return ans;
    }
};
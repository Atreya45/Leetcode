class Solution {
public:
    int maxProduct(vector<int>& nums) {
        double prefix=1;
        double suffix=1;
        double n = nums.size();
        double maxi=INT_MIN;
        for(int i = 0; i < nums.size();i++)
        {
            if(prefix==0)
            {
                prefix=1;
            }
            if(suffix==0)
            {
                suffix=1;
            }
            prefix*=nums[i];
            suffix*=nums[n-i-1]; // to start suffix from the last end 
            maxi=max(maxi , max(suffix,prefix));

        }
        return maxi;
    }
};
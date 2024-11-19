class Solution 
{
public:
    long long maximumSubarraySum(vector<int>& nums, int k) 
    {
        long long res = 0, cur = 0, dup = -1;
        vector<long long> pos(100001,-1);
        
        for (int i = 0; i < nums.size(); ++i)
        {
            cur += nums[i];
            if (i >= k) cur -= nums[i-k];
            
            dup = max(dup, pos[nums[i]]);
            if (i - dup >= k) res = max(res, cur);
            
            pos[nums[i]] = i;
        }
        
        return res;
    }
};
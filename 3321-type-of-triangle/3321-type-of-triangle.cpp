class Solution {
public:
    string triangleType(vector<int>& nums) {
        map<int,int> mp;
        if(nums[0]+nums[1]<=nums[2]||nums[0]+nums[2]<=nums[1]||nums[1]+nums[2]<=nums[0])
            return "none";
        else
        {
            for(auto it:nums){
                mp[it]++;
            }
        }
        int count=0;
        for(auto it:mp){
            if(it.second==3)return "equilateral";
            else if(it.second==2)return "isosceles";
           
        }
         return "scalene";
    }
};
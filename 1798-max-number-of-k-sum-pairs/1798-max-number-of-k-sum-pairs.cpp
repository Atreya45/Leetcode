class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n=nums.size();
        int s=0,e=n-1;
        int count=0;
        sort(nums.begin(),nums.end());
        while(s<e){
            if(nums[s]+nums[e]<k){
                s++;
            }
            else if(nums[s]+nums[e]>k){
                e--;
            }
            else{
                count++;
                s++,e--;
            }
        }
        return count;
    }
};
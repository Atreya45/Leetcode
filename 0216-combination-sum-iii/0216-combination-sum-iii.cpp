class Solution {
    void combinationSum3Helper(vector<vector<int>>& result, vector<int>& temp,
                               int k, int n, int start) {
        if(n<0){
            return;
        }
        if(n==0){
            if(k==0){
                result.push_back(temp);
            }
            return;
        }
        for(int i=start;i<=9;i++){
            temp.push_back(i);
            combinationSum3Helper(result, temp, k-1, n-i, i+1);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> temp;
        combinationSum3Helper(result, temp, k, n, 1);
        return result;
    }
};
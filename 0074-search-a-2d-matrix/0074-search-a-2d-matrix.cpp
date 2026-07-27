class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size(),col=matrix[0].size();
        int r=row-1,c=0;
        while(c<col&&r>=0){
            int curr=matrix[r][c];
            if(curr==target){
                return true;
            }
            if(target<curr){
                r--;
            }
            else{
                c++;
            }
        }
        return false;
    }
};
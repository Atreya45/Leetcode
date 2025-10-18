class Solution {
public:
    int findMaxIndex(vector<vector<int>>& mat,int m,int n,int mid){
        int maxValue=-1;
        int index=-1;
        for(int i=0;i<m;i++){
            if(mat[i][mid]>maxValue){
                maxValue=mat[i][mid];
                index=i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        int l=0,h=n-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            int maxIndex=findMaxIndex(mat,m,n,mid);
            int left=mid-1>=0?mat[maxIndex][mid-1]:-1;
            int right=mid+1<n?mat[maxIndex][mid+1]:-1;
            if(mat[maxIndex][mid]>left&&mat[maxIndex][mid]>right){
                return {maxIndex,mid};
            }
            else if(mat[maxIndex][mid]<left){
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return {-1,-1};
    }
};
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size(),s1=0,s2=0,ans=0;
        for(int i=0;i<n;i++){
            s1+=i,s2+=arr[i];
            if(s1==s2){
                ans++;
            }
        }
        return ans;
    }
};
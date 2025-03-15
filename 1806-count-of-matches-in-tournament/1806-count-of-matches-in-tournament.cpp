class Solution {
public:
    int numberOfMatches(int n) {
        int ans=0;
        int M=0,A=n;
        while(A>1){
            if(A%2==0){
                M=A/2;
                A=A/2;
                ans+=M;
            }
            else{
                M=A/2;
                A=A/2+1;
                ans+=M;
            }
        }
        return ans;
    }
};
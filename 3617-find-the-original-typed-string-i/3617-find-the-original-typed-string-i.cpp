class Solution {
public:
    int possibleStringCount(string word) {
        int n=word.size();
        stack<int>st;
        for(int i=0;i<n;i++){
            if(st.empty()||st.top()!=word[i]){
                st.push(word[i]);
            }
        }
        return n-st.size()+1;
    }
};
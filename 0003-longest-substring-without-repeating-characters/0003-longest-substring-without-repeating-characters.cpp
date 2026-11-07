class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length(),max_len=0,i=0,j;
        unordered_set<char> st;

        for(j=0; j < n; j++){
          //shrink the window --> In set repeating char is present
          while(st.count(s[j])){
           st.erase(s[i]);
           i++;
          }
           
          st.insert(s[j]);
          max_len = max(max_len , j-i+1);
        }
        return max_len;
    }
};
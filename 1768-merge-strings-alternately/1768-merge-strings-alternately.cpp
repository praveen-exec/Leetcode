//Time : O(m+n)
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans={};

        int w1=word1.size(),w2=word2.size();

        for(int i=0; i< w1 + w2 ; i++){
            if(i<w1)
            ans+=word1[i];

            if(i<w2)
            ans+=word2[i];
        }
      return ans;
    }
};
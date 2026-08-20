class Solution {
public:
    int scoreOfString(string s) {
        int sum=0;
        for(int i=1;i<s.length();i++){
            int LastChar=s[i-1];
            int PreChar=s[i];

            sum+=abs(LastChar-PreChar);
        }

        return sum;
    }
};
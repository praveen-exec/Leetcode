class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());

        string ans="";
        int n=s.length();

        for(int i=0;i<n;i++){

          string word="";
          //string --> word
          while(i < n && s[i]!=' '){
           word+=s[i];
           i++;
          }

          reverse(word.begin(),word.end());
          //valid word i.e not space
          if(word.length() > 0)
            ans+=" "+word;
            
        }

        return ans.substr(1);
    }
};
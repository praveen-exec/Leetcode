class Solution {
public:
    string reverseWords(string s) {
       reverse(s.begin(),s.end());

       vector<string> tokens;

       stringstream ss(s);
       string token="";

       while(ss >> token){
        tokens.push_back(token);
       }

       string ans="";
       for(int i=0;i<tokens.size();i++){
        reverse(tokens[i].begin(),tokens[i].end());
        ans+=" "+tokens[i];
       }
       
     return ans.substr(1);
    }
};
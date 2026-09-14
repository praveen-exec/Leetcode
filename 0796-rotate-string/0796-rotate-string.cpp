class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        int m = goal.length();

        if(n != m) return false;

        string s1;
        s1=s+s;

        if(s1.find(goal) != string::npos)
          return true;
        else
          return false;


    }
};
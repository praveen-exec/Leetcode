class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        int m = goal.length();

        if(n != m) return false;

        for(int i=0; i<n ;i++){
        //eg s = abcde | s.substring(1)=bcde + s[0]=a ==>bcdea
         s = s.substr(1) + s[0];

         //check if equal to goal or not
         if(s==goal) 
           return true;

        }

        return false;
    }
};
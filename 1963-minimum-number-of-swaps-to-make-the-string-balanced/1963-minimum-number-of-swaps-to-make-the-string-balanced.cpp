class Solution {
public:
    int minSwaps(string s) {
        //if string lenth is odd 
        if(s.length() & 1) return -1;

        stack<char> st;
        int n = s.length();

        int c=0; //counting closing bracket

        for(int i=0;i<n;i++)
        {

         if(s[i]=='[')
          st.push('[');

         // s[i] = ']' && stack is not empty
         else if(s[i]==']' && !st.empty())
          st.pop();
        
         else
           c++;

        }
        
        //if closing brackets is odd then c/2 + 1
        if(c & 1)
         return c/2 + 1;
        
        else
         return c/2;

    }
};
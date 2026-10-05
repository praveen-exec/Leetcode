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
        
    return (c + 1) / 2;

    }
};

//Solution 2
class Solution {
public:
    int minSwaps(string s) {

        int balance = 0;
        int c = 0;   // unmatched closing brackets

        for(char ch : s) {

            if(ch == '[') {
                balance++;
            }
            else {
                balance--;

                // extra closing bracket
                if(balance < 0) {
                    c++;
                    balance = 0;
                }
            }
        }

        return (c + 1) / 2;
    }
};

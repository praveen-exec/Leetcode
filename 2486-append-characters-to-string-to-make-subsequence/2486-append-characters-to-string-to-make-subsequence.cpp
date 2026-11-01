//c o a c h i n g  ==>s
//                i
//c o d i n g      ==>t
//  j

//t.length()=6
//6-2=4 ( ding )
class Solution {
public:
    int appendCharacters(string s, string t) {
        int i=0,j=0;
        while(i<s.length() && j<t.length()){
            if(s[i] == t[j])
              j++;
            
            i=i+1; //everytime 
        }
        return t.length() - j;
    }
};
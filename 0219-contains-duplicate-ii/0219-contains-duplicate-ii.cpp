class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> st;

        for(int i = 0; i < nums.size(); i++) {

            // agar hume same element mil jaaye k ke andar, toh return true
            if(st.find(nums[i]) != st.end())
                return true;

            // current element ko set mein daal do
            st.insert(nums[i]);

            // agar window size k se badi ho gayi hai
            if(i >= k) {

                // sabse purane number ko delete kardo
                st.erase(nums[i - k]);
                
            }
        }
        return false;
    }
};
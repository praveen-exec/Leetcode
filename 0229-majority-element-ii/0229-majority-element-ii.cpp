class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        unordered_map<int,int> mp;

        for (int i : nums) 
          mp[i]++;

        int n1=n/3;

        for (auto it : mp){
          if (it.second > n1){
           ans.push_back(it.first);
         }
        }
    return ans;
    }
};
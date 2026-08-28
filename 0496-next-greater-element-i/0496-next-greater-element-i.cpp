class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> ans;

        for (int i = 0; i < nums1.size(); i++) {
            
            int index = -1;

            // Find nums1[i] in nums2
            for (int j = 0; j < nums2.size(); j++) {
                if (nums1[i] == nums2[j]) {
                    index = j;
                    break;
                }
            }

            int nextEl = -1;

            // Find the FIRST greater element
            for (int k = index + 1; k < nums2.size(); k++) {
                if (nums2[k] > nums1[i]) {
                    nextEl = nums2[k];
                    break;
                }
            }

            ans.push_back(nextEl);
        }

        return ans;
    }
};
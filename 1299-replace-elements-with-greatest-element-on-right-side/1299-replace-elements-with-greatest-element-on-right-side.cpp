class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n=arr.size();
        vector<int> ans(n);
        int maxi = INT_MIN;

        ans[n - 1] = -1;

        for (int i = n - 1; i >= 1; i--) {
            maxi = max(maxi, arr[i]);
            ans[i - 1] = maxi;
        }

        arr=ans;
        return arr;
    }
};
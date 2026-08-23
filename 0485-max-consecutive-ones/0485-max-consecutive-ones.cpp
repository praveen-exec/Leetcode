class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& a) {
        int count = 0;
        int max_count = 0;

        for (int i = 0; i < a.size(); i++) {

            if (a[i] == 1) {
                count++;
                max_count = max(max_count, count);
            }
            else {
                count = 0;
            }
        }

        return max_count;
    }
};
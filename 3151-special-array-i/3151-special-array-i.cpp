class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i] % 2 == nums[i + 1] % 2)
                return false;
        }
        return true;
    }
};


class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        for(int i=0,j=1;i<nums.size() && j<nums.size();i++,j++){
            if(nums[i] % 2 == 0  && nums[j] % 2 ==0) return false;

            if(nums[i] % 2 != 0  && nums[j] % 2 !=0) return false;


        }
        return true;
    }
};

class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size() - 1;

        while (i < j) {
            int curr = nums[i] + nums[j];
            if (curr == target)
                return {i+1,j+1};
            else if (curr > target)
                j--;
            else
                i++;
        }
        return {-1, -1};
    }
};

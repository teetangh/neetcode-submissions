class Solution {
    int getSubarrays(vector<int>& nums, int split) {
        int curr = 0;
        int numSubarrays = 0;
        for (auto ele : nums) {
            if (curr + ele <= split) {
                curr += ele;
            } else {
                curr = ele;
                numSubarrays++;
            }
        }

        return curr > 0 ? numSubarrays + 1 : numSubarrays;
    }

   public:
    int splitArray(vector<int>& nums, int k) {
        int max = *max_element(nums.begin(), nums.end());
        int sum = accumulate(nums.begin(), nums.end(), 0);

        int low = max;
        int high = sum;
        int ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int subArrays = getSubarrays(nums, mid);
            if (subArrays <= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
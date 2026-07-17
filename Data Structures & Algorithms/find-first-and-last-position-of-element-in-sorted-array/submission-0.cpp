class Solution {

    int lowerBound(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        int position = nums.size();
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                position = mid;
                high = mid - 1;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return (position != nums.size()) ? position : -1;
    }

    int upperBound(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        int position = nums.size();
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                position = mid;
                low = mid + 1;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return (position != nums.size()) ? position : -1;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {lowerBound(nums, target), upperBound(nums,target)};
    }
};
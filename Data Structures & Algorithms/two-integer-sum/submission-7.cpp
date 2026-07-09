class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int,vector<int>> umpp;
        int len = nums.size();

        for(int i = 0; i < len; i++){
            umpp[nums[i]].push_back(i);
        }

        sort(nums.begin(),nums.end());

        int i = 0, j = nums.size() - 1;
        int sum = 0;
        vector<int> result;

        while(i < j){
            sum = nums[i] + nums[j];
            if(sum < target)
                i++;
            else if (sum > target)
                j--;
            else{
                auto first = umpp[nums[i]];
                auto second = umpp[nums[j]];
                                
                if(nums[i] != nums[j])
                    result = {first[0],second[0]};
                else
                    result = {first[0],first[1]};              
                sort(result.begin(),result.end());
                return result;
            }
        }

        return {-1,-1};
    }
};

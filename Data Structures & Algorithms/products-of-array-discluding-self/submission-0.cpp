class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        if(n == 2){
            return {nums[1],nums[0]};
        }

        vector<int> prefixProduct;
        int product = 1;
        for(int i = 0; i < n; i++){
            product *= nums[i];
            prefixProduct.push_back(product);
        }

        vector<int> suffixProduct;
        product = 1;
        for(int i = n-1; i >=0 ; i--){
            product *= nums[i];
            suffixProduct.push_back(product);
        }
        reverse(suffixProduct.begin(),suffixProduct.end());
 
        vector<int> answer(n,1);
        for(int i = 1; i < n - 1; i++){
            answer[i] = prefixProduct[i-1] * suffixProduct[i+1];
        }
        answer[0] = suffixProduct[1];
        answer[n-1] = prefixProduct[n-2];

        return answer;
    }
};

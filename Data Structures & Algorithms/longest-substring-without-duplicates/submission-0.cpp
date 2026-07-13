class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        int n = s.size();

        unordered_map<char,int> mpp;

        int maxLength = 0;
        while(r < n){
            mpp[s[r]]++;
            while(mpp[s[r]] > 1){
                mpp[s[l]]--;
                l++;
            } 
            if(mpp[s[r]] <= 1){
                maxLength = max(maxLength,r-l+1);
            }

            r++;
        }

        return maxLength;
    }
};

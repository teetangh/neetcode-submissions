class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        int n = s.size();

        unordered_map<char, int> mpp;

        int maxLength = 0;
        while (r < n) {

            if(mpp.find(s[r]) != mpp.end() && mpp[s[r]] >= l){
                l = mpp[s[r]] + 1;
            }

            int length = r - l + 1;
            if (length > maxLength) maxLength = length;
            mpp[s[r]] = r;
            r++;
        }

        return maxLength;
    }
};

class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int r = 0;

        unordered_map<char, int> mpp;
        int n = s.size();

        int maxLength = 0;
        char maxFreqChar;
        int maxFreq = 0;
        while (r < n) {
            mpp[s[r]]++;

            if (mpp[s[r]] > maxFreq) {
                maxFreq = mpp[s[r]];
                maxFreqChar = s[r];
            }

            int length = r - l + 1;
            if (length - mpp[maxFreqChar] > k) {
                mpp[s[l]]--;
                l++;
                if (mpp[s[l]] == 0)
                    mpp.erase(s[l]);
            }

            if (length - mpp[maxFreqChar] <= k)
                maxLength = max(length,maxLength);

            r++;
        }

        return maxLength;
    }
};

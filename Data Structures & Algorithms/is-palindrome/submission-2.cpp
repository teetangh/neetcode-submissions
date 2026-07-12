class Solution {
   
   bool isAlphanumeric(char c){
        if (c >= 'a' && c <= 'z')
            return true;
        if (c >= '0' && c <= '9')
            return true;

        return false;
   }
   
   public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;

        while (i < j) {
            char c1 = tolower(s[i]);
            char c2 = tolower(s[j]);

            if (isAlphanumeric(c1) && isAlphanumeric(c2)) {
                if (c1 == c2) {
                    i++, j--;
                } else {
                    return false;
                }
            } else if (isAlphanumeric(c1)) {
                j--;
            } else if (isAlphanumeric(c2)) {
                i++;
            } else {
                i++,j--;
            }
        }

        return true;
    }
};

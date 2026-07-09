class Solution {
public:
    bool isAnagram(string s1, string s2) {
          if(s1.size() != s2.size())
            return false;
        
        if (s1.size() == 0)
            return true;
        
        map<char,int> freq;
        int len = s1.size();
        
        for(int i = 0 ; i < len ; i++){
            freq[s1[i]]++;
            freq[s2[i]]--;
        }
        
        for(char c = 'a' ; c <= 'z' ; c++){
            if(freq[c] !=0)
                return false;
        }
        
        return true;
    }
};

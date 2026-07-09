class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& arr) {
        unordered_map<string,vector<string>> umpp;
        
        for(string word : arr){
            map<char,int> freq;
            int len = word.size();
            
            for(int i = 0 ; i < len ; i++)
                freq[word[i]]++;
                
            string temp = "";
            for(pair<char,int> c : freq){
                temp += c.first + to_string(c.second); 
            }
            
            umpp[temp].push_back(word);
        }
        
        vector<vector<string>> result;
        for(pair<string,vector<string>> freqPattern : umpp){
            vector<string> row;
            for(string word : freqPattern.second){
                row.push_back(word);
            }
            result.push_back(row);
        }
        
        return result;
    }
};

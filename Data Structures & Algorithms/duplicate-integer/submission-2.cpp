class Solution {
public:
    bool hasDuplicate(vector<int>& arr) {
        map<int,int> mpp;
        for(auto a : arr){
            if(mpp[a] != 0){
                return true;
            }
            mpp[a]++;
        }
        
        return false;
    }
};
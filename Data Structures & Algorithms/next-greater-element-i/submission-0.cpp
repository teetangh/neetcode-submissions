class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;

        int n = nums2.size();
        
        map<int,int> ngr;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums2[i] >= st.top()) {
                st.pop();
            }
            if (st.empty())
                ngr[nums2[i]] = -1;
            else
                ngr[nums2[i]] = st.top();
            st.push(nums2[i]);
        }

        vector<int> result(nums1.size(),-1);

        for(int i = 0 ; i < nums1.size() ; i++){
            result[i]= ngr[nums1[i]];
        }

        return result;
    }
};
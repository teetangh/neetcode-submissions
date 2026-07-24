class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // code here
        stack<int> st;

        int n = temperatures.size();

        vector<int> ngr(n, -1);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && temperatures[i] >= temperatures[st.top()]) {
                st.pop();
            }
            if (st.empty())
                ngr[i] = 0;
            else
                ngr[i] = st.top();
            st.push(i);
        }
        for (int i = 0; i < n; i++) {
            if (ngr[i] == 0) continue;
            ngr[i] -= i;
        }
        return ngr;
    }
};

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n = asteroids.size();
        for (int i = 0; i < n; i++) {
            if (asteroids[i] >= 0 || st.empty()) {
                st.push(asteroids[i]);
            } else {
                while (!st.empty() && st.top() >= 0 &&
                       abs(asteroids[i]) > st.top()) {
                    st.pop();
                }

                if (st.empty() || st.top() < 0) {
                    st.push(asteroids[i]);

                } else {
                    if (abs(asteroids[i]) == st.top()) {
                        st.pop();
                    } else { // abs(asteroids[i]) > st.top()
                        continue;
                    }
                }
            }
        }

        vector<int> result;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
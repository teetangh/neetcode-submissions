class Solution {
    stack<int> st;
public:
    bool isValid(string s) {
        for(int i = 0 ; i < s.size() ; i++){
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);
            else {
                if(st.empty())
                    return false;
                char top = st.top();
                if (top == '(' && s[i] != ')')
                    return false;
                if (top == '{' && s[i] != '}')
                    return false;
                if (top == '[' && s[i] != ']')
                    return false;
                st.pop();
            }
        }

        return st.empty() ? true : false;
    }
};

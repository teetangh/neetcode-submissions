class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i].compare("+") == 0 || tokens[i].compare("-") == 0 ||
                tokens[i].compare("*") == 0 || tokens[i].compare("/") == 0) {
                int b = st.top();
                st.pop();

                int a = st.top();
                st.pop();

                if (tokens[i] == "+")
                    st.push(a + b);
                else if (tokens[i] == "-")
                    st.push(a - b);
                else if (tokens[i] == "*")
                    st.push(a * b);
                else
                    st.push(a / b);

            } else {
                cout << tokens[i] << endl;
                int num = std::stoi(tokens[i]);
                st.push(num);
            }
        }

        return st.top();
    }
};
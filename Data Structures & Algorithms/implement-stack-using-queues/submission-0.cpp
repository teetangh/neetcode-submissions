class MyStack {

    queue<int> q1, q2;
    bool isQ1active;

public:
    MyStack() { isQ1active = true; }

    void push(int x) {
        if (isQ1active)
            q1.push(x);
        else
            q2.push(x);
    }

    int pop() {
        if (isQ1active) {
            while (q1.size() > 1) {
                int ele = q1.front();
                q1.pop();
                q2.push(ele);
            }

            int res = q1.front();
            q1.pop();
            isQ1active = false;
            return res;
        } else {
            while (q2.size() > 1) {
                int ele = q2.front();
                q2.pop();
                q1.push(ele);
            }

            int res = q2.front();
            q2.pop();
            isQ1active = true;
            return res;
        }
    }

    int top() {
        if (isQ1active) {
            while (q1.size() > 1) {
                int ele = q1.front();
                q1.pop();
                q2.push(ele);
            }

            int res = q1.front();
            return res;
        } else {
            while (q2.size() > 1) {
                int ele = q2.front();
                q2.pop();
                q1.push(ele);
            }

            int res = q2.front();
            return res;
        }
    }

    bool empty() { return q1.size() == 0 && q2.size() == 0; }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
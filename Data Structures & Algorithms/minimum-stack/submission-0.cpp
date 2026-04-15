class MinStack {
public:
    stack<int> s1;
    stack<int> s2;
    MinStack() {
    }
    
    void push(int val) {
        if (s1.empty()) {
            s1.push(val);
            s2.push(val);
        } else {
            s1.push(val);
            s2.push(min(val, s2.top()));
        }
    }
    
    void pop() {
        s1.pop();
        s2.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
};

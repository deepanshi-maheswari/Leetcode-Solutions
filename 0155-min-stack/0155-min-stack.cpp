class MinStack {
public:
    stack<int> st;
    stack<int> minSt;
    MinStack() {
        
    }
    
    void push(int value) {
        st.push(value);

        if(minSt.empty()){
            minSt.push(value);
        }
        else{
            minSt.push(min(value, minSt.top()));
        }
    }
    
    void pop() {
        if(!st.empty()){
            st.pop();
            minSt.pop();
        }
    }
    
    int top() {
        if(!st.empty()){
            return st.top();
        }
        else{
            return -1;
        }
    }
    
    int getMin() {
        return minSt.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
class MinStack {
private:
    vector<pair<int,int>> _stack;
    int _min;
public:
    MinStack() {
        _stack = {};
        _min = INT_MAX;
    }
    
    void push(int val) {
        if (!_stack.size()) _stack.push_back({val, val});
        else _stack.push_back({val, min(val, _min)});
        _min = _stack.back().second;
    }
    
    void pop() {
        _stack.pop_back();
        if (_stack.size()) _min = _stack.back().second;
    }
    
    int top() {
        return _stack.back().first;
    }
    
    int getMin() {
        return _min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
class MinStack {
private:
    stack <int> st; 
    stack <int> prefixMin; 
public:
    MinStack() {
    }
    
    void push(int val) {
        st.push(val);
        if (!prefixMin.empty())
            prefixMin.push(min(val, prefixMin.top()));
        else prefixMin.push(val);
    }
    
    void pop() {
       st.pop(); 
       prefixMin.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return prefixMin.top();
    }
};


/*
4 1
1 1 
3 3 
*/ 
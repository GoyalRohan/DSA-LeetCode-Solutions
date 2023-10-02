class MyStack {
public:
    
    queue<int> q ; 
    
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x) ; 
        int size = q.size() ; 
        while(size-- > 1)
        {
            q.push(q.front()) ; 
            q.pop() ; 
        }
    }
    
    int pop() {
        if(q.empty())
            return -1 ; 
        
        int ans = q.front() ; 
        q.pop() ; 
        return ans ; 
    }
    
    int top() {
        if(q.empty())
            return -1 ; 
        
        int ans = q.front() ; 
        return ans ; 
    }
    
    bool empty() {
        if(q.empty())
            return true ; 
        return false ; 
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
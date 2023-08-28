class MyStack {
public:
    
    queue<int> q1 ; 
    
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x) ; 
        
        int size = q1.size() ; 
        while(size-- > 1)
        {
            q1.push(q1.front()) ;
            q1.pop() ; 
        } 
    }
    
    int pop() {
        
        if(!q1.empty())
        {
            int ans = q1.front() ; 
            q1.pop() ; 
            return ans ; 
        }
        return -1 ; 
    }
    
    int top() {
        
        if(q1.empty())
            return -1 ; 
        
        return q1.front() ; 
    }
    
    bool empty() {
        if(q1.empty())
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
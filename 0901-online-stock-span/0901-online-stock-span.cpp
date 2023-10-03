class StockSpanner {
public:
    
    stack<pair<int, int>> st ; 
    int i= 0 ;
    
    StockSpanner() {
        
    }
    
    int next(int price) {
        while(!st.empty() && st.top().second <= price)
            st.pop() ; 
        
        int ans = st.empty() ? i+1 : i - st.top().first  ; 
        st.push({i , price}) ; 
        i++ ; 
        
        return ans ; 
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
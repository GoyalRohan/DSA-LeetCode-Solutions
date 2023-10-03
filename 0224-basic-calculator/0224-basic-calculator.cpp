class Solution {
public:
    int calculate(string s) {
        stack<int> st ; 
        int result = 0  , sign = 1 ,curno = 0 ; 
        
        for(int i=0 ; i<s.size() ; i++)
        {
            if(isdigit(s[i]))
                curno = curno*10 + (s[i] - '0') ; 
            else if(s[i] == '+')
            {
                result += sign * curno ; 
                curno = 0 ; 
                sign = 1 ; 
            }
            else if(s[i] == '-')
            {
                result += sign * curno ; 
                curno = 0 ; 
                sign = -1 ; 
            }
            else if(s[i] == '(')
            {
                st.push(result) ; 
                st.push(sign) ; 
                result = 0 ; 
                sign = 1 ; 
                curno = 0 ; 
            }
            else if(s[i] == ')')
            {
                result += sign*curno ; 
                curno = 0 ; 
                
                int sig = st.top() ; st.pop() ; 
                int prevres = st.top() ; st.pop() ;
                
                result = result*sig ; 
                result += prevres ;  
                
            }
        }
        
        result += sign * curno ; 
        
        return result ; 
    }
};
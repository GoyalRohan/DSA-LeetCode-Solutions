class Solution {
public:
    int calculate(string s) {
        stack<int> st ; 
        char curchar , operation = '+' ; 
        int curno = 0 ; 
        
        for(int i=0 ; i<s.size() ; i++)
        {
            curchar = s[i] ; 
            if(isdigit(s[i]))
            {
                curno = curno * 10 + (curchar - '0') ;
            }
            if(!isdigit(curchar) && !iswspace(curchar) || i==s.size()-1)
            {
                if(operation == '+')
                {
                    st.push(curno) ; 
                }
                else if(operation == '-')
                {
                    st.push(-curno) ; 
                }
                else if(operation == '*')
                {
                    int stacktop = st.top() ; 
                    st.pop(); 
                    st.push(curno * stacktop) ; 
                }
                else if(operation == '/')
                {
                    int stacktop = st.top() ; 
                    st.pop(); 
                    st.push(stacktop/curno) ; 
                }
                
                curno = 0 ; 
                operation = curchar ; 
            }
        }
        
        int result = 0 ; 
        while(!st.empty())
        {
            result += st.top() ; 
            st.pop() ; 
        }
        
        return result ; 
    }
};
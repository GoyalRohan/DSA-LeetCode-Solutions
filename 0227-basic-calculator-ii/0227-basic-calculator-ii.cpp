class Solution {
public:
    int calculate(string s) {
        // stack<int> st ;
        int lastno = 0 ; 
        int result = 0 ; 
        char curchar  ; 
        int curno = 0 ; 
        char operation = '+' ; 
        
        for(int i=0 ; i<s.size() ; i++)
        {
            curchar = s[i] ; 
            if(isdigit(curchar))
            {
                curno = curno*10 + (curchar - '0') ; 
            }
            
            if((!isdigit(curchar) && !iswspace(curchar)) || i==s.size()-1)
            {
                if(operation == '+' || operation == '-')
                {
                    result += lastno ; 
                    if(operation == '+')
                        lastno = curno ; 
                    else
                        lastno = -curno ; 
                }
   
                else if(operation == '*')
                {
                    lastno = lastno * curno ; 
                }
                else if(operation == '/')
                {
                    lastno = lastno / curno ; 
                }
                
                curno= 0 ; 
                operation = curchar ; 
            }
        }
        
        result = result + lastno ; 
        
        return result ; 
    }
};
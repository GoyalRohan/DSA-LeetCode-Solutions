class Solution {
public:
    int calculate(string s) {
        int result = 0 , lastno = 0 ; 
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
                if(operation == '+' || operation == '-')
                {
                    result += lastno ; 
                    operation == '+' ? lastno = curno : lastno = -curno ; 
                }
                else if(operation == '*')
                {
                    lastno = lastno*curno ; 
                }
                else if(operation == '/')
                {
                    lastno = lastno / curno ; 
                }
                
                curno = 0 ; 
                operation = curchar ; 
            }
        }
        
        result += lastno ; 
        return result ; 
    }
};
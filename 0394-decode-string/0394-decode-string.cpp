class Solution {
public:
    string decodeString(string s) {
        int n = s.size() , curnum = 0  ; 
        string curstring = "" ; 
        stack<string> st ; 
        
        for(int i=0 ; i<n ; i++)
        {
            if(s[i] == '[')
            {
                st.push(curstring) ; 
                st.push(to_string(curnum)) ; 
                curstring = "" ; 
                curnum = 0 ; 
            }
            
            else if(s[i] == ']')
            {
                int num = stoi(st.top()) ;
                st.pop() ; 
                string temp = st.top() ; 
                st.pop() ; 
                
                // curstring = temp + num*curstring ; 
                while(num-- > 0)
                    temp += curstring ; 
                
                curstring = temp ; 
            }
            
            else if(s[i] >= '0' && s[i] <= '9')
            {
                curnum = curnum*10 + s[i]-'0' ; 
            }
            else
                curstring += s[i] ; 
        }
        
        return curstring ; 
    }
};
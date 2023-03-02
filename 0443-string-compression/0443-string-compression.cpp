class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size() , i = 0 , ansIndex =0 ; 
        
        while(i < n )
        {
            int j = i+1 ; 
            while(j <n && chars[i] == chars[j])
            {
                j++ ; 
            }
            
            chars[ansIndex++] = chars[i] ; 
            
            int cnt = j-i ; 
            
            if(cnt > 1)
            {
                string count = to_string(j-i) ;
            
                for(auto ch : count)
                {
                     chars[ansIndex++] = ch ; 
                }
            }
            
            
            i = j ; 
            
        }
        
        return ansIndex ;
    }
};
class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1 , j = b.size() - 1 ;
        
        int carry = 0 ; 
        string ans = "" ; 
        int sum = 0 ; 
        
        while(i>=0 || j>=0)
        {
            sum = 0 ; 
            if(i>=0)
                sum += a[i--] - '0' ;
            
             
            if(j >=0)
                sum += b[j--] - '0' ; 
            sum += carry ; 
            
            
            int rem = sum % 2 ; 
            carry  = sum / 2 ; 
            
            // cout<<rem <<" "<<carry <<endl ; 
            
            ans += rem + '0' ; 
                
        }
        
        if(carry == 1)
            ans += '1' ; 
        
        reverse(ans.begin() , ans.end()) ; 
        
        return ans ; 
    }
};
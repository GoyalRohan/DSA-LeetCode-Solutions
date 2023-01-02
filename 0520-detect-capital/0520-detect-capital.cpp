class Solution {
public:
    bool detectCapitalUse(string word) {
        int small = 0 , capital = 0 ; 
        int n = word.size() ; 
        
        for(int i=0 ; i<word.size() ; i++)
        {
            if(word[i] >= 'A' && word[i] <= 'Z')
                capital++ ; 
            else
                small++ ; 
        }
        
        // cout<<capital<<" "<<small<<endl ; 
        
        if(capital == n || small == n)
        {
            // cout<<1<<endl ; 
            return true ; 
        }
            
        
        if(word[0] >= 'A' && word[0] <= 'Z' )
        {
           if(small == n-1)
                return true ;  
            else
                return false ; 
        }
            
        return false ; 
        
        
        
    }
};
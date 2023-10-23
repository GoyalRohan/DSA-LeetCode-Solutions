class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int maxi = 0 ; 
        int curfrog = 0 ; 
        int c = 0 , r = 0 , o = 0 , a = 0 , k = 0 ; 
        
        for(int i=0 ; i<croakOfFrogs.size() ; i++)
        {
            if(croakOfFrogs[i] == 'c')
            {
                c++ ; 
                curfrog++ ; 
                maxi= max(maxi, curfrog) ; 
            }
            if(croakOfFrogs[i] == 'r')
            {
                r++ ;  
            }
            if(croakOfFrogs[i] == 'o')
            {
                o++ ; 
            }
            if(croakOfFrogs[i] == 'a')
            {
                a++ ;  
            }
            if(croakOfFrogs[i] == 'k')
            {
                k++ ; 
                curfrog-- ;  
            }
            
            if(c<r || r<o || o<a || a<k)
                return -1 ; 
            
        }
        
        if(curfrog == 0 && c==r && r==o && o==a && a==k)
            return maxi ; 
        
        return -1 ; 
    }
};
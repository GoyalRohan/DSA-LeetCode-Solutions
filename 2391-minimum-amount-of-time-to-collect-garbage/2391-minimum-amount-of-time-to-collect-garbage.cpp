class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int cnt = 0 ; 
        int lastm = 0 , lastp = 0 , lastg = 0 ; 
        
        for(int i=0; i<garbage.size() ; i++)
        {
            for(auto c : garbage[i])
            {
                cnt++ ; 
                if(c== 'M')
                    lastm = i ; 
                else if(c== 'P')
                    lastp = i ; 
                else
                    lastg = i ;  
            }
        }
        
        for(int i=1 ; i<travel.size() ; i++)
            travel[i] += travel[i-1] ; 
        
        if(lastm > 0)
            cnt += travel[lastm - 1] ; 
        if(lastp > 0)
            cnt += travel[lastp - 1] ; 
        if(lastg > 0)
            cnt += travel[lastg - 1] ; 
        
        
        return cnt ; 
    }
};
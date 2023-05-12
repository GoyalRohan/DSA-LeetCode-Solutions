class Solution {
public:
    int beautySum(string s) {
        int n = s.size() , sum = 0; 
        
        for(int i=0 ; i<n-1 ; i++)
        {
            vector<int> count(26, 0) ; 
            
            for(int j=i ; j<n ; j++)
            {
                count[s[j]- 'a']++ ; 
                
                int mini = INT_MAX , maxi = INT_MIN ;
                for(int i=0 ; i<26 ; i++)
                {
                    if(count[i] != 0)
                    {
                        maxi = max(maxi, count[i]) ; 
                        mini = min(mini, count[i]) ; 
                    }
                }
                
                sum += maxi - mini ; 
            }
        }
        
        return sum ; 
    }
};
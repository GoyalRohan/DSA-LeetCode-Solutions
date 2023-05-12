class Solution {
public:
    int beautySum(string s) {
        int n = s.size() , sum = 0; 
        
        for(int i=0 ; i<n-1 ; i++)
        {
            unordered_map<char, int> mpp ; 
            mpp[s[i]]++ ; 
            
            for(int j=i+1 ; j<n ; j++)
            {
                mpp[s[j]]++ ; 
                
                int mini = INT_MAX , maxi = INT_MIN ;
                char maxchar , minchar ; 
                for(auto m : mpp)
                {
                    if(m.second > maxi)
                    {
                        maxi = m.second ; 
                        maxchar = m.first ; 
                    }
                    
                    if(m.second < mini)
                    {
                        mini = m.second ; 
                        minchar = m.first ; 
                    }
                    
                }
                
                sum += mpp[maxchar] - mpp[minchar] ; 
            }
        }
        
        return sum ; 
    }
};
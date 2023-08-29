class Solution {
public:
    int bestClosingTime(string customers) {
        
        // BRUTE APPROACH
//         int ans  = -1  , mini = INT_MAX ; 
//         int n = customers.size() ; 
        
//         for(int i=0 ; i<=n ; i++)
//         {
//             int penalty = 0 ; 
//             for(int j=0 ; j<n ; j++)
//             {
//                if(i>j)
//                {
//                    if(customers[j] == 'N')
//                        penalty++ ; 
//                }
//                else
//                {
//                    if(customers[j] == 'Y')
//                        penalty++ ; 
//                }
//             }
            
//             // cout<<i<<" , "<<penalty<<endl ; 
//             if(mini > penalty)
//             {
//                 mini = penalty ; 
//                 // cout<<penalty<<" , "<<i<<endl ; 
//                 ans = i ; 
//             }
//         }
        
//         return ans ; 
        
        // OPTIMIZED APPROACH
        
        int n = customers.size() ; 
        vector<int> prefix(n+1 , 0) , suffix(n, 0) ; 
        int penalty = 0 ; 
        
        for(int i=0 ; i<n ; i++)
        {
            if(customers[i] == 'N')
            {
                penalty++ ; 
                
            }
            prefix[i+1] = penalty ; 
        }
        
        penalty = 0 ; 
        
        for(int i=n-1 ; i>=0 ; i--)
        {
            if(customers[i] == 'Y')
            {
                penalty++ ; 
                
            }
            suffix[i] = penalty ; 
        }
        
        
//         for(int i=0 ; i<n ; i++)
//         {
//             cout<<prefix[i]<<" , "<<suffix[i]<<endl ;
//         }
        
        int mini = INT_MAX ;
        int ans = -1 ; 
        
        for(int i=0 ; i<n ; i++)
        {
            int sum = prefix[i] + suffix[i] ; 
            if(sum < mini)
            {
                mini = sum ; 
                ans = i ; 
            }
        }
        
        if(mini > prefix[n])
            ans = n ; 
        
        return ans ; 
    }
};
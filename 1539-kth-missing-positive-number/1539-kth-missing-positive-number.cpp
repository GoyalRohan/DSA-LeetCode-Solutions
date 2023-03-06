class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int no = 1 ; 
        
        for(int i=0 ; i<arr.size() ; i++ , no++ )
        {
            if(arr[i] != no)
            {
                k-- ; 
                if(k == 0)
                    return no ; 
                i-- ; 
            }
        }
        
        while(k > 0)
        {
            no++ ; k-- ; 
        }
            
        return no - 1 ; 
    }
};
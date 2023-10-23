class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size() ; 
        int m = arr2.size(); 
        
        vector<int> h(1001 , 0) ; 
        for(int i=0 ; i<n ; i++)
        {
            h[arr1[i]]++ ; 
        }
        
        // cout<<"Vsfvdv" ;
        
        int j= 0 ; 
        for(int i=0 ; i<m ; i++)
        {
            while(h[arr2[i]] > 0)
            {
                arr1[j++] = arr2[i] ; 
                h[arr2[i]]-- ;
            }
        }
        
        
        
        for(int i=0 ; i<=1000 ; i++)
        {
            while(h[i] > 0)
            {
                arr1[j++] = i ;
                h[i]-- ;
            }
        }
        
        return arr1 ; 
    }
};
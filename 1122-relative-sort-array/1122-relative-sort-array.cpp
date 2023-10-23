class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size() ; 
        int m = arr2.size(); 
        
        map<pair<int, int> , int> mpp ; 
        vector<int> temp , ans ; 
        
        for(int i=0 ; i<m ; i++)
        {
            mpp[{i, arr2[i]}] = 0 ;
        }
        
        for(int i=0 ; i<n ; i++)
        {
            bool flag = false ; 
            for(auto m : mpp)
            {
                if(m.first.second == arr1[i])
                {
                    mpp[{m.first.first , m.first.second}]++;
                    // m.second += 1 ; 
                    flag = true ; 
                    // cout<<"FSfs" ;
                    // cout<<m.first.second<<" : "<<m.second<<endl ; 
                    break ; 
                }
                   
            }
            if(flag == false)
                temp.push_back(arr1[i]) ; 
        }
        
        sort(temp.begin() ,temp.end()) ; 
        
        for(auto m : mpp)
        {
            int ele = m.first.second , freq = m.second ; 
            // cout<<ele<<" : "<<freq<<endl ; 
            while(freq > 0)
            {
                ans.push_back(ele) ;
                // cout<<"fvdvd" ; 
                freq-- ; 
            }
        }
        
        for(auto t: temp)
            ans.push_back(t) ; 
        
        return ans ; 
    }
};
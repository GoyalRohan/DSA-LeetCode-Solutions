class RangeFreqQuery {
public:
    unordered_map<int , vector<int>> mpp ; 
    
    RangeFreqQuery(vector<int>& arr) {
        for(int i=0 ; i<arr.size() ; i++)
            mpp[arr[i]].push_back(i) ; 
    }
    
    int query(int left, int right, int value) {
        if(mpp.find(value) == mpp.end())
            return 0 ; 
        
        auto &v = mpp[value] ; 
        int ind1 = lower_bound(v.begin() , v.end() , left) - v.begin(); 
        int ind2 = upper_bound(v.begin() , v.end() , right) - v.begin(); 
        
        return ind2 - ind1 ; 
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
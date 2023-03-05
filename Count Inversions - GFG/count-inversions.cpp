//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    void merge(int low, int mid, int high , long long &cnt , long long arr[] , long long temp[])
    {
        int i = low , j = mid+1 , k = low ; 
        while(i <= mid && j<=high)
        {
            if(arr[i] <= arr[j])
                temp[k++] = arr[i++] ; 
            else
            {
                temp[k++] = arr[j++] ; 
                cnt += mid - i +1 ; 
            }
        }
        
        while(i <= mid)
        {
            temp[k++] = arr[i++] ;
        }
        
        while(j <= high)
        {
            temp[k++] = arr[j++] ;
        }
        
        for(int i=low ; i<=high ; i++)
            arr[i] = temp[i] ; 
    }
    
    void mergeSort(int low, int high , long long &cnt , long long arr[] , long long temp[] , int N)
    {
        if(low < high)
        {
            int mid = (low + high)/2 ; 
            mergeSort(low , mid , cnt , arr , temp , N) ; 
            mergeSort(mid+1 , high , cnt , arr , temp , N) ;
            merge(low , mid , high , cnt , arr , temp) ; 
            
        }
    }
    
    
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long cnt = 0 , temp[N] ; 
        
        mergeSort(0 , N-1 , cnt , arr , temp ,N) ; 
        return cnt ; 
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends
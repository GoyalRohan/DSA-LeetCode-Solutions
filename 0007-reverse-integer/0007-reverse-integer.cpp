class Solution {
public:
    int reverse(int x) {
        // cout<<"sfs" ; 
        long int ans=0;
    

       while(x>=1 || x<=-1 )
       {    
           ans=ans*10+(x%10);
           x=x/10;
       }
       if(ans>INT_MAX || ans<INT_MIN) return 0;
       return int(ans);
    }
};
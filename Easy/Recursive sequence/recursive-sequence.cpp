//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    long long sequence(int n){
        int c=1;
        long long ans=0;
        int mode=1e9+7;
        
        for(int i=1;i<=n;i++){
            int t=i;
            long long temp=1;
            while(t--){
                temp=(temp*c)%mode;
                c++;
                
            }
            ans=(ans+temp)%mode;
            
        }    
        return(ans);    
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends
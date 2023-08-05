//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int solve(int n,vector<int>&dp){
        int count=0;
        if(dp[n]!=-1)return dp[n];
        if(n==0 || n==1){
            return 1;
        }
        else {
            for(int i=1;i<=n;i++){
                count+=solve(i-1,dp)*solve(n-i,dp);
            }
        }

        return dp[n]=count;
    }
    //Function to return the total number of possible unique BST. 
    int numTrees(int N) 
    {
        //Memoization is not working here 
        const int mod=1e9+7;
        vector<long long>dp(N+1,0);
        dp[0]=1;
        dp[1]=1;
        
        for(int i=2;i<=N;i++){
            for(int j=1;j<=i;j++){
                dp[i]=(dp[i]+((dp[j-1]%mod)*(dp[i-j]%mod))%mod)%mod;  //catalan numbers f4=f0f3+f1f2+f2f1+f3f0;
            }
        }
        return dp[N]%mod;
    }
};

//{ Driver Code Starts.
#define mod (int)(1e9+7)
int main(){
    
    //taking total testcases
    int t;
    cin>>t;
    while(t--){
        
        //taking total number of elements
        int n;
        cin>>n;
        Solution ob;
        //calling function numTrees()
        cout<<ob.numTrees(n)<<"\n";
    }
}	
// } Driver Code Ends
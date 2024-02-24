//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
        int solve(vector<int>&dp,int n)
        {
            //Base case
            if(n==0|| n==1||n==2){
                return n;//whatever is n
            }
            
            //If sum upto n already calculated 
            if(dp[n]!=-1)return dp[n];
            
            int sum=solve(dp,n/2)+solve(dp,n/3)+solve(dp,n/4);
            
            return dp[n]=max(n,sum);
            
        }
        int maxSum(int n)
        {
            //Referred solution , but Fully understood and Drawn recursive tree too
            vector<int>dp(n+1,-1);
            return solve(dp,n);
        }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.maxSum(n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
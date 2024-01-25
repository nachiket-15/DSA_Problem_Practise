//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int cnt=0;
    int solve(int ind,int sum,vector<int>&arr,vector<vector<int>>&dp)
    {
        //Base case
        if(ind==arr.size())
        {
            if(sum==0)
            {
                cnt++;
            }
            return 0;
        }
        
        if(dp[sum][ind]!=-1)
        {
            return dp[sum][ind];
        }
        //take 
        if(arr[ind]<=sum){
            dp[sum][ind]+=solve(ind+1,sum-arr[ind],arr,dp);
        }
        //not take        
        dp[sum][ind]+=solve(ind+1,sum,arr,dp);
        
        return dp[sum][ind];
    }
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
    
        vector<vector<int>>dp(k+1,vector<int>(n+1,-1));
       
        int b=solve(0,k,arr,dp);
    
        return cnt;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            int x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        bool ans = obj.checkSubsequenceSum(n, arr, k);
        cout<<( ans ? "Yes" : "No")<<"\n";
    }
    return 0;
}
// } Driver Code Ends
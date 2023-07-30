//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int ind,int wt,int profit[],int weight[],vector<vector<int>>&dp)
    {
        //base case
        if(ind==0){
            return (wt/weight[0])*profit[0];
        }
        if(dp[ind][wt]!=-1){
            return dp[ind][wt];
        }
    
        int notTake=solve(ind-1,wt,profit,weight,dp);
        int take=-1e9;
        if(weight[ind]<=wt){
            take=profit[ind]+solve(ind,wt-weight[ind],profit,weight,dp);
        }
            return dp[ind][wt]=max(take,notTake);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        
        vector<vector<int>>dp(N,vector<int>(W+1,-1));
        return solve(N-1,W,val,wt,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends
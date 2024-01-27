//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    int func(vector<int>&cost,vector<int>&dp,int N)
    {
        if(N==0 || N==1)
        {
            return 0;
        }
        
        if(dp[N]!=-1)return dp[N];
        
        int oneStep=func(cost,dp,N-1)+cost[N-1];
        
        int twoStep=INT_MAX;
        if(N>1){
            twoStep=func(cost,dp,N-2)+cost[N-2];
        }
        
        return dp[N]=min(oneStep,twoStep);
        
    }
    int minCostClimbingStairs(vector<int>&cost ,int N) {
        //We will go top to down
        vector<int>dp(N+1,-1);
        return func(cost,dp,N);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>cost(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>cost[i];
        }

        Solution ob;
        cout<<ob.minCostClimbingStairs(cost,N);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
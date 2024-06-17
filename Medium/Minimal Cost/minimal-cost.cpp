//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(int index,vector<int>&dp,vector<int>&height,int k){
        //Base case
        dp[0]=0;
        //Memoization
        if(dp[index]!=-1){
            return dp[index];
        }
    
        int minSteps=INT_MAX;
        int jumps;
        for(int i=1;i<=k;i++){
            if(index-i>=0){
                jumps=solve(index-i,dp,height,k)+abs(height[index]-height[index-i]);
            }
            minSteps=min(jumps,minSteps);
        }
    
        return dp[index]=minSteps;
    }
    int minimizeCost(vector<int>& height, int n, int k) {
        // vector<int>dp(n,-1);
        // return solve(n-1,dp,height,k);
        
        //tabulation
        vector<int>dp(n,1e9);
        
        //cost to reach first position is 0
        dp[0]=0;
        
        for(int ind=1;ind<n;ind++)
        {
            int min_cost=1e9;
            
            for(int step=1;step<=k;step++)
            {
                if(ind-step>=0)
                {
                    min_cost=min(min_cost,dp[ind-step]+abs(height[ind]-height[ind-step]));
                }
            }
            dp[ind]=min_cost;
        }
        
        return dp[n-1];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends
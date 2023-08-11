//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
     //Memoization sol
     // This solution not working here due to long long
    long long int solve(int index,int target,int coins[],vector<vector<long long int>>&dp){
        //Base index
        if(index==0){
            if(target%coins[0]==0)return 1;
            return 0;
        }
        //Memoization
        if(dp[index][target]!=-1){
            return dp[index][target];
        }

        long long int notTake=solve(index-1,target,coins,dp);
        long long int take=0;
        if(coins[index]<=target)
        {
            take=solve(index,target-coins[index],coins,dp);
        }

        return dp[index][target]=take+notTake;
    }
    
    long long int count(int coins[], int N, int sum) {

        vector<vector<long long int>>dp(N,vector<long long int>(sum+1,-1));
        return solve(N-1,sum,coins,dp);
        
        /*
        //Base case
        for(int target=0;target<=amount;target++){
            dp[0][target]=(int)(target%coins[0]==0);
        }

        for(int index=1;index<n;index++){
            for(int T=0;T<=amount;T++){

                long long int notTake=dp[index-1][T];
                long long int take=0;
                if(coins[index]<=T)
                {
                    take=dp[index][T-coins[index]];
                }

                dp[index][T]=take+notTake;
            }
        }
        return dp[n-1][amount];
        */
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends
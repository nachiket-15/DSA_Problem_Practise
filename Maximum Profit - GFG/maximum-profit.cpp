//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    //Memoization approach
    int solve(int ind,int buy,int cap,int prices[],int n,vector<vector<vector<int>>>&dp)
    {
        if(ind==n ||cap==0)return 0;
        if(dp[ind][buy][cap]!=-1)return dp[ind][buy][cap];
        if(buy==1){
            //buy or not buy
            return dp[ind][buy][cap]=max(-prices[ind]+solve(ind+1,0,cap,prices,n,dp),0+solve(ind+1,1,cap,prices,n,dp));
        }
        //Sell now or not
        return dp[ind][buy][cap]=max(prices[ind]+solve(ind+1,1,cap-1,prices,n,dp),0+solve(ind+1,0,cap,prices,n,dp));
    }
    int maxProfit(int K, int N, int prices[]) {
        /* Memoization stuff:-
        vector<vector<vector<int>>>dp(N,vector<vector<int>>(2,vector<int>(K+1,-1)));
        return solve(0,1,K,A,N,dp);
        */
        
        
        //Tabulation approach
        
        //Base case:
        //tabulatiuon solution
        int buy=1;
        int cap=K;
        vector<vector<vector<int>>>dp(N+1,vector<vector<int>>(2,vector<int>(K+1,0)));
        //DP initialiled with zero so no need of base case
        for(int ind=N-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=K;cap++){
                    if(buy==1){
                        //buy or not buy
                        dp[ind][buy][cap]=max(-prices[ind]+dp[ind+1][0][cap]
                        ,dp[ind+1][1][cap]);
                    }
                    else dp[ind][buy][cap]=max(prices[ind]+dp[ind+1][1][cap-1]
                    ,dp[ind+1][0][cap]);
                }
            }
        }
        return dp[0][1][K];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends
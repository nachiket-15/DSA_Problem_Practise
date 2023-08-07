//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long f(long long ind,long long buy,vector<long long>& prices,vector<vector<long long>> &dp)
    {
        if(ind >= prices.size()) return 0;
        
        if(dp[ind][buy] != -1) return dp[ind][buy];

        
        if(buy)
        {
            return dp[ind][buy]=max(-prices[ind]+ f(ind + 1,0,prices,dp),0 + f(ind + 1,1,prices,dp));
        }
        
        return dp[ind][buy]=max(prices[ind]+ f(ind + 2,1,prices,dp),0 + f(ind+1,0,prices,dp));
        
    }
    long long maximumProfit(vector<long long>&price, int n) {
        //Memoization gives TLE ,  tabulation works
        vector<vector<long long int>> dp(n + 2, vector<long long int>(2, 0));

        // no need to write base case
    
        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                // buy
                if (buy == 1)
                    dp[ind][buy] = max(-price[ind] + dp[ind + 1][0],
                                       0 + dp[ind + 1][1]);
    
                // sell,
                // can not buy right after sell, that why +2
                else
                    dp[ind][buy] = max(price[ind] + dp[ind + 2][1],
                                       0 + dp[ind + 1][0]);
            }
        }
    
        return dp[0][1];
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> prices;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            prices.push_back(x);
        }
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
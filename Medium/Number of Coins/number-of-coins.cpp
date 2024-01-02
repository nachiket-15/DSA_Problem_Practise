//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int minCoins(vector<int> &coins, int M, int V) 
	{ 
	    // lets try tabulation approach on memoization solution
	    
	    vector<vector<int>>dp(M,vector<int>(V+1,0));
	    //Base case
	    //When u are at last index , check whether target is still achiveable
	    for(int target=0;target<=V;target++)
	    {
	        if(target%coins[0]==0){
	            dp[0][target]=(target/coins[0]);
	        }else{
	            dp[0][target]=1e9;
	        }
	    }
	    
	    for(int ind=1;ind<M;ind++)
	    {
	        for(int target=0;target<=V;target++)
	        {
	            int not_take=dp[ind-1][target];
	            int take=1e9;
	            if(coins[ind]<=target){
	                take=1+dp[ind][target-coins[ind]];
	            }
	            
	            dp[ind][target]=min(take,not_take);
	        }
	    }
	    
	    int ans=dp[M-1][V];
	    if(ans>=1e9)return -1;
	    
	    return ans;
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        vector<int> coins(m);
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends
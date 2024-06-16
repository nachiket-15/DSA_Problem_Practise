//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int f(int ind,vector<int>&height,vector<int>&dp)
    {
        //base case
        if(ind==0)
        {
            return 0;
        }
        if(dp[ind]!=-1)
        {
            return dp[ind];
        }
        int jmpOne=f(ind-1,height,dp)+abs(height[ind]-height[ind-1]);
        int jmpTwo=1e9;
        
        if(ind>1)
        {
            jmpTwo=f(ind-2,height,dp)+abs(height[ind]-height[ind-2]);
        }
        
        return dp[ind]=min(jmpOne,jmpTwo);
    }
    int minimumEnergy(vector<int>& height, int n) {
        /* 
        memoization approach
        
        vector<int>dp(n,-1);
        return f(n-1,height,dp);
        */
        
        vector<int>dp(n,0);
        dp[0]=0;
        
        for(int ind=1;ind<n;ind++)
        {
            int jmpOne=dp[ind-1]+abs(height[ind]-height[ind-1]);
            int jmpTwo=1e9;
            
            if(ind>1)
            {
                jmpTwo=dp[ind-2]+abs(height[ind]-height[ind-2]);
            }
            dp[ind]=min(jmpOne,jmpTwo);
        }
        
        return dp[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends
class Solution {
public:
    int solve(int n,vector<int>&dp){
        int count=0;
        if(dp[n]!=-1)return dp[n];
        if(n==0 || n==1){
            return 1;
        }
        else {
            for(int i=1;i<=n;i++){
                count+=solve(i-1,dp)*solve(n-i,dp);
            }
        }

        return dp[n]=count;
    }
    int numTrees(int n) {
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};
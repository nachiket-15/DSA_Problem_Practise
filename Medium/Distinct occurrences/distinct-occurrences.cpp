//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
    //Memoization solution
    int solve(int i,int j,string &s,string &t,vector<vector<int>>&dp){
        //Base case : If ref words iterator finishes
        
        //choti string sampli
        if(j<0)return 1;
        //mothi string sampli
        if(i<0)return 0;

        if(dp[i][j]!=-1)return dp[i][j];

        if(s[i]==t[j]){
            //equal astil tr donhi possibility consider kara
            return dp[i][j]=solve(i-1,j-1,s,t,dp)+solve(i-1,j,s,t,dp);
        }
        //equal nastil mothi string vrti iterate karun pudhe ja (i.e.mage)
        return dp[i][j]=solve(i-1,j,s,t,dp);
    }
    
    public:
    int mod=1e9+7;
    int subsequenceCount(string S, string T)
    {
        int n=S.size();
        int m=T.size();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        for(int i=0;i<=n;i++)dp[i][0]=1;
        // for(int j=0;j<=m;j++)dp[0][j]=0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                
                if(S[i-1]==T[j-1]){
                    dp[i][j]=dp[i-1][j-1]%mod+dp[i-1][j]%mod;
                }
                
                else
                    dp[i][j]=dp[i-1][j]%mod;
            }
        }
        return dp[n][m]%mod;
    }
};
 




//{ Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}
// } Driver Code Ends
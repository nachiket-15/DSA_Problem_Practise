//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int lcs(string s, string t)
    {
        int n=s.length();
        int m=t.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
	   //Tabulation
	   //Base case
	   for(int i=0;i<=n;i++)dp[i][0]=0;
	   for(int j=0;j<=m;j++)dp[0][j]=0;
	   
	   //
	   for(int i=1;i<=n;i++){
	       for(int j=1;j<=m;j++){
	            if(s[i-1]==t[j-1]){
    		        dp[i][j]= 1+dp[i-1][j-1];
    	        }
    	        else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
	       }
	   }
	   return dp[n][m];
	   
    }
	int minOperations(string str1, string str2) 
	{ 
	    
	    return str1.length()-lcs(str1,str2)+str2.length()-lcs(str1,str2);
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends
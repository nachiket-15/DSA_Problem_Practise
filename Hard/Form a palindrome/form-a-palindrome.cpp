//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

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
    int longestPalinSubseq(string s) {
        //We know how tom find longest common subsequence 
        //We for palindrome we reverse string 
        //them we find lcs for both string 
        string t=s;
        reverse(t.begin(),t.end());
        return lcs(s,t);
    }
    int countMin(string str){
    
        //minimun insertions required are nothing but 
        //string length - longest palindromic subsequence
        //as LPS is already a palindrome , we just need remaining non pal characters count
        int lps_len=longestPalinSubseq(str);
        return str.length()-lps_len;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends
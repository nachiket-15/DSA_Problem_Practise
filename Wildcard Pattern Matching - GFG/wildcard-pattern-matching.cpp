//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    //Memoization solution on 0 based indexing
    int solve(int i,int j,string pattern,string text,vector<vector<int>>&dp){
    //If both of them are exhausted , return true
        if(i<0 && j<0)return true;
        //If pattern is exhausted and text remains
        if(i<0 && j>=0)return false;
        //If text is exhausted and pattersn lefts
        if(j<0 && i>=0){
            for(int ii=0;ii<=i;ii++){
                if(pattern[ii]!='*')return false;
            }
            return true;
        };
    
        if(dp[i][j]!=-1)return dp[i][j];
        
        if(pattern[i]==text[j]||pattern[i]=='?'){
            return dp[i][j]=solve(i-1,j-1,pattern,text,dp);
        }
        if(pattern[i]=='*'){
            return dp[i][j]=solve(i-1,j,pattern,text,dp)||solve(i,j-1,pattern,text,dp);
        }
        return dp[i][j]=false;
    }
/*You are required to complete this method*/
    int wildCard(string pattern,string str)
    {
        int n=pattern.size();
        int m=str.size();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        //Tabulation method (1 based indexing)
        
        //Base case
        dp[0][0]=1;
        for(int j=1;j<=m;j++){
            dp[0][j]=0;
        }
        for(int i=1;i<=n;i++){
            int flag=1;
            for(int ii=1;ii<=i;ii++){
                if(pattern[ii-1]!='*'){
                    flag=0;
                    break;
                }
            }
            dp[i][0]=flag;
        }
        
        //For changing parameters
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                
                if(pattern[i-1]==str[j-1]||pattern[i-1]=='?'){
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(pattern[i-1]=='*'){
                    dp[i][j]=dp[i-1][j] || dp[i][j-1];
                }
                else dp[i][j]=false;
            }
        }
        return dp[n][m];
        
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends
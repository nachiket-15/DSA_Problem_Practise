//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int solve(string &str,int idx,int prevSum,vector<vector<int>>&dp)
	{
	    //Base case
	    if(idx==str.size())return 1;
	    //Memoization step
	    if(dp[idx][prevSum]!=-1)return dp[idx][prevSum];
	    
	    //ans and sum vars 
	    int ans=0;
	    int sum=0;
	    
	    //Iterate over string from idx till end
	    for(int i=idx;i<str.size();i++)
	    {
	        //Calculate the sum of numbers remaining in string
	        sum+=(str[i]-'0');
	        
	        //If this sum is greater than prevSum
	        if(sum>=prevSum)
	        {
	            ans+=solve(str,i+1,sum,dp);
	            //Add up the count return by recursive solve function into ans variable
	        }
	    }
	    
	    return dp[idx][prevSum]=ans;
	}
	int TotalCount(string str){
	    int n=str.size();
	    //dp to store no of string groups where sum is greater than its previous string group
	    vector<vector<int>>dp(n,vector<int>(1000,-1));
	    
	    return solve(str,0,0,dp);
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.TotalCount(str);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
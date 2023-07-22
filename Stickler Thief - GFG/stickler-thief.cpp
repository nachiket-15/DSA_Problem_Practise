//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    int solve(vector<int>&dp,int n,int*arr){
        dp[0]=arr[0];
        
        for(int i=1;i<n;i++){
            int pick=arr[i];
            if(i>1)pick+=dp[i-2];
            int nonpick=dp[i-1];
            dp[i]=max(pick,nonpick);
        }
        return dp[n-1];
    }
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
       //tabulation solution
	    vector<int>dp(n,-1);
	    return solve(dp,n,arr);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 
int maxSumBS(int arr[] , int n );

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		
		cout<<maxSumBS(a,n)<<endl;
		
	}
}
// } Driver Code Ends


int maxSumBS(int arr[] , int n )
{
    vector<int>dp1(n);
    vector<int>dp2(n);
    
    
    for(int i=0;i<n;i++)
    {
        int maxSum=0;
        for(int prev=0;prev<i;prev++)
        {
            if(arr[prev]<arr[i])
            {
                maxSum=max(dp1[prev],maxSum);
            }
        }
        dp1[i]=arr[i]+maxSum;
    }
    
    
    for(int i=n-1;i>=0;i--)
    {
        int maxSum=0;
        for(int prev=n-1;prev>i;prev--)
        {
            if(arr[prev]<arr[i])
            {
                maxSum=max(dp2[prev],maxSum);
            }
        }
        dp2[i]=arr[i]+maxSum;
    }
    
    int ans=0;
    for(int i=0;i<n;i++)ans=max(ans,dp1[i]+dp2[i]-arr[i]);
    
    
    return ans;
}

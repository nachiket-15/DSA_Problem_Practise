//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    /*
    MEMOIZATION
    
int longestIncreasingSubsequenceHelper(int arr[], int prevPosition, int curPosition, int n, int **dp)
{
   
    // Base case.
    if (curPosition == n)
    {
        return 0;
    }
    
    // Already computed.
    if (dp[prevPosition + 1][curPosition] >= 0)
    {
        return dp[prevPosition + 1][curPosition];
    }

    int taken = 0;

    // Taking the current element.
    if (prevPosition < 0 || arr[curPosition] > arr[prevPosition])
    {
        taken = 1 + longestIncreasingSubsequenceHelper(arr, curPosition, curPosition + 1, n, dp);
    }

    // Not Taking the current element.
    int notTaken = longestIncreasingSubsequenceHelper(arr, prevPosition, curPosition + 1, n, dp);
    dp[prevPosition + 1][curPosition] = max(taken, notTaken);
    return dp[prevPosition + 1][curPosition];
}
    TABULATION
    int longestIncreasingSubsequence(int arr[], int n)
{
    // dp[i] represents i+1'th length LIS ending at minimum integer dp[i]
    int dp[n]; 

    // Base case
    dp[0] = 1;

    int ans = 1;

    for (int i = 1; i < n; i++)
    {
        int maxval = 0;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                maxval = max(maxval, dp[j]);
            }
        }
        dp[i] = maxval + 1;
        ans = max(ans, dp[i]);
    }
    return ans;
}
    
    */
    int longestSubsequence(int n, int a[])
    {
        //Solution using binary search
        vector<int>v;
        v.push_back(a[0]);
       
       for(int i=1;i<n;i++){
           if(a[i]<=v.back()){
               int index=lower_bound(v.begin(),v.end(),a[i])-v.begin();
               v[index]=a[i];
           }
           else{
               v.push_back(a[i]);
           }
       }
       
       return v.size();
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends
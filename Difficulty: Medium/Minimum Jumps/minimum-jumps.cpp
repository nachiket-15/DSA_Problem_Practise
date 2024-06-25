//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n)
    {
        int jumps=0;
        int left=0;
        int right=0;
        int farthest=0;
        
        while(right<n-1)
        {
            farthest=0;
            for(int ind=left;ind<=right;ind++)
            {
                farthest=max(ind+arr[ind],farthest);
            }
            // If we can't move forward, return -1
            if (farthest == right) return -1;
            
            left=right+1;
            right=farthest;
            jumps=jumps+1;
        }
        return jumps;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends
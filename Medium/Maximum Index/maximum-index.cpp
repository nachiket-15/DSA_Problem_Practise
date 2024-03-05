//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int a[], int n) 
    { 
        //done by me , correct , but gives TLE
        // int maxDiff=0;
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=i;j<n;j++)
        //     {
        //         if(a[i]<=a[j])
        //         {
        //             maxDiff=max(j-i,maxDiff);
        //         }
        //     }
        // }
        
        // return maxDiff;
        
        int ans = 0;
        
        for(int i=0; i<n; i++){
            int j=n-1;
            
            while(j>=i && a[j]<a[i]){
                j--;
            }
            ans = max(ans,j-i);
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends
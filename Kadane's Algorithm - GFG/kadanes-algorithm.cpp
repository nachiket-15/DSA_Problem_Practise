//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    
    long long maxSubarraySum(int arr[], int n){
        /*
        // Naive approach : Generate all subarrays and compare sums
        long long maxi = -1e9;
    
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                vector<int> v;
                for(int k = i; k <= j; k++){
                    v.push_back(arr[k]);
                }
    
                long long sum = accumulate(v.begin(), v.end(), 0);
                if(sum > maxi) maxi = sum;
            }
        }
        return maxi;
        */
        
        //Kadane algorithm:
        
        long long maxEndingHere=arr[0];
        long long maxSoFar=arr[0];
        
        for(int i=1;i<n;i++){
            maxEndingHere=max((long long) arr[i],maxEndingHere+arr[i]);
            maxSoFar=max(maxEndingHere,maxSoFar);
        }
        
        return maxSoFar;
    }
};

//{ Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	
	public:
	long long countTriplets(long long arr[], int n, long long sum)
	{
	    // Solution Referred , but i know this pattern of 2/3 ptrs
	    
	    sort(arr,arr+n);
	    long long cnt=0;
	    
	    for(int k=0;k<n-2;k++)
	    {
	        int i=k+1;
	        int j=n-1;
	        
	        while(j>i)
	        {
	            long long currSum=arr[k]+arr[i]+arr[j];
	            
	            if(currSum < sum)
	            {
	                cnt+=(j-i);
	                i++;
	            }
	            else
	            {
	                j--;    
	            }
	        }
	    }
	    
	    return cnt;
	}
		 

};

//{ Driver Code Starts.

int main() 
{
  
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
    	long long sum;
        cin>>n>>sum;
        long long arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
	    

       

        Solution ob;
        cout << ob.countTriplets(arr, n, sum) ;
	   
        
	    cout << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends
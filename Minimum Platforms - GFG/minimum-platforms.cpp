//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        //check submission one for explanation
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	
    	int res=1;
    	int count=1;
    	
    	int i=1;
    	int j=0;
    	
    	while(i<n && j<n)
    	{
    	    //if next train arrives before earlier one leaves
    	    if(arr[i]<=dep[j]){
    	        i++;
    	        count++;
    	    }
    	    
    	    else{
    	        j++;
    	        count--;
    	    }
    	    res=max(count,res);
    	}
    	
    	return res;
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends
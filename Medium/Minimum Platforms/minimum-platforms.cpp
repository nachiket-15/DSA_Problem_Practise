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
    	//Sort arrival & departure times
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	
    	//Initialize count and ans variables
    	int ans=1,count=1;
    	
    	//Use i for arrival array & j for departure array
    	int i=1,j=0;
    	
    	//Iterate over loop , Use condition 
    	while(i<n && j<n){
    	    //If arrival of next train is before departure 
    	    if(arr[i]<=dep[j]){
    	        count++;
    	        i++;
    	    }
    	    //Else no new platform is required and you may reduce no of platforms 
    	    else{
    	        count--;
    	        j++;
    	    }
    	    ans=max(ans,count);
    	}
    	return ans;
    	
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
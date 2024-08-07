//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    
    	//Tabulation approach
    	int totalSum=0;
    	for(int i=0;i<n;i++)totalSum+=arr[i];
    	int k=totalSum;
	
    	vector<vector<bool>>dp(n,vector<bool>(k+1,0));
    	
    	//Base case 1 - If target becomes zero
    	for(int i=0;i<n;i++){
    		dp[i][0]=true;
    	}
	
    	//Second Base case - index is 0 and 
    	if(arr[0]<=k){
    		dp[0][arr[0]]=true;
    	}

    	//Iterate for remaining 
    	for(int ind=1;ind<n;ind++){
    		for(int target=1;target<=k;target++){
    			
    			bool notTake=dp[ind-1][target];
    			
    			bool take=false;
    			if(arr[ind]<=target){
    				take=dp[ind-1][target-arr[ind]];
    			}
                //Perform Logical OR Operation of both 
    			dp[ind][target]=take || notTake;
    		}
    	}
        
    	int diff=1e9;
    
    	for(int s1=0;s1<=k/2;s1++){
    		if(dp[n-1][s1]==true){
    			diff=min(diff,abs((k-s1)-s1));
    		}
    	}
    	
    	return diff;

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
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends
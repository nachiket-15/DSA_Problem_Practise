//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int NthRoot(int n, int m)
	{
	    //This is naive approach - though it works due to pow function
	    
	    /*
	    if(m==1){
	        return 1;
	    }
	    for(int i=2;i<=m;i++){
	        if(pow(i,n)==m){
	            return i;
	        }
	        else if(pow(i,n)>m)
	            break;
	    }
	    
	    return -1;
	    */
	    
	    int low=1;
	    int high=m;
	    while(low<=high){
	        int mid=low+(high-low)/2;
	        
	        if(pow(mid,n)==m){
	            return mid;
	        }
	        else if(pow(mid,n)>m){
	            high=mid-1;
	        }
	        else if(pow(mid,n)<m){
	            low=mid+1;
	        }
	    }
	    return -1;
	}  
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends
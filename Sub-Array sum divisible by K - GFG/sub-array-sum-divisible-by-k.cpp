//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	long long subCount(long long arr[], int N, long long K)
	{
	    unordered_map<int,int>map;
	    int sum=0;
	    int rem=0;
	    int ans=0;
	    //As zero sum is divisble by K
	    map[0]=1;
	    
	    for(int i=0;i<N;i++){
	        sum+=arr[i];
	        rem=sum%K;
	        if(rem < 0){
	            rem+=K;
	        }
	        if(map.find(rem)!=map.end()){
	            ans+=map[rem];
	            map[rem]++;
	        }
	        else{
	            map[rem]=1;
	        }
	    }
	    return ans;
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
       	long long k;
		cin>>n >> k;
		long long a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
        

        Solution ob;
        cout << ob.subCount(a, n, k);
	    cout << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends
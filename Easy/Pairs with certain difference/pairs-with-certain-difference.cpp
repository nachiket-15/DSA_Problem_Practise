//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int maxSumPairWithDifferenceLessThanK(int arr[], int n, int k)
    {
        // Solution referred
        sort(arr,arr+n,greater<int>());
        vector<int>vis(n,0);
        int ans =0;
        
        for(int i=0;i<n-1;i++){
            if(vis[i]==1){
               
                continue;
            }
            else{
                if(abs(arr[i]-arr[i+1])<k)
                {
                    ans+=(arr[i]+arr[i+1]);
                    vis[i]=1;
                    vis[i+1]=1;
                    
                }
           
            }
        }
        return ans ;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		cin>>N;
		int arr[N];
		for(int i=0;i<N;i++)
		cin>>arr[i];

		int K;
		cin>>K;
        Solution ob;
		cout<<ob.maxSumPairWithDifferenceLessThanK(arr,N,K)<<endl;
	}
	return 0;
}

// } Driver Code Ends
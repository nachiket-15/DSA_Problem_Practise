//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        //After 4 months i was able to do this on my own 
        int sum=0;
        int len=0;
        unordered_map<int,int>mp;//sum,index
        
        for(int i=0;i<N;i++){
            sum+=A[i];
            if(sum==K){
                len=i+1;
            }
            if(mp.find(sum)==mp.end()){
                mp[sum]=i;
            }
            if(mp.find(sum-K)!=mp.end()){
                if(len<i-mp[sum-K]){
                    len=i-mp[sum-K];
                }
            }
        }
        return len;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        /*
        Solution 1 - TC = O(N^2) 
        int maxLen=0;
        for(int i=0;i<N;i++){
            int sum=0;
            for(int j=i;j<N;j++){
                sum+=A[j];
                
                if(sum==K){
                    maxLen=max(maxLen,j-i+1);
                }
            }
        }
        
        return maxLen;
        */
        
        //Solution 2 
        unordered_map<int,int>um;//<sum,index>
        int maxLen=0;
        int sum=0;
        
        for(int i=0;i<N;i++){
            sum+=A[i];
            
            if(sum==K){
                maxLen=i+1;
            }
            
            if(um.find(sum)==um.end()){
                um[sum]=i;
            }
            
            if(um.find(sum-K)!=um.end()){
                if(maxLen<(i-um[sum-K])){
                    maxLen=i-um[sum-K];
                }
            }
        }
        return maxLen;
        
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
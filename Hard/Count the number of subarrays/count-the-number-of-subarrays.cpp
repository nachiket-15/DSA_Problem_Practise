//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    long long atMostKsum(vector<int>&nums,long long k)
    {
        int n=nums.size();
        int i=0;
        
        long long sum=0;
        long long ans=0;
        
        for(int j=0;j<n;j++)
        {
            //kaam 
            sum=sum+nums[j];
            //violating condition & upay
            while(sum>k)
            {
                sum=sum-nums[i];
                i++;
            }
            ans+=j-i+1;
        }
        return ans;
    }
    long long countSubarray(int N,vector<int> A,long long L,long long R) {
        return atMostKsum(A,R)-atMostKsum(A,L-1);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        long long L,R;
        cin>>N>>L>>R;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution obj;
        auto ans = obj.countSubarray(N,A,L,R);
        cout<<ans<<endl;
    }
}  
// } Driver Code Ends
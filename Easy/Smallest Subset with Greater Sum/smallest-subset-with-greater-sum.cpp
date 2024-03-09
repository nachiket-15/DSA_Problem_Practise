//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int minSubset(vector<int> &Arr,int N){
        
        sort(begin(Arr),end(Arr));
        
        int cnt=0;
        long totalSum=0;
        for(int n:Arr)totalSum+=n;
        
        long currSum=0;
        
        for(int i=N-1;i>=0;i--)
        {
            currSum+=Arr[i];
            totalSum-=Arr[i];
            cnt++;
            if(currSum>totalSum)return cnt;
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> Arr(N);
        for(int i=0;i<N;i++){
            cin>>Arr[i];
        }
        Solution ob;
        cout<<ob.minSubset(Arr,N)<<endl;
    }
    return 0;
}
// } Driver Code Ends
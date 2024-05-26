//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int findSubArraySum(int Arr[], int N, int k)
    {
        int preSum=0,cnt=0;
        map<int,int>map;
        
        map[0]=1;
        
        for(int i=0;i<N;i++){
            preSum+=Arr[i];
            
            int toBeRemoved=(preSum-k);
            cnt+=map[toBeRemoved];
            
            map[preSum]+=1;
        }
        
        return cnt;
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.findSubArraySum(Arr, N, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends
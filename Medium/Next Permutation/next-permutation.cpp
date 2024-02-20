//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        //Start travelling from end
        
        //Check for first index which breaks pattern from increasing to decreasing 
        int idx=-1;
        
        for(int i=(N-2);i>=0;i--){
            if(arr[i] < arr[i+1]){
                idx=i;
                break;
            }
        }
        if(idx==-1){
            reverse(arr.begin(),arr.end());
            return arr;
        }
        //Again start travelling from end and this time search for first element which is greater than previously found element 
        //After finding such an element , swap the two 
        for(int i=(N-1);i>=0;i--){
            if(arr[i]>arr[idx]){
                swap(arr[i],arr[idx]);
                break;
            }
        }
        
        reverse(arr.begin()+idx+1,arr.end());
        return arr;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
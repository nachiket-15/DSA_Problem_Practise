//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    void solve(int ind, int sum, vector<int>& arr, int N, vector<int>& ans) 
    {
        if(ind==N) {
            ans.push_back(sum);
            return;
        }
        //pick
        solve(ind+1, sum+arr[ind],arr,N,ans);
        
        // notPick
        solve(ind+1,sum,arr,N,ans);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int>ans;
        int index=0;
        int sum=0;
        
        solve(index,sum,arr,N,ans);
        sort(ans.begin(),ans.end());
        
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
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
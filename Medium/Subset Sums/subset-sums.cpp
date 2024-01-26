//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    void solve(vector<int>arr,vector<int>&ans,vector<int>subset,int index){
        if(index>=arr.size()){
            ans.push_back(accumulate(subset.begin(),subset.end(),0));
            return;
        }
        //Exclude
        solve(arr,ans,subset,index+1);
        
        //Include
        int element=arr[index];
        subset.push_back(element);
        solve(arr,ans,subset,index+1);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        //Done on own
        vector<int>ans;
        int index=0;
        vector<int>subset;
        solve(arr,ans,subset,index);
        
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
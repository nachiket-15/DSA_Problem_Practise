//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void findCombination(int ind,vector<int>&arr,vector<vector<int>>&ans,vector<int>&ds,int target)
    {
        if(target==0)
        {
            ans.push_back(ds);
            return ;
        }
        
        //See we are on a mission to fill ds inside ans array 
        //In each iteration , we want to fill ind th element from ds
        
        //Hence when we have already filled an x element at position ind in ds 
        //& if we again encounter x for ith position , then we will continue
        for(int i=ind;i<arr.size();i++)
        {
            if(i>ind && arr[i]==arr[i-1])continue;
            
            if(arr[i]>target)break;
            
            ds.push_back(arr[i]);
            findCombination(i+1,arr,ans,ds,target-arr[i]);
            ds.pop_back();
        }
    }
    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k)
    {
        //See combination 1 technique with just modification in the
        //include call with index+1 is fine and will work too
        //But will produce duplicates 
        //So you would additionally require set data structure
        //Which would increase time complexity from (2^N)*K to (2^N)KLogN
        
        //Hence we are following this approach(strivers video)
        vector<vector<int>>ans;
        vector<int>ds;
        
        sort(arr.begin(),arr.end());
        
        findCombination(0,arr,ans,ds,k);
        return ans;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        auto obj=ob.CombinationSum2(arr,n,k);
        for(int i=0;i<obj.size();i++)
        {
            for(int j=0;j<obj[i].size();j++)
            {
                cout<<obj[i][j]<<" ";
            }
            cout<<"\n";
        }
        if(obj.size()==0) cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
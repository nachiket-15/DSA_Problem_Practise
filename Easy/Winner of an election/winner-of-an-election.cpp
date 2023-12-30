//{ Driver Code Starts
#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
        // Your code here
        // Return the string containing the name and an integer
        // representing the number of votes the winning candidate got
        
        vector<string>ans(2);
        
        unordered_map<string,int>freq;
        
        for(int i=0;i<n;i++)
        {
            freq[arr[i]]++;
        }
        
        int best=0;
        
        for(auto it:freq)
        {
            if(it.second > best){
                best=it.second;
                ans[0]=it.first;
                ans[1]=to_string(best);
            }
            else if(best == it.second && ans[0]>it.first){
                ans[0]=it.first;
                ans[1]=to_string(best);
            }
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++)
    {
        
        
        int n;
        cin>>n;
        
        string arr[n];
        
        for (int i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        vector<string> result = obj.winner(arr,n);
        
        cout<<result[0] << " " << result[1] << endl;
    }
    return 0;
}

// } Driver Code Ends
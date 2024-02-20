//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
  public:
    vector<int> arranged(int arr[],int n)
    {
        vector<int>v1,v2;
      
      for(int i=0;i<n;i++)
      {
          if(arr[i]<0)
          v1.push_back(arr[i]);
          else
          {
              if(arr[i]>=0)
              v2.push_back(arr[i]);
          }
      }
      vector<int>result;
      for(int i=0;i<n;i++)
      {
           result.push_back(v2[i]);
            result.push_back(v1[i]);
      }
      return result;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    int n,i,j;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    vector<int> ans;
    Solution obj;
    ans=obj.arranged(a,n);
    for(i=0;i<n;i++)
        cout<<ans[i]<<" ";
    cout<<"\n";
    }
}

// } Driver Code Ends
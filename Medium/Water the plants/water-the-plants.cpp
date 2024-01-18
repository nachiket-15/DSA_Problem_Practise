//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    
    int min_sprinklers(int gallery[], int n)
    {
        //sprinkler with range x at division i can water all divisions from i-x to i+x.
        vector<pair<int,int>>v;//(i-x,i+x)
        
        for(int i=0;i<n;i++)
        {
            if(gallery[i]==-1){
                continue;
            }
            
            int no_of_div_watered_in_front=min(n-1,i+gallery[i]);
            int no_of_div_watered_in_back=max(0,i-gallery[i]);
            
            v.push_back({no_of_div_watered_in_back,no_of_div_watered_in_front});
        }
        
        sort(v.begin(),v.end());
        
        int start=0;
        int i=0;
        
        int ans=0;
        
        while(start<n)
        {
            int maxi=INT_MIN;
            while(i<v.size())
            {
                if(v[i].first > start)
                {
                    break;
                }
                
                maxi=max(v[i].second,maxi);
                i++;
            }
            
            if(maxi<start)
            {
                return -1;
            }
            
            ans++;
            start=maxi+1;
        }
        
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
        int n;
        cin>>n;
        
        int gallery[n];
        for(int i=0; i<n; i++)
            cin>> gallery[i];
        Solution obj;
        cout<< obj.min_sprinklers(gallery,n) << endl;
    }
	return 1;
}

// } Driver Code Ends
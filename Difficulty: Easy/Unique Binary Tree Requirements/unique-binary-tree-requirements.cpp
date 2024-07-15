//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    bool isPossible(int a,int b)
    {
        int one=0;
        int two=0;
        int three=0;
        
        if(a==1)one++;
        if(b==1)one++;
        if(a==2)two++;
        if(b==2)two++;
        if(a==3)three++;
        if(b==3)three++;
        
        if(one && two)return 1;
        if(two && three)return 1;
        
        if(one>1 || two>1 || three>1)return 0;
        
        return 0;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b; 
        cin>>a>>b;
        Solution obj;
        bool ans=obj.isPossible(a,b);
        cout<<ans<<"\n";
    }
}
// } Driver Code Ends
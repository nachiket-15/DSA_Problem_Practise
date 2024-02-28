//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int function(string s)
    {
        int ans=0;
        
        for(char num:s)
        {
            if(num>= '0' && num <='9')
            {
                ans=ans*10+(num-'0');
            }
        }
        
        return ans;
    }
    int DivisibleByEight(string s){
        int num=function(s);
        
        if(num%8==0)return 1;
        
        return -1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.DivisibleByEight(S)<<"\n";
    }
}
// } Driver Code Ends
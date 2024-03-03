//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to find the largest number after k swaps.
    string ans="";
    void helper(int idx,int k,string str)
    {
        //Base case
        if(k<=0 || idx>=str.length())
        {
            ans=max(ans,str);
            return;
        }
        
        //Not swap case 
        helper(idx+1,k,str);
        
        //Swap case - We have to consider all possibilities in remaining string and hence loop for this call
        
        for(int i=idx+1;i<str.length() && k>0;i++)
        {
            if(str[idx]<str[i])
            {
                swap(str[idx],str[i]);
                helper(idx+1,k-1,str);
                //Backtrack after exploring 
                swap(str[i],str[idx]);
            }
        }
    }
    
    string findMaximumNum(string str, int k)
    {
       //Solution referred
       int idx=0;
       helper(idx,k,str);
       return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string S) {
        //Solution referred
        int n=S.length();
        int i=0,j=0,one=0,two=0,zero=0,ans=1e9;
        
        while(j<n)
        {
            if(S[j]=='0')zero++;
            else if(S[j]=='1')one++;
            else if(S[j]=='2')two++;
            
            while(zero>0 && one>0 && two>0)
            {
                ans=min(ans,j-i+1);
                if(S[i]=='0')zero--;
                else if(S[i]=='1')one--;
                else if(S[i]=='2')two--;
                i++;
            }
            j++;
        }
        if(ans==1e9)ans=-1;
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends
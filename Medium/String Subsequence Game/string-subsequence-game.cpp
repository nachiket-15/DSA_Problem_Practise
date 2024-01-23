//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    set<string> allPossibleSubsequences(string S) {
        
        set<string>ans;
        
        
        
        //We will use bit manipulation approach
        int n=S.length();
        
        for(int i=0;i<(1<<n);i++)
        {
            string st="";
            
            for(int j=0;j<n;j++)
            {
                if(i & (1<<j)){
                    st+=S[j];
                }
            }
            
            if(st.size()>=2)
            {
                if((st[0]=='a' || st[0]=='e' || st[0]=='i' ||st[0]=='o' || st[0]=='u') && (st[st.size()-1]!='a' && st[st.size()-1]!='e' && st[st.size()-1]!='i' && st[st.size()-1]!='o'&&st[st.size()-1]!='u' ) ){
                ans.insert(st);
            }
            }
        }
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
        set<string> ans = ob.allPossibleSubsequences(S);
        if (ans.size() == 0)
            cout << -1 << endl;
        else {
            for (auto i : ans) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends
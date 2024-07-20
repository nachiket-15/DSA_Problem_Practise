//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string preToInfix(string pre_exp) {
        stack<string>st;
        int n=pre_exp.length();
        reverse(pre_exp.begin(),pre_exp.end());
        
        for(int i=0;i<n;i++)
        {
            char ch=pre_exp[i];
            
            if(ch>='a' && ch<='z' || ch>='A' && ch<='Z')
            {
                st.push(string(1,ch));
            }else{
                string t1=st.top();st.pop();
                string t2=st.top();st.pop();
                
                string newString='('+t1+ch+t2+')';
                st.push(newString);
            }
        }
        return st.top();
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToInfix(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends
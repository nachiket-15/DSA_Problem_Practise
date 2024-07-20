//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string postToPre(string post_exp) {
        int n=post_exp.size();
        stack<string>st;
        
        for(int i=0; i<n; i++){
            char ch=post_exp[i];
            
            if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z')){
                st.push(string(1, ch));
            }
            else if(ch=='+' || ch=='-' || ch=='*' || ch=='/'){
                string op1=st.top(); st.pop();
                string op2=st.top(); st.pop();
                st.push(ch + op2 + op1);
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
        string postfix;
        cin >> postfix;

        // char marker; cin >> marker;

        Solution obj;
        cout << obj.postToPre(postfix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends
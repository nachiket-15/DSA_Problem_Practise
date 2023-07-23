//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
    bool check_op(char x)
    {
        if(x =='+'|| x== '-'|| x== '/'|| x=='*')
            return true;
        else
            return false;
    }
  public:
    string preToPost(string pre_exp) {
        reverse(pre_exp.begin(),pre_exp.end());
        stack<string>st;
        
        for(int i=0;i<pre_exp.length();i++){
            char ch=pre_exp[i];
            
            if(check_op(ch)){
                string op1=st.top();
                st.pop();
                
                string op2=st.top();
                st.pop();
                
                string temp=op1+op2+ch;
                st.push(temp);
            }
            else{
                st.push(string(1,ch));
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
        cout << obj.preToPost(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends
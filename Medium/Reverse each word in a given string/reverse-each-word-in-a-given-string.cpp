//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseWords (string s)
    {
        //Very happy :)) Done on my own
        string ans;
        stack<char>st;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            if(isalpha(ch)||isdigit(ch)){
                st.push(ch);
            }else{
                if(!st.empty())
                {
                    while(!st.empty()){
                        ans+=st.top();
                        st.pop();
                    }
                }
                ans+='.';
            }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.reverseWords (s) << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends
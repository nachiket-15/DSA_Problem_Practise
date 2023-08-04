//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        stack<string>st;
        
        for(int i=0;i<S.size();i++){
            if(S[i]==' ')continue;
            string word;
            while(i<S.size() && S[i]!='.'){
                word+=S[i];
                i++;
            }
            st.push(word);
        }
        string ans;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
            if(!st.empty())
                ans+='.';
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
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends
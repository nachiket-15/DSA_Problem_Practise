//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    vector<int> bracketNumbers(string str) {
        
        stack<pair<char,int>>st;
        vector<int>ans;
        
        int uniqCnt=0;
        
        for(char ch:str)
        {
            if(ch=='(')
            {
                uniqCnt++;
                st.push({ch,uniqCnt});
                
                ans.push_back(uniqCnt);
            }
            else if(ch==')')
            {
                auto it=st.top();
                ans.push_back(it.second);
                st.pop();
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;

        vector<int> ans = ob.bracketNumbers(s);

        for (auto i : ans)
            cout << i << " ";

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends
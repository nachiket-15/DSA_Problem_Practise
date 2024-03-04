//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string s){
        //Solution referred
        stack<char>st;
        string ans = "";
        
        for(int i=0;i<s.size();i++) {
            if(s[i]==']') 
            {
                while(st.size()>0 && st.top()!='[') {
                    //this is concatenating and not appending
                    ans = st.top() + ans;
                    st.pop();
                }
                // cout<<ans<<" "<<endl;
                
                //then remove '['
                if(st.size()>0) {
                    st.pop();
                }
                
                //now after removing '[' we want to extract num 
                string num = "";
                while(st.size()>0 && st.top()>='0' && st.top()<='9') {
                    num = st.top()+num;
                    st.pop();
                }
                
                int digit = stoi(num);
                
                string temp = ans;
                for(int i=0;i<digit-1;i++) {
                    ans += temp;
                }
                
                for(int i=0;i<ans.length();i++) {
                    st.push(ans[i]);
                }
                
                ans = "";
            }
            
            else {
                st.push(s[i]);
            }
        }
        
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
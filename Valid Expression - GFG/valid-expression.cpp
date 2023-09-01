//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
bool valid(string str);
int main()
{
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string str;
        getline(cin,str);
        cout<<valid(str)<<endl;
    }
    return 0;
}
// } Driver Code Ends

bool ispar(string s)
    {
       if(s.length()%2==1){
          return false;//odd number brackets cant be balanced
        }
        
        stack<int>st;
        st.push('a');
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' || s[i]=='['||s[i]=='{'){
                st.push(s[i]);
            }
            else if(s[i]==')' && st.top()=='(')
            {
                st.pop();
            }
            else if(s[i]==']'&& st.top()=='[')
            {
                st.pop();
            }
            else if(s[i]=='}'&& st.top()=='{')
            {
                st.pop();
            }
            else{
                return false;
            }
        }
        if(st.size()!=1){
            return false;
        }
        return true;
    }
bool valid(string s)
{
    return ispar(s);
}
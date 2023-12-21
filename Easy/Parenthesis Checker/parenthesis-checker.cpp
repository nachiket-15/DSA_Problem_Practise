//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string s)
    {
        if(s.length()%2==1)
        {
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

};


//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends
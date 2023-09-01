//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    #include<bits/stdc++.h>
#include<stack>
bool findRedundantBrackets(string &s)
{
    // Write your code here.
    stack<char>st;
    for(int i=0;i<s.length();i++){
        char ch=s[i];
        if(ch=='(' || ch=='+'||ch=='-'||ch=='/'||ch=='*'){
            st.push(ch);
        }
        else{
            if(ch==')'){
                bool isRedundant=true;
                while(st.top()!='('){
                    if(st.top()=='+'||st.top()=='-'||st.top()=='/'||st.top()=='*'){ 
                        isRedundant=false;
                        st.pop();
                    }
                }
                if(isRedundant==true){
                    return true;
                }
                st.pop();
            }
        }
    }
    return false;
}

    int checkRedundancy(string s) {
        return findRedundantBrackets(s);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        
    
        string s; 
        cin>>s;
        
        Solution obj;
        int res = obj.checkRedundancy(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
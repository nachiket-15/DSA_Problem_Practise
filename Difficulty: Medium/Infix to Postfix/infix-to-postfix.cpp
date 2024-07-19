//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int priority(char ch){
        if(ch=='^'){
            return 3;
        }
        else if(ch=='*'||ch=='/'){
            return 2;
        }
        else if(ch=='+'||ch=='-'){
            return 1;
        }
        else{
            return -1;
        }
    }
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s) {
        stack<char>st;
        string result="";
        
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            // if its an operand
            if((ch>='a'&&ch<='z') || (ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9')){
                result+=ch;
            }
            // if
            else if(ch=='('){
                st.push(ch);
            }
            else if(ch==')'){
                while(!st.empty() && st.top()!='('){
                    result+=st.top();
                    st.pop();
                }
                //pop the '('
                st.pop();
            }
            // when its an operator
            else{
                while(!st.empty() && priority(st.top())>=priority(ch)){
                    result+=st.top();
                    st.pop();
                }
                st.push(ch);
            }
        }
        
        while(!st.empty()){
            result+=st.top();
            st.pop();
        }
        
        return result;
    }
};



//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends
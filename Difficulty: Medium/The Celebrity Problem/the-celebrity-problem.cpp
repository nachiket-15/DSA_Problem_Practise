//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M) 
    {
        int n=M.size();
        //Push all persons into stack
        //;) here persons are indexes
        
        stack<int>st;
        
        for(int i=0;i<n;i++){
            st.push(i);
        }
        
        while(st.size()>1){
            int a=st.top();
            st.pop();
            
            int b=st.top();
            st.pop();
            
            //a la b mahiti ahe ka ?
            if(M[a][b]==1){
                //asel tr b celebrity jhala
                st.push(b);
            }else{
                //nahitr a celebrity jhala 
                st.push(a);
            }
        }
        
        int candidate=st.top();
        
        //Now verify the candidate as celebrity
        
        for(int i=0;i<n;i++){
            if(i!=candidate && (M[i][candidate]==0 || M[candidate][i]==1)){
                return -1;
            }
        }
        
        return candidate;
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
    }
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// #define ll long long
class Solution{
public:
    vector<long long> nthRowOfPascalTriangle(int n) {
        // code here
        vector<long long>ans;  
        
        vector<vector<long long>>row(n);   
        long long m = 1e9+7;   
        
        for(long long int i=0; i<n; i++){
            row[i].resize(i+1);    
            
            row[i][0]=1;   
            row[i][i]=1;    
            
            for(int j=1; j<i; j++)
            {
                row[i][j]= (row[i-1][j-1] + row[i-1][j]) %m;   
            }
            
            if(i==(n-1))  
            {
                for(auto k:row[i])   
                {
                    ans.push_back(k);
                }
            }
        }
        return ans; 
    }
};


//{ Driver Code Starts.


void printAns(vector<long long> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int minimizeDifference(int n, int k, vector<int> &arr) {
        int ans = 1e9;
        vector<int>preMax(n),preMin(n);
        vector<int>suffMax(n),suffMin(n);
        
        preMax[0] = -1e9;
        preMin[0] = 1e9;
        
        suffMax[n-1] = -1e9;
        suffMin[n-1] = 1e9;
        
        for(int i = 1; i<n; i++){
           preMax[i] = max(preMax[i-1], arr[i-1]);
           preMin[i] = min(preMin[i-1], arr[i-1]);
        }
        
        for(int i = n-2; i>=0; i--){
           suffMax[i] = max(suffMax[i+1], arr[i+1]);
           suffMin[i] = min(suffMin[i+1], arr[i+1]);
        }
        
        int i = 0;
        for(int j = 0; j<n; j++){
            if(j-i+1 == k){
                ans = min(ans, max(preMax[i], suffMax[j]) - min(preMin[i], suffMin[j]));
                i++;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        int k;
        scanf("%d",&k);
        
        
        vector<int> arr(n);
        Array::input(arr,n);
        
        Solution obj;
        int res = obj.minimizeDifference(n, k, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
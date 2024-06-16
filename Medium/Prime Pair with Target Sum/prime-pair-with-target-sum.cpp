//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    vector<int> getPrimes(int n) {
        //Sieve of Eratosthenes method
        
        vector<int>prime_array(n+1,0);
        // 0 rahila tr prime 
        // 1 wala non prime
        
        prime_array[0]=prime_array[1]=1;
        
        for(int i=2;i*i<=n;i++)
        {
            for(int j=i*i;j<n;j+=i)
            {
                prime_array[j]=1;
            }
        }
        
        vector<int>ans(2,-1);
        
        for(int i=2;i<=n;i++)
        {
            if(prime_array[i]==0 && prime_array[n-i]==0)
            {
                if(ans[0]==-1)
                {
                    ans[0]=i,ans[1]=(n-i);
                }
                else if(ans[0]!=-1 && i<ans[0])
                {
                    ans[0]=i,ans[1]=(n-i);
                }
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        vector<int> res = obj.getPrimes(n);

        Array::print(res);
    }
}

// } Driver Code Ends
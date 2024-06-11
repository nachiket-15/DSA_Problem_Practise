//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &a, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &a[i]);
        }
    }

    template <class T>
    static void print(vector<T> &a) {
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    long long maxTip(int n, int x, int y, vector<int> &arr, vector<int> &brr) {
        // solution referred 
        // we will create a vector which will store (diff,arr,brr)
        
        vector<pair<int,pair<int,int>>>temp;
        
        for(int i=0;i<n;i++)
        {
            temp.push_back({abs(arr[i]-brr[i]),{arr[i],brr[i]}});
        }
        
        sort(temp.rbegin(),temp.rend());
        
        long long ans=0;
        
        //diff=4,2,0,2,4
        //sorted=4,4,2,2,0
        
        
        for(auto it:temp)
        {
            if(x==0){
                ans+=it.second.second;
                y--;
            }    
            else if(y==0)
            {
                ans+=it.second.first;
                x--;
            }
            else{
                if(it.second.first>it.second.second)
                {
                    ans+=it.second.first;
                    x--;
                }else{
                    ans+=it.second.second;
                    y--;
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

        int x;
        scanf("%d", &x);

        int y;
        scanf("%d", &y);

        vector<int> arr(n);
        Array::input(arr, n);

        vector<int> brr(n);
        Array::input(brr, n);

        Solution obj;
        long long res = obj.maxTip(n, x, y, arr, brr);

        cout << res << endl;
    }
}

// } Driver Code Ends
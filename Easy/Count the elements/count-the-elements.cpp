//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int bsearch(vector<int> &b, int x)
    {
        int low = 0;
        int high = b.size() -1;
        
        int mid = (high + low)/2;
        int flag = 0;
        
        if(x < b[0])
        {
            return 0;
        }
        
        while(low < high && flag == 0)
        {
            if(b[mid]<=x && b[mid + 1] > x)
            {
                flag = 1;
            }
            else if(b[mid] <= x && b[mid+1] <= x)
            {
                low = mid + 1;
                mid = (high + low)/2;
            }
            else
            {
                high = mid - 1;
                mid = (high + low)/2;
            }
        }
        
        return mid + 1;
    }
    vector<int> countElements(vector<int> &a, vector<int> &b, int n, vector<int> &query,
                              int q) 
    {
        // Your code goes here;
        
        int i;
        sort(b.begin(), b.end());
        vector<int> ans;
        for(i = 0; i<q; i++)
        {
            int x = query[i];
            int y = a[x];
            ans.push_back(bsearch(b, y));
        }
        
        return ans;
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {

        int n;
        cin >> n;
        vector<int> a, b, ans;
        int input;
        for (int i = 0; i < n; i++) {
            cin >> input;
            a.push_back(input);
        }
        for (int i = 0; i < n; i++) {
            cin >> input;
            b.push_back(input);
        }
        int q;
        cin >> q;
        vector<int> query;
        for (int i = 0; i < q; i++) {
            cin >> input;
            query.push_back(input);
        }
        Solution obj;
        ans = obj.countElements(a, b, n, query, q);
        for (int i = 0; i < q; i++) {
            cout << ans[i] << endl;
        }
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> ans;
        int m = nums1.size();
        int n = nums2.size();
        int i = 0;  // Pointer for nums1
        int j = 0;  // Pointer for nums2
        
        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                ans.push_back(nums1[i]);
                i++;
            } else {
                ans.push_back(nums2[j]);
                j++;
            }
        }

        // Add remaining elements from nums1, if any
        while (i < m) {
            ans.push_back(nums1[i]);
            i++;
        }
        
        // Add remaining elements from nums2, if any
        while (j < n) {
            ans.push_back(nums2[j]);
            j++;
        }

        int d = ans.size();
        if (d % 2 == 0) {
            int z = d / 2;
            double sum = (ans[z] + ans[z - 1]);
            return sum / 2;
        } else {
            int z = round(d / 2);
            return ans[z];
        }

    
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends
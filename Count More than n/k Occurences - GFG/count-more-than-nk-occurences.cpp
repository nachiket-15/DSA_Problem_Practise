//{ Driver Code Starts
// A C++ program to print elements with count more than n/k

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find all elements in array that appear more than n/k times.
    int countOccurence(int arr[], int n, int k) {
        //Initialize unordered map
        unordered_map<int,int>m;
        //Increment the frequency in map when value is spotted
        for(int i=0;i<n;i++){
            m[arr[i]]++;
        }
        int count=0;
        // In map i.first is value 
        // i.second is its frequency
        for(auto i:m){
            if(i.second>n/k){
                count++;
            }
        }
        return count;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;

        int arr[n];

        for (i = 0; i < n; i++) cin >> arr[i];
        int k;
        cin >> k;
        Solution obj;
        cout << obj.countOccurence(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends
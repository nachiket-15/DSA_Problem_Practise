//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

// arr : given vector of elements
// target : given sum value

class Solution {
  public:
    int threeSumClosest(vector<int> arr, int target) {
        sort(arr.begin(), arr.end());
        // use 2 pointer approach
        int ans = arr[0] + arr[1] + arr[2]; // Initialize with the first three elements sum
        int minDiff = abs(ans - target);
        
        for (int i = 0; i < arr.size() - 2; i++) {
            int left = i + 1;
            int right = arr.size() - 1;
            
            while (left < right) {
                int sum = arr[i] + arr[left] + arr[right];
                
                if (sum == target) return sum;
                
                int diff = abs(sum - target);
                
                if (diff < minDiff) {
                    minDiff = diff;
                    ans = sum;
                } else if (diff == minDiff && sum > ans) {
                    ans = sum;
                }
                
                if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        // cin.ignore();
        // if (f)
        //     return 0;
        Solution ob;
        cout << ob.threeSumClosest(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends
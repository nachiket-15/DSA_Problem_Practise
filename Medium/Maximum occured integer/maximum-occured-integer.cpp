//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // l and r are input array
    // maxx : maximum in r[]
    // n: size of array
    // arr[] : declared globally with size equal to maximum in l[] and r[]
    // Function to find the maximum occurred integer in all ranges.
    int maxOccured(int n, int l[], int r[], int maxx) {

        // Create a map to store the frequency of each integer
        // map<int, int> freq;
    
        // // Iterate through each range and count the frequencies of each integer
        // for (int i = 0; i < n; i++) {
        //     for (int j = l[i]; j <= r[i]; j++) {
        //         freq[j]++;
        //     }
        // }
    
        // // Find the maximum occurring integer
        // int maxFreq = 0;
        // int result = maxx;  // Initialize to maxx for smallest integer condition
    
        // for (const auto& entry : freq) {
        //     if (entry.second > maxFreq) {
        //         maxFreq = entry.second;
        //         result = entry.first;
        //     } else if (entry.second == maxFreq && entry.first < result) {
        //         result = entry.first;
        //     }
        // }
    
        // return result;
        
        
        //approach 2 
        // Step 1: Create a frequency array
        vector<int> freq(maxx + 2, 0);
    
        // Step 2: Populate the difference array
        for (int i = 0; i < n; i++) {
            freq[l[i]] += 1;
            if (r[i] + 1 <= maxx) {
                freq[r[i] + 1] -= 1;
            }
        }
    
        // Step 3: Compute the prefix sum and find the maximum occurred integer
        int max_count = -1;
        int max_occurred_integer = -1;
        int current_count = 0;
        
        for (int i = 0; i <= maxx; i++) {
            current_count += freq[i];
            if (current_count > max_count) {
                max_count = current_count;
                max_occurred_integer = i;
            }
        }
    
        return max_occurred_integer;
    }
};


//{ Driver Code Starts.

int main() {

    int t;

    // taking testcases
    cin >> t;

    while (t--) {
        int n;

        // taking size of array
        cin >> n;
        int l[n];
        int r[n];

        // adding elements to array L
        for (int i = 0; i < n; i++) {
            cin >> l[i];
        }

        int maxx = 0;

        // adding elements to array R
        for (int i = 0; i < n; i++) {

            cin >> r[i];
            if (r[i] > maxx) {
                maxx = r[i];
            }
        }
        Solution ob;

        // calling maxOccured() function
        cout << ob.maxOccured(n, l, r, maxx) << endl;
    }

    return 0;
}
// } Driver Code Ends
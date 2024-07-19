//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
//  User function template for C++

class Solution {
  public:
    
// Function to perform merge sort and count smaller elements
void merge(vector<int>& arr, vector<int>& indices, vector<int>& counts, int left, int mid, int right) {
    vector<int> temp(right - left + 1);
    int left_index = left, right_index = mid + 1, k = 0, right_counter = 0;

    // Merge the two halves
    while (left_index <= mid && right_index <= right) {
        if (arr[indices[right_index]] < arr[indices[left_index]]) {
            temp[k++] = indices[right_index++];
            right_counter++;
        } else {
            temp[k++] = indices[left_index];
            counts[indices[left_index]] += right_counter;
            left_index++;
        }
    }

    // Copy the remaining elements from the left half
    while (left_index <= mid) {
        temp[k++] = indices[left_index];
        counts[indices[left_index]] += right_counter;
        left_index++;
    }

    // Copy the remaining elements from the right half
    while (right_index <= right) {
        temp[k++] = indices[right_index++];
    }

    // Copy the merged subarray back to the original array
    for (int i = 0; i < k; ++i) {
        indices[left + i] = temp[i];
    }
}

void mergeSort(vector<int>& arr, vector<int>& indices, vector<int>& counts, int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;
    mergeSort(arr, indices, counts, left, mid);
    mergeSort(arr, indices, counts, mid + 1, right);
    merge(arr, indices, counts, left, mid, right);
}

vector<int> constructLowerArray(vector<int>& arr) {
    int n = arr.size();
    vector<int> counts(n, 0);
    vector<int> indices(n);

    // Initialize the indices array
    for (int i = 0; i < n; ++i) {
        indices[i] = i;
    }

    // Perform merge sort and count smaller elements
    mergeSort(arr, indices, counts, 0, n - 1);

    return counts;
}
};

//{ Driver Code Starts.
int main() {
    int t;

    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        vector<int> a = ob.constructLowerArray(arr);
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
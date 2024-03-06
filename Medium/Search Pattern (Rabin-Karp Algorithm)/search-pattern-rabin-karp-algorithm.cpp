//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pattern, string text)
        {
            //code here.
            vector<int> indices;

    // Prime number used for hashing
    int q = 101;

    int m = pattern.size();
    int n = text.size();
    int i, j, hash_p = 0, hash_t = 0, h = 1, d = m + n;

    // Calculate h: (d^(m-1)) % q
    for (i = 0; i < m - 1; i++) {
        h = (h * d) % q;
    }

    // Calculate hash value for pattern and text
    for (i = 0; i < m; i++) {
        hash_p = (pattern[i] + d * hash_p) % q;
        hash_t = (text[i] + d * hash_t) % q;
    }

    // Find the match
    for (i = 0; i <= n - m; i++) {
        // Check the hash values of current windows of text and pattern.
        if (hash_p == hash_t) {
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) break;
            }
            // if pattern == text
            if (j == m) indices.push_back(i+1);
        }
        // Calculate the hash value for next window : adding trailing digit and remove leading digit
        if (i < n - m) {
            hash_t = (d * (hash_t - text[i] * h) + text[i + m]) % q;
            // Converting negative value of hash_t to positive
            if (hash_t < 0) hash_t = (hash_t + q);
        }
    }

    return indices;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends
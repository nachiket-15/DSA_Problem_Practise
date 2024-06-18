//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// User function Template for C++

class Solution {
  public:
    int rectanglesInCircle(int radius) {
        
        int rectangles = 0;
        // Diameter = 2 * Radius
        int diameter = 2 * radius;
        // Square of diameter which is the square of the maximum length diagonal
    
        int diameterSquare = diameter * diameter;
     
        // generate all combinations of a and b
    
        // in the range (1, (2 * Radius - 1))(Both inclusive)
    
        for (int a = 1; a < 2 * radius; a++) {
    
            for (int b = 1; b < 2 * radius; b++) {
     
    
                // Calculate the Diagonal length of
    
                // this rectangle
    
                int diagonalLengthSquare = (a * a + b * b);
     
    
                // If this rectangle's Diagonal Length
    
                // is less than the Diameter, it is a
    
                // valid rectangle, thus increment counter
    
                if (diagonalLengthSquare <= diameterSquare) {
    
                    rectangles++;
    
                }
    
            }
    
        }
     
    
        return rectangles;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        int ans = ob.rectanglesInCircle(n);
        cout << ans << "\n";
    }
}
// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    /*
    Maximize The Cut Segments
Introduction
The "Maximize The Cut Segments" problem is a classic dynamic programming problem that involves cutting a line segment into smaller parts.
Given a line segment of length n and three possible cut lengths x, y, and z, the goal is to determine the maximum number of segments the line can be cut into.
If no valid cuts can be made, the function should return 0.
Algorithm
To solve this problem, imagine you're trying to cut a rope of length n into as many pieces as possible, but you can only make cuts of lengths x, y, or z.
The key challenge is to explore all possible ways to cut the rope and keep track of the maximum number of segments you can achieve.
If a particular cut doesn't fit, you move on to other possibilities.
 
The idea is to leverage dynamic programming to store the results of subproblems, so we don't need to recompute the number of segments for every possible cut.
Approach
1. Dynamic Programming Array Initialization:
   - We create a DP array dp where dp[i] represents the maximum number of segments that can be obtained from a line segment of length i.
   - We initialize dp[0] = 0 since a line segment of length 0 has 0 segments, and set the other entries to negative infinity (-inf) to indicate that no cuts have been made yet.
 
2. Iterating Over Lengths:
   - We iterate over all lengths from 1 to n and determine the maximum number of segments for each length by considering the cuts of lengths x, y, and z.
 
3. Updating the DP Array:
   - For each length i, we calculate the maximum number of segments by considering cuts of lengths x, y, and z (if they are feasible).
   - We update dp[i] with the maximum value obtained from the three possible cuts.
 
4. Result:
   - The value at dp[n] will give us the maximum number of segments for the length n. If dp[n] is still negative, it means no valid cuts can be made, and we return 0.
Optimized Code
class Solution:
    def maximizeTheCuts(self, total_length, cut_length_x, cut_length_y, cut_length_z):
        # Initialize a DP array where dp[i] stores the maximum number of cuts for length i
        dp = [0] + [float("-inf")] * total_length
       
        # Iterate through each length from 1 to total_length
        for current_length in range(1, total_length + 1):
            # If current_length is greater than or equal to cut_length_x, consider cutting it
            max_cuts_x = 1 + dp[current_length - cut_length_x] if current_length >= cut_length_x else dp[current_length]
           
            # If current_length is greater than or equal to cut_length_y, consider cutting it
            max_cuts_y = 1 + dp[current_length - cut_length_y] if current_length >= cut_length_y else dp[current_length]
           
            # If current_length is greater than or equal to cut_length_z, consider cutting it
            max_cuts_z = 1 + dp[current_length - cut_length_z] if current_length >= cut_length_z else dp[current_length]
           
            # Update dp[current_length] with the maximum cuts possible
            dp[current_length] = max(dp[current_length], max_cuts_x, max_cuts_y, max_cuts_z)

        # The result is the maximum number of cuts possible for total_length
        # Return 0 if no cuts can be made (i.e., result is negative)
        return max(0, dp[-1])
Brief Dry Run
Let's run the algorithm with the following example:
 
Example:
- n = 5
- x = 5
- y = 3
- z = 2

We need to find the maximum number of segments the line segment can be cut into using lengths 5, 3, and 2.

Initialization:
- dp = [0, -inf, -inf, -inf, -inf, -inf]
- Here, dp[0] = 0 because no segments are needed for a length of 0. All other positions are initialized to -inf to signify that no segments have been determined yet.

Iteration through the lengths:

1. For current_length = 1:
   - We check if it's possible to cut a segment of length 5, 3, or 2.
   - None of these lengths can be used to cut a segment from 1, so dp[1] remains -inf.
   - dp = [0, -inf, -inf, -inf, -inf, -inf]

2. For current_length = 2:
   - Check if 2 >= 5: No, can't cut.
   - Check if 2 >= 3: No, can't cut.
   - Check if 2 >= 2: Yes, we can cut a segment of length 2.
     - max_cuts_z = 1 + dp[2 - 2] = 1 + dp[0] = 1 + 0 = 1
   - Update dp[2] to the maximum value among -inf, -inf, 1, which is 1.
   - dp = [0, -inf, 1, -inf, -inf, -inf]

3. For current_length = 3:
   - Check if 3 >= 5: No, can't cut.
   - Check if 3 >= 3: Yes, we can cut a segment of length 3.
     - max_cuts_y = 1 + dp[3 - 3] = 1 + dp[0] = 1 + 0 = 1
   - Check if 3 >= 2: Yes, we can cut a segment of length 2.
     - max_cuts_z = 1 + dp[3 - 2] = 1 + dp[1] = 1 + (-inf) = -inf
   - Update dp[3] to the maximum value among -inf, 1, -inf, which is 1.
   - dp = [0, -inf, 1, 1, -inf, -inf]

4. For current_length = 4:
   - Check if 4 >= 5: No, can't cut.
   - Check if 4 >= 3: Yes, we can cut a segment of length 3.
     - max_cuts_y = 1 + dp[4 - 3] = 1 + dp[1] = 1 + (-inf) = -inf
   - Check if 4 >= 2: Yes, we can cut a segment of length 2.
     - max_cuts_z = 1 + dp[4 - 2] = 1 + dp[2] = 1 + 1 = 2
   - Update dp[4] to the maximum value among -inf, -inf, 2, which is 2.
   - dp = [0, -inf, 1, 1, 2, -inf]

5. For current_length = 5:
   - Check if 5 >= 5: Yes, we can cut a segment of length 5.
     - max_cuts_x = 1 + dp[5 - 5] = 1 + dp[0] = 1 + 0 = 1
   - Check if 5 >= 3: Yes, we can cut a segment of length 3.
     - max_cuts_y = 1 + dp[5 - 3] = 1 + dp[2] = 1 + 1 = 2
   - Check if 5 >= 2: Yes, we can cut a segment of length 2.
     - max_cuts_z = 1 + dp[5 - 2] = 1 + dp[3] = 1 + 1 = 2
   - Update dp[5] to the maximum value among 1, 2, 2, which is 2.
   - dp = [0, -inf, 1, 1, 2, 2]

Final Result

- The value at dp[5] is 2, meaning that the maximum number of segments that the length 5 can be cut into is 2.

So, the output for this example is 2.
Time and Space Complexity
- Time Complexity: The time complexity of this solution is O(n), where n is the length of the segment. This is because we iterate through all lengths from 1 to n and update the DP array.
 
- Space Complexity: The space complexity is O(n) due to the DP array used to store the maximum number of segments for each length.

    */
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        
        // Initialize a DP array where dp[i] stores the maximum number of cuts for length i
        vector<int> dp(n + 1, -1e9); // Use a large negative number to represent -infinity
        dp[0] = 0;
    
        // Iterate through each length from 1 to n
        for (int current_length = 1; current_length <= n; ++current_length) {
            // If current_length is greater than or equal to x, consider cutting it
            if (current_length >= x) {
                dp[current_length] = max(dp[current_length], 1 + dp[current_length - x]);
            }
    
            // If current_length is greater than or equal to y, consider cutting it
            if (current_length >= y) {
                dp[current_length] = max(dp[current_length], 1 + dp[current_length - y]);
            }
    
            // If current_length is greater than or equal to z, consider cutting it
            if (current_length >= z) {
                dp[current_length] = max(dp[current_length], 1 + dp[current_length - z]);
            }
        }
    
        // The result is the maximum number of cuts possible for n
        // Return 0 if no cuts can be made (i.e., result is negative)
        return max(0, dp[n]);
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends
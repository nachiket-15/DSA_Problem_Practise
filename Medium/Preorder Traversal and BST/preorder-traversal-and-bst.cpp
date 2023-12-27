//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int preIndex=0;
    void buildBST(int N,int arr[],int min,int max)
    {
        //Base case 
        if(preIndex>=N){
            return;
        }
        //Check BST conditions & then only build tree
        if(min < arr[preIndex] && max > arr[preIndex])
        {
            int rootNode=(arr[preIndex]);
            preIndex++;
            
            //Construct left subtree recursively
            buildBST(N,arr,min,rootNode);
            //Construct right subtree recursively
            buildBST(N,arr,rootNode,max);
        }
        
        //Here we arent using Node type pointers and we arent returning them 
        //As we are just checking the feasibility of constructing tree and our 
        //Logic is based on preIndex , which helps us to understand inclusion 
        //of all nodes in BST
    }
    int canRepresentBST(int arr[], int N) {
        // Solution says , we will build the tree frommgiven preorder array
        //Whilw building the tree if all nodes are utilized and get their position 
        //Then we say that , its possible to represent tree using all nodes in array
        
        buildBST(N,arr,-1e9,1e9);
        return preIndex==N;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        Solution ob;
        cout << ob.canRepresentBST(arr, N) << endl;
    }
    return 0;
}
// } Driver Code Ends
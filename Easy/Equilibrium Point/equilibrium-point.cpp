//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
        int totalSum=0;
        for(int i=0;i<n;i++){
            //calculate total sum
            totalSum+=a[i];
            
        }
        int leftSum=0;
        for(int i=0;i<n;i++){
            //update total sum by subtracting the current element
            totalSum-=a[i];
            
            if(totalSum==leftSum){
                //return index if equilibrium point is found
                return i+1;
            }
            else{
                //upadtae left sum by adding the current element
                leftSum+=a[i];
            }
        }
        //return -1 if equilibrium point is not found
        return -1;
    }

};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends
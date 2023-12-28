//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    bool isMaxHeap(int a[], int n)
    {
        //You have to iterate till first non-leaf element in array
        for(int i=0;i<=(n/2-1);i++)
        {
            int parentNode=a[i];
            int leftChild=a[2*i+1];
            int rightChild=a[2*i+2];
            
            if(parentNode<leftChild || parentNode<rightChild)
            {
                return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    
    int t;
    cin >> t;
    while(t--)
    {
       int n;
       cin >> n;
       int a[4*n]={0};
       for(int i =0;i<n;i++){
           cin >> a[i];
       }
       Solution ob;
       cout<<ob.isMaxHeap(a, n)<<endl;
        
    }
    return 0;
}

// } Driver Code Ends
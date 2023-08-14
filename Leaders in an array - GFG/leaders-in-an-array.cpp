//{ Driver Code Starts
// C++ program to remove recurring digits from
// a given number
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
    

class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        //Brute force sol by me - Gives TLE
        vector<int>ans;
        // for(int i=0;i<n;i++){
        //     int flag=0;
        //     for(int j=i+1;j<n;j++){
        //         if(a[j]>a[i])
        //             flag=1;
        //     }

        //     if(flag==0){
        //         ans.push_back(a[i]);
        //     }
        // }
        
        
        //Solution referred
        //Last element is always a leader
        
        ans.push_back(a[n-1]);
        
        for(int i=n-2;i>=0;i--){
            if(ans[ans.size()-1] <= a[i]){
                ans.push_back(a[i]);
            }
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
};


//{ Driver Code Starts.

int main()
{
   long long t;
   cin >> t;//testcases
   while (t--)
   {
       long long n;
       cin >> n;//total size of array
        
        int a[n];
        
        //inserting elements in the array
        for(long long i =0;i<n;i++){
            cin >> a[i];
        }
        Solution obj;
        //calling leaders() function
        vector<int> v = obj.leaders(a, n);
        
        //printing elements of the vector
        for(auto it = v.begin();it!=v.end();it++){
            cout << *it << " ";
        }
        
        cout << endl;

   }
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int arr[],long long int n, long long int k) {
        
                                        
        vector<long long>ans;
        
        queue<long long int>q;
        
        for(long long int i=0;i<n;i++){
            if(arr[i]<0)q.push(i);
        }
        
        long long int i=0;
        
        //i+k parynt karan , i+k is the start of last window of size k
        while(i+k<=n){
            //i start of window dakhvtoy
            
            //Queue chya front mdhe curr window mdhli first 
            //negative element padtey ka te check kartoy
            
            //As i is start of window , jar i motha asel 
            //Than negative element chi index (mhanje ch negative element)
            //Yacha arth tumchi window pudhe aliy , so juna 
            //Negative no kamacha rahila nahiye
            
            //So pop kara
            while(q.size()>0 &&  q.front()<i)
                q.pop();
            
            
            //Jevha purn window mdhe negative element ch nahiye
            if(q.size()==0 || q.front()>=i+k)
                ans.push_back(0);
                
            //queue chya front mdhla element valid first
            //negative integer ahe
            else 
                ans.push_back(arr[q.front()]);
                
            //pudh chya index la jane
            i++;
        }
        
         return ans;            
 }
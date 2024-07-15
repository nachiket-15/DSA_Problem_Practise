//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int sum(int num)
    {
        int sum=0;
        
        while(num)
        {
            sum+=num%10;
            num=num/10;
        }
        return sum;
    }
    string smallestNumber(int s, int d) {
        int start=1;
        
        for(int i=1;i<d;i++)
        {
            start=start*10;
        }
        
        for(int num=start;num<start*10;num++){
            int currNumSum=sum(num);
            
            if(currNumSum==s)return to_string(num);
        }
        
        return "-1";
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int s, d;
        cin >> s >> d;
        Solution ob;
        cout << ob.smallestNumber(s, d) << "\n";
    }

    return 0;
}
// } Driver Code Ends
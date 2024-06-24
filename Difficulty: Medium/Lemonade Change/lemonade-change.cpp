//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &bills) {
         // referred strivers video sol

        int five=0;
        int ten=0;

        for(int element:bills)
        {
            if(element==5)
            {
                five++;
            }
            else if(element==10){
                if(five)
                {
                    five--;
                    ten++;
                }else{
                    return 0;
                }
            }
            else{
                if(five && ten)
                {
                    five--;
                    ten--;
                }else if(five>=3){
                    five=five-3;
                }else{
                    return 0;
                }
            }
        }

        return 1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends
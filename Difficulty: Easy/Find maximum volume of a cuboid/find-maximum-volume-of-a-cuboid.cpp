//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    double maxVolume(double perimeter, double area) 
    {
        
        // for fiding the maximum Voulme l=b 
        // Use the S=2(lb+bh+hl)
        // p=4(l+b+h);
        
        // p=4(2l+h)
        //S=2(l^2+lh+lh)
        //S=2(l^2+2lh)
        //h=p/4-2l
        
        //S=2(l^2+2*l(p/4-2l))
        //S/2=(l^2)+2*l(p/4-2l)
        //S/2=(l^2)-4(l^2)+(lp)/2
        //S/2=-3l^2+(lp)/2
        //3l^2-(lp/2)+S/2=0
        //above quadratic needs to be solved
        
        // Find l by formulae ( b+- sqrt(b^2 - 4ac) )/ 2a
        // l = (p - sqrt (p*p - 24*a) ) / 12;
        // let b = h ( for max volume)
        // and h = p/4 -  2*l;
        // and return v = l*l*h;
        double l = (double)(perimeter - sqrt(perimeter*perimeter - 24*area))/12;              
        double h = perimeter/4 - 2*l;
        double volume = l*l*h;
        return volume;
    }
};

//{ Driver Code Starts.
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        double perimeter, area;
        cin >> perimeter >> area;
        // if (area == 5 and parameter == 15) {
        //     cout << "0.46" << endl;
        //     return 0;
        // }
        Solution ob;
        double ans = ob.maxVolume(perimeter, area);
        cout.precision(2);
        cout << fixed << ans << "\n";
    }
}
// } Driver Code Ends
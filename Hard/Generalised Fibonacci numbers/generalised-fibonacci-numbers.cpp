//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  /*
  Easy c++ solution with explaination -

Que : 

find nth element of series with modulo m-

F(n) = a*F(n-1) + b*F(n-2) + c where F(1) = 1 and F(2) = 1

Approach :

What do we use to find nth fibonacci number?

ans -> use DP (only applicable if n is small <1e6)

What if n>1e6? Let's say 1e13!!

ans -> matrix exponentiation

What is Matrix Exponentiation?
Do you know binary exponentiation? It is nothing but we raise a number num to the power n in log n time complexity!!

Here is code for binary exponentiation:

long long power(long long num, long long n, long long mod)
{
   long long ANS = 1LL;
   while (b)
   {
      if (b & 1)
         ANS = (ANS * 1LL * num) % mod;
      num = (num * 1LL * num) % mod;
      b >>= 1;
   }
   return ANS;
}
Fibonacci is-

F(n) = F(n-1) + F(n-2) where F(1)=0 and F(2) = 1

In similar way with proper construction of a matrix and using same approach we can find nth fibonacci even if n is very high in log n time only!

Matrix = [[1 1]

                  [1 0]]

Likewise in this question we will find a matrix,

Matrix = [[a b c]

                     [1 0 0]

                     [0 0 1]]
  */
  
  
  
    vector<vector<long long>> multiply(vector<vector<long long>> &mat1,vector<vector<long long>> &mat2,long long &m){
      vector<vector<long long>> ans(3,vector<long long>(3,0));
      for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            for (int k = 0; k < 3; ++k)
                ans[i][j] = (ans[i][j] + mat1[i][k] * mat2[k][j])%m;
       return ans;
  }
  vector<vector<long long>> power(vector<vector<long long>> &mat,long long n,long long &m){
      vector<vector<long long>> ans(3,vector<long long> (3,0));
      ans[0][0]=ans[1][1]=ans[2][2]=1;
      while(n){
          if(n%2)ans=multiply(ans,mat,m);
          mat=multiply(mat,mat,m);
          n>>=1;
      }
      return ans;
  }
    long long genFibNum(long long a, long long b, long long c, long long n, long long m) {
        // code here
        if(n<=2)return 1;
        vector<vector<long long>> mat={{a,b,c},{1,0,0},{0,0,1}};
        auto ans=power(mat,n-2,m);
        return (ans[0][0]+ans[0][1]+ans[0][2])%m;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long a,b,c,n,m;
        
        cin>>a>>b>>c>>n>>m;

        Solution ob;
        cout << ob.genFibNum(a,b,c,n,m) << endl;
    }
    return 0;
}
// } Driver Code Ends
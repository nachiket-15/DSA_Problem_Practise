//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution{
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        
        //We will require disjoint Set ds for solving this problem
        int n=accounts.size();
        
        DisjointSet ds(n);
        
        unordered_map<string,int>mapMailNode;
        //We will perform required mapping
        for(int i=0;i<n;i++)
        {
            //As i/p vector has first account name and then all mail id's
            //So as currently we are interested in mapping mails to nodes
            //Hence we start in next loop(for iterating vector inside vector) from index 1
            
            for(int j=1;j<accounts[i].size();j++)
            {
                string mail=accounts[i][j];
                //If mail don't exists in map , add them
                if(mapMailNode.find(mail)==mapMailNode.end())
                {
                    mapMailNode[mail]=i;
                }
                //Else union them in a graph
                else{
                    //Unite current node with node that previously exists for that mail
                    ds.unionByRank(i,mapMailNode[mail]);
                }
            }
        }    
            //Now we will iterate over mapping mapMailNode 
            //And we will perform process of merging mails
            //We will merge all mails with their ultimate parents 
            
            //For storing them we will require an array of vectors
            vector<string>mergedMails[n];
            
            //Now iterate over mapping
            for(auto it:mapMailNode){
                string mail=it.first;
                int ultimateParentNode=ds.findUPar(it.second);
                
                mergedMails[ultimateParentNode].push_back(mail);
            }
            
            //Now we need to create an ans vector , which has account name in starting and then merged mails
            vector<vector<string>>ans;
            
            for(int i=0;i<n;i++)
            {
                if(mergedMails[i].size()==0)continue;
                
                sort(mergedMails[i].begin(),mergedMails[i].end());
                vector<string>temp;
                
                string accName=accounts[i][0];
                temp.push_back(accName);
                
                for(auto it:mergedMails[i]){
                    temp.push_back(it);
                }
                
                ans.push_back(temp);
            }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<vector<string>> accounts;

    for (int i = 0; i < n; i++)
    {
      vector<string> temp;
      int x;
      cin >> x;

      for (int j = 0; j < x; j++)
      {
        string s1;
        cin >> s1;
        temp.push_back(s1);
      }
      accounts.push_back(temp);
    }

    Solution obj;
    vector<vector<string>> res = obj.accountsMerge(accounts);
    sort(res.begin(), res.end());
    cout << "[";
    for (int i = 0; i < res.size(); ++i)
    {
      cout << "[";
      for (int j = 0; j < res[i].size(); j++)
      {
        if (j != res[i].size() - 1)
          cout << res[i][j] << ","
               << " ";
        else
          cout << res[i][j];
      }
      if (i != res.size() - 1)
        cout << "], " << endl;
      else
        cout << "]";
    }
    cout << "]"
         << endl;
  }
}
// } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;
//                               Disjoint Set
class DisjointSet{
    vector<int>rank,parent;  //Array rank is maintained to keep our tree of limited height
    public:
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i = 0;i<=n;i++){
            parent[i] = i;
        }
    }
    int findUltParent(int node){
        if(parent[node]==node){
            return node;
        }
        parent[node] = findUltParent(parent[node]);
        return parent[node];
    }
    void unionByRank(int u,int v){
        int ultParU = findUltParent(u);
        int ultParV = findUltParent(v);
        if(ultParU==ultParV){
            return;
        }
        if(rank[ultParU]<rank[ultParV]){
            parent[ultParU] = ultParV;
        }
        else if(rank[ultParU]>rank[ultParV]){
            parent[ultParV] = ultParU;
        }
        else{
            parent[ultParV] = ultParU;
            rank[ultParU]++;
        }
    }
};

//                              nth Fibonacci number in O(logn)
vector<vector<long long>> matMul(vector<vector<long long>>a, vector<vector<long long>>b){
    vector<vector<long long>>ans(a.size(),vector<long long>(b[0].size(),0));
    for(int i = 0;i<a.size();i++){
        for(int j = 0;j<b[0].size();j++){
            for(int k = 0;k<b.size();k++){
                ans[i][j] += a[i][k]*b[k][j];
            }
        }
    }
    return ans;
}
vector<vector<long long>> binaryMatExp( vector<vector<long long>>a,int n){
    int l = 2;
    if(n==0){
        // return identity mat
        vector<vector<long long>>ans(l,vector<long long>(l,0));
        for(int i = 0;i<l;i++){
            a[i][i] = 1;
        }
        return ans;
    }
    if(n==1){
        return a;
    }
    vector<vector<long long>>ans = binaryMatExp(a,n/2);
    ans = matMul(ans,ans);
    if(n%2==0){
        return ans;
    }
    return matMul(ans,a);
}
int fib(long long n)
{   //tc of dp sol ->O(n) 

    //binary mat exp -->O(logn) 
    vector<vector<long long>>a = {{1,1},{1,0}};
    a = binaryMatExp(a,n);
    return a[0][1];
}

//                       Strongly connected components(kosaraju algorithm)

void dfs(int node,vector<vector<int>>&adj,vector<bool>&visited){
    visited[node] = true;
    for(auto it:adj[node]){
        if(!visited[it]){
            dfs(it,adj,visited);
        }
    }
}
void dfs(int node,vector<vector<int>>&adj,vector<bool>&visited,stack<int>&st){
    visited[node] = true;
    for(auto it:adj[node]){
        if(!visited[it]){
            dfs(it,adj,visited,st);
        }
    }
    st.push(node);
}
int kosaraju(int n,vector<vector<int>>&adj){
    // step 1 : sort on basis of time in stack
    stack<int>st;
    vector<bool>visited(n,false);
    for(int i = 0;i<n;i++){
        if(!visited[i]){
            dfs(i,adj,visited,st);
        }
    }

    // step 2 : reverse the graph
    vector<vector<int>>rev(n);
    for(int i = 0;i<n;i++){
        visited[i] = false;
        for(auto it:adj[i]){
            rev[it].push_back(i);
        }
    }

    // step 3 : count scc
    int scc = 0;
    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(!visited[node]){
            scc++;
            dfs(node,rev,visited);
        }
    }

    return scc;

}

//  	                Count Inversions in nlogn
long long merge(vector<long long>&nums,long long s1,long long e1,long long s2,long long e2){
  vector<long long>a(e2-s1+1);
  long long ans = 0;
  long long i=0,p1=s1,p2=s2;
  while(p1<=e1 && p2<=e2){
    if(nums[p1]<=nums[p2]){
      a[i]=nums[p1];
      p1++;
    }
    else{
      a[i]=nums[p2];
      ans+=(e1-p1+1);
      p2++;
    }
    i++;
  }
  while(p1<=e1){
    a[i] = nums[p1];
    p1++;
    i++;
  }
  while(p2<=e2){
    a[i] = nums[p2];
    p2++;
    i++;
  }
  for(long long i = s1;i<=e2;i++){
    nums[i] = a[i-s1];
  }
  return ans;
}
long long countInversion(vector<long long>&nums,long long s,long long e){
  if(s>=e)return 0;
  long long mid = (s+e)/2;
  return countInversion(nums,s,mid)+countInversion(nums,mid+1,e)+merge(nums,s,mid,mid+1,e);
}
long long countInversions(vector<long long> &nums) {
  return countInversion(nums,0,nums.size()-1);
}


//                              KMP
bool knuthMorrisPrattAlgorithm(string str, string substr){
    // building pattern
    int l = substr.size();
    vector<int> pattern(l, -1);
    int j = 0, i = 1;
    while (i < l){
        if (substr[i] == substr[j]){
            pattern[i] = j;
            i++;
            j++;
        }
        else if (j > 0){
            j = pattern[j - 1] + 1;
        }
        else{
            i++;
        }
    }

    // pattern
    for (auto k : pattern){
        cout << k << " ";
    }

    // string matching
    i = 0;
    j = 0;
    while (j != l && i < str.size()){
        if (str[i] == substr[j]){
            i++;
            j++;
        }
        else if (j > 0){
            j = pattern[j - 1] + 1;
        }
        else{
            i++;
        }
    }
    return j == l;
}

//        String Hashing (codeforces 271D -->without hashing MLE if we store string in set)
#include <bits/stdc++.h>
using namespace std;

//  hashed using 2 bases to avoid collisions!!
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    // defining variables for hashing 
    const int p1=31,p2 = 29,m=1e9+9;
    
    // taking input
    string s,good;
    cin>>s>>good;
    int maxbad;
    cin>>maxbad;
    
    // set to store unique strings hash values
    set<pair<int,int>>unique;
    
    for(int i = 0;i<s.size();i++){
        int hash1 = 0,hash2=0;
        long long pp1 = 1,pp2=1;
        
        int bad = 0;
        
        for(int j = i;j<s.size();j++){
            // hashing
            hash1 = (hash1+(s[j]-'a'+1)*pp1)%m;
            hash2 = (hash2+(s[j]-'a'+1)*pp2)%m;
            pp1=(pp1*p1)%m;
            pp2=(pp2*p2)%m;
            
            if(good[(s[j]-'a')]=='0'){
                bad++;
            }
            
            if(bad<=maxbad){
                unique.insert({hash1,hash2});
            }
            else{
                break;
            }
            
        }
    }
    // print number of unique strings possible
    cout<<unique.size()<<endl;

    return 0;
}

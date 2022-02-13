#include <bits/stdc++.h>
using namespace std;
#define fast_io {\
                ios_base::sync_with_stdio(false);\
                cin.tie(0);\
                cout.tie(0);}
#define rep(i,a,b) for(int i=a ; i<(b) ; ++i )
#define endl "\n"
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define debug(x) cout<<#x<<" : "<<x<<"\n";
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<int> vi;
using set_pointer = set<int>*;
vector<vi> tree;
vi color;
vi res;
vector<bool> vis;
// vector<> memo;
set_pointer dfs(int node){
    
    // no base case because condition is applied over the reccerence calling //
    // reccuernce will be called only on reccursive cases //
    set_pointer ans = new set<int>();
    if(vis[node])return ans;
    vis[node] = 1;
 
    ans->insert(color[node]); // or (*ans).insert(color[node]);
    for(auto x: tree[node]){
        if(!vis[x]){
            set<int>* sub = dfs(x);
            for(auto itr=sub->begin();itr!=sub->end();++itr){
                ans->insert(*itr); 
            }
        }
    }
    
    
    res[node] = ans->size();
    // memo[node] = ans;
    return ans;
}
 
void solve(){
  int n, root = 1;
  cin>>n;
  
//   memo.resize(n+1);
  color.resize(n+1);
  tree.resize(n+1);
  res.resize(n+1);
  vis.resize(n+1, 0);
  
  rep(i,1,n+1)  cin>>color[i];
  
  rep(i,0,n-1){
      int u, v;
      cin>>u>>v;
      tree[u].eb(v);
      tree[v].eb(u);
  }
  
  auto temp = dfs(root);
  
  rep(i,1,n+1)
  cout<<res[i]<<" ";
  
}
 
int main() {
	fast_io;
	ll t=1;
// 	cin>>t;
	rep(i,1,t+1)
	{
	   // cout<<"Case: #"<<t<<"\n";
	    solve();
	}
	return 0;
}
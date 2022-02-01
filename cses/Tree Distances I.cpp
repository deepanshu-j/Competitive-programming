#include <bits/stdc++.h>
using namespace std;
#define fast_io {\
                ios_base::sync_with_stdio(false);\
                cin.tie(0);\
                cout.tie(0);}
#define rep(i,a,b) for(ll i=a ; i<(b) ; ++i )
#define endl "\n"
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define debug(x) cout<<#x<<" : "<<x<<"\n";
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
 
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

unordered_map<pair<int, int>, int, hash_pair> memo;
vi res;
vector<bool> vis;
vector<vi> tree;
vi depth; 
 
void dfs(int node, int parent){ 
    
    if(vis[node]) return; // POE
    
    // cout<<"node: "<<node<<" , parent: "<<parent<<"\n";
    vis[node] = 1;

    // precomputation // for prefix and suffix for rerooting //
    
    vi child;
    rep(i,0,tree[node].size())
    if(!vis[ tree[node][i] ]) child.eb(tree[node][i]);
    
    int sz = child.size();
    
    vi prefix(sz, 0), suffix(sz, 0);
    int _pre = 0, _suff = 0;
    
    // Computing Prefix //
    rep(i,0,sz){
        _pre = max(_pre, depth[ child[i] ]);
        prefix[i] = _pre;
    }
    // Computing Suffix //    
    for(int i=sz-1; i>=0 ; --i){
        _suff = max(_suff, depth[ child[i] ]);
        suffix[i] = _suff; 
    }
    
    // if(node ==4){
    
    //     cout<<"\nCHILD of node 4\n";
    //     rep(i,0,sz) cout<<child[i]<<" ";
        
    //     cout<<"\nPREFIX\n";
    //     rep(i,0,sz) cout<<prefix[i]<<" ";
        
    //     cout<<"\nSUFFIX\n";
    //     rep(i,0,sz) cout<<suffix[i]<<" ";
        
    // }
    
    rep(i,0,sz){
        int pre = (i>0) ? prefix[i-1] : 0 ; 
        int suff = (i+1<sz) ? suffix[i+1] : 0;
        memo[{ node, child[i] }] = 1 + max({ 0,
            pre, // POE maybe INT_MIN  
            suff,
            (parent!=-1) ? ( memo[{parent, node}] ): 0 
            });
            
        // cout<<"MEMO: node: "<<node<<" , child: "<<child[i]<<" , val: "<<memo[{ node, child[i]}]<<"\n";
    }
    
    int ans = 0;
    
    ans = max(ans, depth[node]);
    
    if(parent!=-1){
        ans = max({ans, 1+memo[{parent, node}] }); // ans of the parent without considering this node's subtree  
    }
        
    if(parent!=-1)
    res[node] = ans;

    for(auto x: tree[node])
        dfs(x, node);
    
}
 
int depth_fn(int root){
    
    if(vis[root]) return 0;
    vis[root] = 1;
    
    int m = 0;
    for(auto x: tree[root]){
        if(!vis[x])
        m = max(m, depth_fn(x) );
    }
    return depth[root] = 1+m;
} 
 
void solve(){
    int n;
    cin>>n;
    
    res.resize(n+1);
    tree.resize(n+1);
    vis.resize(n+1, 0);
    depth.resize(n+1, 0);
    
    rep(i,0,n-1){
        int u, v;
        cin>>u>>v;
        
        tree[u].pb(v);
        tree[v].pb(u);
    }
    
    // cout<<"\n**********TREE (in AdjList)************\n";
    // rep(i,1,n+1){
    //     cout<<"for i: "<<i<<" , ";
    //     for(auto x: tree[i])cout<<x<<" ";
    //     cout<<endl;
    // }
    
    int root = 1;
    int temp = depth_fn(root);
    
    res[root] = depth[root];
    
    vis.clear();
    vis.resize(n+1, 0);
    
    dfs(root, -1);
    
    // Print Result //
    rep(i,1,n+1)
    cout<<res[i]-1<<" ";

}
signed main() {
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
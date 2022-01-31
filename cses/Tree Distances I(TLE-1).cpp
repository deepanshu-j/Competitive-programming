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
typedef pair<ll,ll> pii;
typedef vector<ll> vi;
#define inf -1000000

unordered_map<string, int> memo;
vi res;
vector<bool> vis;
vector<vi> tree;

int dfs(int node, int parent){ // the parent with whose respect we wanna calculate the ans 
// basically in the direction of parent to this node side //
    
    
    if(vis[node]) return 0;// POE
    
    // cout<<"node: "<<node<<" , parent: "<<parent<<"\n";
    vis[node] = 1;
   
    
    string key = to_string(node)+ " " + to_string(parent);
    
    if(parent != -1 and memo.count(key) != 0)
        return memo[key];
    
    
    int ans = 0;
    for(auto x: tree[node]){
        ans = max(ans, dfs(x, node) );// this is what we wanna store //
    }
    ++ans;
    if(parent!=-1){
        return memo[key] = ans;
    }else return ans;
    
    // vis[node] = 0;// POE
}

void solve(){
    int n;
    cin>>n;
    
    res.resize(n+1);
    tree.resize(n+1);
    vis.resize(n+1, 0);
    
    rep(i,0,n-1){
        int u, v;
        cin>>u>>v;
        
        tree[u].pb(v);
        tree[v].pb(u);
    }
    
    // rep(i,1,n+1){
    //     cout<<"for i: "<<i<<" , ";
    //     for(auto x: tree[i])cout<<x<<" ";
    //     cout<<endl;
    // }
    // cout<<"\n***************\n";
    
    rep(i,1,n+1){
        vis.clear();
        vis.resize(n+1, 0);
        res[i] = dfs(i, -1);
        // cout<<"\n***************\n";
    }
    
    // Print ANS //
    rep(i,1,n+1)
    cout<<res[i]-1<<" ";
    
}
signed main() {


    // freopen("in.txt" , "r" , stdin) ;
    // freopen("out.txt" , "w" , stdout) ;

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

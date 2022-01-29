/*      AUTHOR: Deepanshu Johar 
        codeforces: Dj46
*/
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
#define fast_io {\
                ios_base::sync_with_stdio(false);\
                cin.tie(0);\
                cout.tie(0);}
#define rep(i,a,b) for(int i=a ; i<(b) ; ++i )
#define endl "\n"
#define pb push_back
#define ff first
#define ss second
#define debug(x) cout<<#x<<" : "<<x<<"\n";
#define all(x) x.begin(), x.end()
using ll = long long;
typedef pair<ll,ll> pii;
typedef vector<int> vi;
const ll MOD = 1e9 + 7;

vector<vi> tree;
vi vis;
map<int,int> parent;
int up[200001][21];

// Populate up table //
void dfs(int node){
    
    if(vis[node])return;
    
    vis[node] = 1;
    
    up[node][0] = parent[node];
    
    rep(i,1,21){
        // cout<<"node: "<<node<<" i-1: "<< i-1<<" up[node][i-1]: "<< up[node][i-1]<<endl;
        if(up[node][i-1]!=-1){
            up[node][i] = up[ up[node][i-1] ][i-1];
        }
        else
            up[node][i] = -1;
    }
    
    for(auto _node: tree[node] )
        dfs(_node);
}
void solve(){
    int n, q;
    cin>>n>>q;
    
    tree.resize(n+1);
    memset(up, -1, sizeof up);
    
    rep(i,2,n+1){
        int e ;
        cin>>e;
        
        parent[i] = e;
        tree[i].pb(e);
        tree[e].pb(i);
    }
    parent[1] = -1;
    
    vis.resize(n+1, 0);
    
    dfs(1);
    
    while(q--){
        int x, k;
        cin>>x>>k;
    
        rep(i,0,21){
            if(k & (1<<i)){
                x = up[x][i];
                if(x==-1)
                break;
            }
        }
        
        cout<<x<<"\n";
    }
    
}
signed main() {
    
    //OPTIMIZE

    // freopen("in.txt" , "r" , stdin) ;
    // freopen("out.txt" , "w" , stdout) ;
	
    fast_io;
	int t=1;
	// cin>>t;
	while(t--)
	{
	    solve();
	}
	return 0;
}
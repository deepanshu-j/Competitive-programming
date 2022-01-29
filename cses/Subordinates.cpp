#include <bits/stdc++.h>
using namespace std;
#define fast_io {\
                ios_base::sync_with_stdio(false);\
                cin.tie(0);\
                cout.tie(0);}
#define rep(i,a,b) for(ll i=a ; i<(b) ; ++i )
#define endl "\n"
#define pb push_back
#define ff first
#define ss second
#define debug(x) cout<<#x<<" : "<<x<<"\n";
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

vector<vector<int>> tree;
vector<int> res;
vector<bool> vis;

int dp(int node){
    
    // base case // Leaf node //
    if(tree[node].size()==0){
        res[node] = 0;
        return res[node]+1;
    }
    
    if(vis[node])
        return res[node];
        
    vis[node] = 1;
    
    int ans =0 ;
    for(auto x: tree[node]){
        ans += dp(x);
    }
    
    res[node] = ans;
    return res[node]+1;
}

void solve(){
    int n;
    cin>>n;
    if(n==1){
        cout<<"0";
        return;
    }
    
    tree.resize(n+1);
    vis.resize(n+1, 0);
    res.resize(n+1, 0);
    
    rep(i,2,n+1){
        int u;
        cin>>u;
        
        tree[u].pb(i);
        tree[i].pb(u);
    }
    
    int temp = dp(1);
    
    // debug(temp);
    rep(i,1,n+1)cout<<res[i]<<" ";
    
}
signed main() {
	fast_io;
	int t=1;
// 	cin>>t;
	while(t--)
	{
	    solve();
	}
	return 0;
}

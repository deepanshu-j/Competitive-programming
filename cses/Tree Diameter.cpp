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

int g = -1;
vector<bool> vis;
int dp(int node){
    
    if(vis[node])
        return 0;
    vis[node]=1;
    
    vector<int> sub;
    for(auto x: tree[node]){
        sub.pb(dp(x));
    }
    
    if(sub.size())
    sort(all(sub), greater<int>());
    
    if(sub.size()>1){
        int pivot = 1 + sub[0] + sub[1];
        g = max({g, pivot});
    }
    
    // return the longest branch going through this node
    if(sub.size()>0){
        g = max({g, sub[0]+1});
        return sub[0]+1;
    }
    return 1;
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
    rep(i,0,n-1){
        int u, v;
        cin>>u>>v;
        
        tree[u].pb(v);
        tree[v].pb(u);
    }
    
    int temp = dp(1);
    
    cout<<g-1;
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

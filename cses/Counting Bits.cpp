#include <bits/stdc++.h>
using namespace std;
#define fast_io {\
                ios_base::sync_with_stdio(false);\
                cin.tie(0);\
                cout.tie(0);}
#define rep(i,a,b) for(ll i=a ; i<(b) ; ++i )
#define pb push_back
typedef long long ll;
typedef pair<ll,ll> pii;
typedef vector<ll> vi;

void solve(){
    ll n;
    cin>>n;
    ++n;
    ll res = 0;
    
    rep(i,0,55){
        
        
        ll _2p = 1LL<<i;
        ll g = n / _2p;
        
        ll rem = n % _2p;
        if(g&1){
            res+= rem;
        }
        g/=2;
        g*=_2p;
        
        
        res +=  g;
        
    }
    cout<<res;
}
signed main() {
	fast_io;
	ll t=1;
    // 	cin>>t;
	while(t--)
	{
	    solve();
	}
	return 0;
}

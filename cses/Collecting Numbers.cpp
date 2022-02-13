/*      AUTHOR: Deepanshu Johar 
        codeforces: Dj46
*/
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
void solve(){
    int n;
    cin>>n;
    
    vi a(n);
    vi idx(n+1);
    rep(i,0,n){
        cin>>a[i];
        idx[a[i]]=i;
    }
    
    int ans=1;
    rep(i,1,n){
        if(idx[i]>idx[i+1])++ans;
    }
    cout<<ans;
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

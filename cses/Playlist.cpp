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
    rep(i,0,n)cin>>a[i];
    
    map<int,int> mp;
    
    int res=1;
    int i=0,j=0;
    mp[a[0]]++;
    while(i<=j and j<n){
        // cout<<"i:"<<i<<" ,j:"<<j<<"\n";

        res=max(res, j-i+1);
        ++j;
        mp[a[j]]++;
        
        if(mp[a[j]]>1){
            while(mp[a[j]]>1 and i<=j){
                mp[a[i]]--;
                i++;
            }
        }
    }
    cout<<res<<"\n";
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

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
void solve(){
    int n;
    cin>>n;
    
    vi a(n);
    int x= 0;
    rep(i,0,n){
        cin>>a[i];
        x^=a[i];
    }
    
    if(x)
        cout<<"first\n";
    else
        cout<<"second\n";
}
signed main() {
	fast_io;
	int t=1;
	cin>>t;
	while(t--)
	{
	    solve();
	}
	return 0;
}

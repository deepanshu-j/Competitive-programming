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
#define rep(i,a,b) for(ll i=a ; i<(b) ; ++i )
#define endl "\n"
#define pb push_back
#define ff first
#define ss second
#define endl "\n"
#define debug(x) cout<<#x<<" : "<<x<<"\n";
#define all(x) x.begin(), x.end()
using ll = long long;
typedef pair<ll,ll > pii;
typedef vector<ll> vi;
const ll MOD = 1e9 + 7;

ll binPow(ll a,ll n)
{
    ll res=1;
    while(n)
    {
        if(n&1)
            res=(1LL*res*a)%MOD;
        a=(1LL*a*a)%MOD;
        
        n>>=1;
    }
    return res;
}

///this calculated ncr%MOD///
ll ncr(ll n,ll r,vector<ll> &fact,vector<ll> &inv)
{
    /// ///
    if(r>n)
    return 0;
    
    ll multiply=( 1LL * fact[n] * inv[r] )%MOD;
    multiply=(1LL * multiply * inv[n-r] )%MOD;
    
    return multiply;
    //this function returns an lleger because value of MOD can be contained in an lleger
    //but to avoid error we are using 1LL //which does the multiplication like as if ll//
}
ll add(ll i, ll j) {
	if ((i += j) >= MOD)
		i -= MOD;
	return i;
}
ll gcdExtended(ll a, ll b, ll *x, ll *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
 
    ll x1, y1; // To store results of recursive call
    ll gcd = gcdExtended(b%a, a, &x1, &y1);
 
    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd;
}
ll modInverse(ll b, ll m)
{
    ll x, y; // used in extended GCD algorithm
    ll g = gcdExtended(b, m, &x, &y);
 
    // Return -1 if b and m are not co-prime
    if (g != 1)
        return -1;
 
    // m is added to handle negative x
    return (x%m + m) % m;
}

// Function to compute a/b under modulo m
ll modDivide(ll a, ll b, ll m)
{
    a = a % m;
    ll inv = modInverse(b, m);
    if (inv == -1)
    //  prllf ("Division not defined");
    return -1;
    else
    {
      ll c = (inv * a) % m ;
    //   prllf ("Result of division is %d", c) ;
    return c;
    }
}



void solve(){
 
    ll n;
    cin>>n;
    
    if(n&1){
        cout<<"0";
        return;
    }
    
    ///calc fact and inv vector///
    
    vector<ll> fact(n+1,1LL);
    vector<ll> inv(n+1,1LL);
    
    for(ll i=1;i<=n;++i)
    {
        fact[i]=(fact[i-1]*i)%MOD;
        inv[i]=binPow(fact[i],MOD-2);
    }
    
    //now you can use ncr directly here//
    
    n>>=1;
    ll res = ncr(2*n, n, fact, inv);
    
    res = modDivide(res, n+1, MOD);
    cout<<res;
    
}
signed main() {
    
    //OPTIMIZE

    // freopen("in.txt" , "r" , stdin) ;
    // freopen("out.txt" , "w" , stdout) ;
	
    fast_io;
	ll t=1;
// 	cin>>t;
	while(t--)
	{
	    solve();
	}
	return 0;
}
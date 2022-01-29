
// #include<bits/stdc++.h>

// /**
#include<iostream>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <unordered_map>
#include <unordered_set>
// */


using namespace std;
#define fast_io {\
                ios_base::sync_with_stdio(false);\
                cin.tie(0);\
                cout.tie(0);}
#define rep(i,a,b) for(int i=a ; i<(b) ; ++i )
#define pb push_back
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
using ll = long long;
typedef pair<int,int> pii;
typedef vector<int> vi;
const int MOD = 1e9 + 7;

vector<vi> tree;
vi vis;
map<int,int> parent;
void dfs(int node, int par){
    if(vis[node])return;
    
    vis[node] = 1;
    parent[node] = par;
    for(auto _node: tree[node] )
        dfs(_node, node);
};

void solve(){
    int n, q;
    cin>>n>>q;
    
    tree.resize(n+1);
    
    rep(i,2,n+1){
        int e ;
        cin>>e;
        
        tree[i].pb(e);
        tree[e].pb(i);
    }
    
    vis.resize(n+1, 0);
    
    dfs(1, -1);
    
    // rep(i,1,n+1)
    // debug(parent[i]);
    
    
    while(q--){
        int x, k;
        cin>>x>>k;
    
        while(k--){
            if(x==-1){
                cout<<"-1\n";
                break;
            }
            x = parent[x];        
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
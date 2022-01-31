
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
#define rep(i,a,b) for(ll i=a ; i<(b) ; ++i )
#define endl "\n"
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define debug(x) cout<<#x<<" : "<<x<<"\n";
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define inf -1000000
 
// unordered_map<string, int> memo;
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};
unordered_map<pair<int, int>, int, hash_pair> memo;
vi res;
vector<bool> vis;
vector<vi> tree;
 
int tot =0;
int dfs(int node, int parent){ // the parent with whose respect we wanna calculate the ans 
// basically in the direction of parent to this node side //
    
    
    if(vis[node]) return 0;// POE
    
    // cout<<"node: "<<node<<" , parent: "<<parent<<"\n";
    vis[node] = 1;
    
    // string key = to_string(node)+ " " + to_string(parent);
    auto key = make_pair(node, parent);
    
    if(parent != -1 and memo.count(key) != 0)
        return memo[key];
    ++tot;
    
    int ans = 0;
    for(auto x: tree[node]){
        if(!vis[x])
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
    // rep(i,1,n+1)
    // cout<<res[i]-1<<" ";
    cout<<"\n"<<tot;
}
signed main() {

    freopen("test_input.txt" , "r" , stdin) ;
    freopen("out.txt" , "w" , stdout) ;


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
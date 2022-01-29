
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
void solve(){
    int n;
    cin>>n;
    vi a(n);

    rep(i,0,n)cin>>a[i];

    // lets say we wanna make it increasing //

    // hence every element should be as large as the prev el //

    int prev = a[0];
    int res = 0x3f3f3f3f, ans = 0;
    rep(i,1,n){
        if(a[i]<prev){
            ans += prev-a[i];
            a[i] = prev;
        }

        prev = a[i];
    } 
    res = min(res, ans);

    ans = 0;
    prev = a[0];
    rep(i,1,n){
        if(a[i]>prev){
            ans += a[i]-prev;
            a[i] = prev;
        }
        
        prev = a[i];
    } 
    res = min(res, ans);

    cout<<res;

}

signed main() {
    
    //OPTIMIZE

    freopen("in.txt" , "r" , stdin) ;
    freopen("out.txt" , "w" , stdout) ;
	
    fast_io;
	int t=1;
	// cin>>t;
	while(t--)
	{
	    solve();
	}
	return 0;
}
#include <vector>
#include <map>
#include <cstdlib>
#include <fstream>
#include <iomanip>   
#include <iostream>  
#include <sstream>  // istringstream buffer(myString);
#include <stack>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <math.h>
#include <unordered_map>
#include <queue>
#include <array>
#include <set>
#include <numeric>

using namespace std;

typedef long long ll;

#define forn(i, n) for (int i=0; i< (int)n; ++i) 

ll mod = 1e9 + 7;

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n), mnR(n), mnL(n), mxR(n), mxL(n);
    for(int i = 0; i < n; ++i)cin >> a[i];
    ll ans = 0;
    forn(i, n){
        ans = (ans + a[i]*(i + 1) % mod * (n - i) % mod) % mod;
    }
    cout << ans << '\n';
}
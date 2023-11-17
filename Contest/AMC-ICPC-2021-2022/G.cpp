#include <algorithm>
#include <array>
#include <cassert>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream> // istringstream buffer(myString);
#include <stack>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define for1(i, n) for (int i = 1; i <= (int)n; ++i)
#define ford(i, n) for (int i = n - 1; i > -1; --i)
#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define el "\n"

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

vector<ll> fib;
vi fac;

bool sol(ll n, int ind){
    if(n == 1)return true;
    ford(i, ind){
        // cout << fib[i] << el;
        if(n % fib[i] == 0){
            fac.pb(i);
            if(sol(n / fib[i], i + 1))return true;
            fac.pop_back();
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    fib.pb(2);
    ll f = 1;
    ll s = 2;
    while(s <= n){
        ll tmp = s;
        s += f;
        f = tmp;
        fib.pb(s);
        // cout << s << ' ' << s % 9 << el;
    }
    int ind = fib.size();
    if(!sol(n, ind)){
        cout << "IMPOSSIBLE" << el;
        return 0;
    }
    vector<char> ans;
    forn(i, fac.size()){
        forn(j, fac[i] + 1){
            ans.pb('A');
        }
        ans.pb('B');
    }
    forn(i, ans.size()){
        cout << ans[i];
    }
    cout << el;
}
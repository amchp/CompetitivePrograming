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

#define fi first
#define se second
#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define for1(i, n) for (int i = 1; i <= (int)n; ++i)
#define fore(i, l, r) for (int i = (int)l; i <= (int)r; ++i)
#define ford(i, n) for (int i = (int)(n)-1; i >= 0; --i)
#define fored(i, l, r) for (int i = (int)r; i >= (int)l; --i)
#define pb push_back
#define el '\n'
#define d(x) cout << #x << " " << x << el
#define ri(n) scanf("%d", &n)
#define sz(v) ((int)v.size())
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> ii;
typedef pair<char, int> pci;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll inf = 1e18;
const int nax = 200000;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

int n;
ll a[nax];
ll dp[nax];

ll sol(int ind){
    if(ind == n)return 0;
    if(ind == n - 1)return a[ind];
    ll& v = dp[ind];
    if(v != inf)return v;
    // if(a[ind] == 0)v = min(v, sol(ind + 1));
    if(ind <= n - 2){
        v = min(v, sol(ind + 2) + max(a[ind], a[ind + 1]));
    }
    if(ind <= n - 3){
        ll val;
        vector<pll> sA;
        forn(i, 3){
            sA.pb({a[ind + i], i});
        }
        sort(all(sA));
        if(sA[0].second == 1){
            val = sA[1].first + sA[2].first;
        }else{
            val = sA[0].first + sA[2].first;
        }
        v = min(v, sol(ind  + 3) + val);
    }
    return v;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    cin >> n;
    forn(i, n){
        cin >> a[i];
        dp[i] = inf;
    }
    cout << sol(0) << el;
}

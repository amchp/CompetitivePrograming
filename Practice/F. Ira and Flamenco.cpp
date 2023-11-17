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
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi; // int vec
typedef vector<ll> vll; // int vec
typedef vector<vi> vvi; // int vec vec
typedef vector<vll> vvll; // int vec
typedef vector<pii> vpi; // int int pair vec
typedef vector<pll> vpll; // int int pair vec

const double pi = 3.1415926535897932384626433832795;
const int maxn = 2e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ll INFLL = 1000000000000000005LL;
const ld EPS = 1e-9;
int dirx[8] = { -1, 0, 0, 1, -1, -1, 1, 1 };
int diry[8] = { 0, 1, -1, 0, -1, 1, -1, 1 };

#define d(x) cout << #x << " = " << x << endl;
#define ios ios_base::sync_with_stdio(0), cin.tie(0);
#define forn(i, n) for (int i=0; i< (int)n; ++i) 
#define forab(i, a, b) for (int i=a; i< (int)b; ++i) 
#define foreach(a, b) for (auto&(a) : (b))
#define formap(map) for (const auto &[key, value] : map)
#define all(v) v.begin(), v.end()
#define allar(arr, sz) arr, arr + sz
#define ms(ar, val) memset(ar, val, size)
#define pq(type) priority_queue<type> 
#define pqd(type) priority_queue<type,vector<type>,greater<type> >
#define umap unordered_map
#define uset unordered_set
#define imax INT_MAX
#define imin INT_MIN
#define pb push_back
#define mp make_pair
#define fi first 
#define se second 
#define nl "\n"
#define in(t) while (t--)

ll fact[maxn];

ll bin_pow(ll a, ll b){
    if(b == 0)return 1LL;
    ll bp = bin_pow(a, b/2);
    bp *= bp;
    bp %= MOD;
    if(b % 2){
        bp *= a;
        bp %= MOD;
    }
    return bp;
}

ll inverse_mod(ll num){
    return bin_pow(num, MOD-2LL);
}

ll comb(ll n, ll r){
    // cout << fact[r] << ' ' << fact[n - r] << nl;
    // cout << inverse_mod(fact[r] * fact[n - r] % MOD) << nl;
    // return 0;
    return (fact[n] * inverse_mod(fact[r] * fact[n - r] % MOD)) % MOD;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    fact[0] = 1;
    forab(i, 1, maxn)fact[i] = fact[i - 1] * i % MOD;
    int t;
    cin >> t;
    in(t){
        int n;
        ll m;
        cin >> n >> m;
        vll a(n);
        forn(i, n)cin >> a[i];
        sort(all(a));
        vll mul;
        mul.pb(1);
        ll num = 1;
        forn(i, n - 1){
            if(a[i] == a[i + 1]){
                num++;
                continue;
            }
            mul.pb(num);
            num = 1;
            mul[mul.size() - 1] *= mul[mul.size() - 2];
            mul[mul.size() - 1] %= MOD;
        }
        mul.pb(num);
        mul[mul.size() - 1] *= mul[mul.size() - 2];
        mul[mul.size() - 1] %= MOD;
        a.resize(distance(a.begin(), unique(all(a))));
        // forn(i, a.size()){
        //     cout << a[i] << ' ';
        // }
        // cout << nl;
        // forn(i, a.size()){
        //     cout << mul[i] << ' ';
        // }
        // cout << nl;
        ll l = 0;
        ll r = 0;
        ll ans = 0;
        while(r < a.size()){
            while(r < a.size() && a[r] - a[l] < m){
                r++;
            }
            if(r - l < m){
                l++;
                continue;
            }
            // cout << l << ' ' << r << ' ';
            // cout << comb(r - l, m) << nl;
            ans += (comb(r - l, m) * ((mul[r] * inverse_mod(mul[l])) % MOD)) % MOD;
            ans %= MOD;
            l++;
        }
        cout << ans << nl;
    }
}

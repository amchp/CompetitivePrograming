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

int n, k, x;
int a[maxn];
ll dp[maxn][21];

int sol(int i, int k){
    if(i == n){
        return 0;
    }
    if(dp[i][k] != -1){
        return dp[i][k];
    }
    ll nt = max(sol(i + 1, k) + (ll)a[i] - x, (ll)a[i] - x);
    if(k == 0){
        return nt;
    }
    ll t = max(sol(i + 1, k - 1) + (ll)a[i] + x, (ll)a[i] + x);
    dp[i][k] = max(t, nt);
    return dp[i][k];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    in(t){
        cin >> n >> k >> x;
        forn(i, n) cin >> a[i];
        memset(dp, -1, sizeof(dp));
        sol(0, k);
        ll ans = 0;
        forn(i, n){
            forn(j, min(n - i, k + 1)){
                // cout << dp[i][j] << nl;
                ans = max(ans, dp[i][j]);
            }
        }
        // forn(i, n){
        //     forn(j, k){
        //         cout << dp[i][j] << ' ';
        //     }
        //     cout << nl;
        // }
        cout << ans << nl;
    }
}
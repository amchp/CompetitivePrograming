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
const int maxn = 1e3 + 5;
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

double dp[maxn];
vi a[maxn];
double probability[maxn];
vector<int> g[maxn];

ll pow2(ll a){
    return a*a;
}

double dfs(int i){
    if(dp[i] != -1)return dp[i];
    double mXN = 0;
    forn(j, g[i].size()){
        mXN = max(mXN, dfs(g[i][j]));
    }
    dp[i] = probability[i] + mXN;
    return dp[i];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int n;
    cin >> n;
    int x, y, t;
    double p;
    forn(i, n){
        cin >> x >> y >> t >> p;
        dp[i] = -1;
        a[i].pb(t);
        a[i].pb(x);
        a[i].pb(y);
        probability[i] = p;
    }
    // forn(i, n){
    //     cout << a[i][0] << ' ' << a[i][1] << ' ' << a[i][2] << nl;
    // }
    forn(i, n){
        forn(j, n){
            if(i == j || a[j][0] - a[i][0] < 0)continue;
            // cout << abs(a[j][0] - a[i][0]) << ' ' << (abs(a[j][1] - a[i][1]) + abs(a[j][2] - a[i][2])) << nl;
            if(a[j][0] - a[i][0] >= sqrt((pow2(a[j][1] - a[i][1]) + pow2(a[j][2] - a[i][2])))){
                g[i].pb(j);
            }
        }
    }
    // forn(i, n){
    //     cout << i << " : ";
    //     forn(j, g[i].size()){
    //         cout << g[i][j] << ' ';
    //     }
    //     cout << nl;
    // }
    double mx = 0;
    forn(i, n){
        mx = max(mx, dfs(i));
    }
    cout << mx << nl;
}
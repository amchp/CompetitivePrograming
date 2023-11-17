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
int dirx[2] = { 1, 0};
int diry[2] = { 0, 1};

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


void sol(){
    int n, m;
    cin >> n >> m;
    vvi a(n, vi(m));
    forn(i, n){
        forn(j, m){
            cin >> a[i][j];
        }
    }
    if((n + m) % 2 == 0){
        cout << "NO" << nl;
        return;
    }
    vvi mx(n, vi(m)), mn(n, vi(m));
    mx[0][0] = a[0][0];
    mn[0][0] = a[0][0];
    forab(i, 1, n){
        mx[i][0] = mx[i - 1][0] + a[i][0];
        mn[i][0] = mn[i - 1][0] + a[i][0];
    }
    forab(j, 1, m){
        mx[0][j] = mx[0][j - 1] + a[0][j];
        mn[0][j] = mn[0][j - 1] + a[0][j];
    }
    forab(i, 1, n){
        forab(j, 1, m){
            mx[i][j] = a[i][j] + max(mx[i - 1][j], mx[i][j - 1]);
            mn[i][j] = a[i][j] + min(mn[i - 1][j], mn[i][j - 1]);
        }
    }
    if(!(mx[n - 1][m - 1] < 0 || 0 < mn[n - 1][m - 1]))cout << "YES" << nl;
    else cout << "NO" << nl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int t;
    cin >> t;
    in(t){
        sol();
    }
}
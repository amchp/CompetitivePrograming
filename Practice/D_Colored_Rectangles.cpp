#include <vector>
#include <map>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream> // istringstream buffer(myString);
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
#include <complex>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;   // int vec
typedef vector<ll> vll;   // int vec
typedef vector<vi> vvi;   // int vec vec
typedef vector<vll> vvll; // int vec
typedef vector<pii> vpi;  // int int pair vec
typedef vector<pll> vpll; // int int pair vec
typedef complex<double> cd;

const double pi = 3.1415926535897932384626433832795;
const int maxn = 205;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ll INFLL = 1000000000000000005LL;
const ld EPS = 1e-9;
int dirx[8] = {-1, 0, 0, 1, -1, -1, 1, 1};
int diry[8] = {0, 1, -1, 0, -1, 1, -1, 1};

#define d(x) cout << #x << " = " << x << endl;
#define ios ios_base::sync_with_stdio(0), cin.tie(0);
#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define forab(i, a, b) for (int i = a; i < (int)b; ++i)
#define foreach(a, b) for (auto &(a) : (b))
#define formap(map) for (const auto &[key, value] : map)
#define all(v) v.begin(), v.end()
#define allar(arr, sz) arr, arr + sz
#define ms(ar, val) memset(ar, val, size)
#define pq(type) priority_queue<type>
#define pqd(type) priority_queue<type, vector<type>, greater<type>>
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

ll rL[maxn], gL[maxn], bL[maxn];
ll dp[maxn][maxn][maxn];

ll sol(int r, int g, int b)
{
    if ((r == -1 && g == -1) || (g == -1 && b == -1) || (r == -1 && b == -1))
        return 0;
    ll &v = dp[r + 1][g + 1][b + 1];
    if (v != -1)
        return v;
    if (r == -1)
        return v = sol(r, g - 1, b - 1) + gL[g] * bL[b];
    if (g == -1)
        return v = sol(r - 1, g, b - 1) + rL[r] * bL[b];
    if(b == -1)
        return v = sol(r - 1, g - 1, b) + rL[r] * gL[g];
    return v = max(sol(r - 1, g - 1, b) + rL[r] * gL[g],
                   max(sol(r, g - 1, b - 1) + gL[g] * bL[b],
                       sol(r - 1, g, b - 1) + rL[r] * bL[b]));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(20);
    int r, g, b;
    cin >> r >> g >> b;
    forn(i, r)
    {
        cin >> rL[i];
    }
    forn(i, g)
    {
        cin >> gL[i];
    }
    forn(i, b)
    {
        cin >> bL[i];
    }
    sort(rL, rL + r);
    sort(gL, gL + g);
    sort(bL, bL + b);
    memset(dp, -1, sizeof(dp));
    cout << sol(r - 1, g - 1, b - 1) << nl;
}